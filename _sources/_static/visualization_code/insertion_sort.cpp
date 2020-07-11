#include <utility>
#include <vector>

//#define CTURTLE_HEADLESS
//#define CTURTLE_HEADLESS_WIDTH 400
//#define CTURTLE_HEADLESS_HEIGHT 400
//#define CTURTLE_HEADLESS_NO_HTML
#include "lib/CTurtle.hpp"

namespace ct = cturtle;
typedef std::pair<ct::Turtle*, int> paired_turtle_t;

void move_item(ct::Turtle& turtle, int index, int yoffs = 0){
    turtle.goTo(-180 + (index * (20 + 20)), -140 + yoffs);
}

void vis_insertion_sort(ct::TurtleScreen& screen, std::vector<paired_turtle_t>& list){
    int i, j;
    paired_turtle_t key;

    for(i = 1; i < list.size(); i++){
        key = list[i];

        key.first->fillcolor({"orange"});

        for(j = i - 1; j >= 0; j--){
            if(list[j].second < key.second)
                break;

            ct::Turtle& itemTurtle = *list[j].first;

            itemTurtle.fillcolor({"blue"});
            move_item(itemTurtle, j + 1);
            itemTurtle.fillcolor({"black"});

            list[j + 1] = list[j];
        }

        move_item(*key.first, j + 1);
        key.first->fillcolor({"black"});
        list[j + 1] = key;
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
    screen.tracer(0, 0);

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

    //pre-assign locations and initial state
    for(int i = 0; i < 10; i++){
        turtles[i].speed(ct::TS_FASTEST);
        turtles[i].penup();
        move_item(turtles[i], i);
    }

    //Assign pairs of turtles and their respective digits.
    std::vector<paired_turtle_t> sort_list;
    for(int i = 0; i < 10; i++){
        sort_list.push_back({&turtles[i], items[i]});
    }

    screen.update(true, false);
    screen.tracer(1, 500);
    vis_insertion_sort(screen, sort_list);

    screen.bye();
    return 0;
}
