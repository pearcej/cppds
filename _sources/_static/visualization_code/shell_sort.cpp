#include <utility>
#include <vector>

#define CTURTLE_HEADLESS
#define CTURTLE_HEADLESS_WIDTH 400
#define CTURTLE_HEADLESS_HEIGHT 400
#include "lib/CTurtle.hpp"

namespace ct = cturtle;
typedef std::pair<ct::Turtle*, int> paired_turtle_t;

void move_item(ct::Turtle& turtle, int index, int yoffs = 0){
    turtle.goTo(-180 + (index * (20 + 20)), -140 + yoffs);
}

void move_markers(ct::Turtle* turtles, int index, int gap){
    turtles[0].goTo(-180 + (index * (20 + 20)), -150);
    turtles[1].goTo(-180 + (index * (20 + 20)) - (gap * 40), -150);
}

void move_gappers(ct::Turtle* turtle, int a, int b){
    turtle[0].goTo(-180 + (a * (20 + 20) - 20), -150);
    turtle[1].goTo(-180 + (b * (20 + 20) - 20), -150);
}

void vis_shell_sort(ct::TurtleScreen& screen, ct::Turtle* markers, ct::Turtle* gappers, std::vector<paired_turtle_t>& list){
    for(int gap = list.size()/2; gap > 0; gap /= 2){;
        for(int i = gap; i < list.size(); i++){
            paired_turtle_t temp = list[i];
            screen.tracer(6, 500);
            temp.first->hideturtle();

            int j = i;
            for (j; j >= gap && list[j - gap].second > temp.second; j -= gap){
                move_gappers(gappers, j-gap, j+1);
                move_markers(markers, j, gap);
                move_item(*list[j-gap].first, j);
                list[j] = list[j - gap];
                screen.tracer(5, 500);
            }

            screen.tracer(2, 500);
            move_item(*temp.first, j);
            temp.first->showturtle();
            list[j] = temp;
        }
    }
}

ct::Polygon create_rectangle(int height, int halfWidth = 10){
    return ct::Polygon({
        {-halfWidth, 0},
        {halfWidth, 0},
        {halfWidth, -height},
        {-halfWidth, -height}
    });
}

void assign_shapes(int* items, ct::Turtle* turtles, int total){
    for(int i = 0; i < total; i++){
        const int item = items[i];
        ct::Turtle& turtle = turtles[i];
        turtle.left(90);
        turtle.shape(create_rectangle(item*30));
    }
}

int main(int argc, char**argv){
    ct::TurtleScreen screen;
    screen.tracer(10000, 0);

    int items[] = {5, 7, 2, 4, 6, 10, 8, 1, 9, 3};

    ct::Turtle turtles[] = {
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
            ct::Turtle(screen),
    };

    assign_shapes(items, turtles, 10);

    //pre-assign locations
    for(int i = 0; i < 10; i++){
        turtles[i].speed(ct::TS_FASTEST);
        turtles[i].penup();
        move_item(turtles[i], i);
    }

    ct::Turtle gap_turtles[] = {{screen}, {screen}};
    for(int i = 0; i < 2; i++){
        ct::Turtle& gap_turtle = gap_turtles[i];
        gap_turtle.penup();
        gap_turtle.speed(ct::TS_FASTEST);
        gap_turtle.left(90);
        gap_turtle.shape(create_rectangle(325, 1));
        gap_turtle.fillcolor({"brown"});
    }

    ct::Turtle marker_turtles[] = {{(screen)}, {screen}};
    for(int i = 0; i < 2; i++){
        ct::Turtle& marker_turtle = marker_turtles[i];
        marker_turtle.penup();
        marker_turtle.speed(ct::TS_FASTEST);
        marker_turtle.left(90);
        marker_turtle.shape("arrow");
        marker_turtle.fillcolor({"blue"});
    }

    //Assign pairs of turtles and their respective digits.
    std::vector<paired_turtle_t> sort_list;
    for(int i = 0; i < 10; i++){
        sort_list.push_back({&turtles[i], items[i]});
    }

    screen.update(true, false);
    vis_shell_sort(screen, marker_turtles, gap_turtles, sort_list);

    screen.bye();
    return 0;
}
