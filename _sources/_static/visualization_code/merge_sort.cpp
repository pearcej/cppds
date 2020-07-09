#include <utility>
#include <vector>

//#define HEADLESS

#ifdef HEADLESS

#define CTURTLE_HEADLESS
#define CTURTLE_HEADLESS_WIDTH 400
#define CTURTLE_HEADLESS_HEIGHT 400
#define CTURTLE_HEADLESS_NO_HTML

#endif
#include "lib/CTurtle.hpp"

namespace ct = cturtle;
typedef std::pair<ct::Turtle*, int> paired_turtle_t;

//one frame
void move_item(ct::Turtle& turtle, int index, int yoffs = 0){
    turtle.goTo(-180 + (index * (20 + 20)), -140 + yoffs);
}

void move_hidden_item(std::vector<paired_turtle_t>& list, int from, int to){
    
}

void move_markers(ct::Turtle* turtles, int leftIndex, int middleIndex, int rightIndex){
    static constexpr int yoffs = -30;
    move_item(turtles[0], leftIndex, yoffs);
    move_item(turtles[1], middleIndex, yoffs);
    move_item(turtles[2], rightIndex, yoffs);
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

void vis_merge(ct::TurtleScreen& screen, std::vector<paired_turtle_t>& list, int leftIndex, int middleIndex, int rightIndex){
    int leftSize = middleIndex - leftIndex + 1;
    int rightSize = rightIndex - middleIndex;

    paired_turtle_t leftTemp[leftSize], rightTemp[rightSize];
    
    for(int i = 0; i < leftSize; i++)
        leftTemp[i] = list[leftIndex+i];

    for(int i = 0; i < rightSize; i++)
        rightTemp[i] = list[middleIndex + 1 + i];
    
    int i = 0, j = 0, k = leftIndex;
//    i = 0; // Initial index of first subarray 
//    j = 0; // Initial index of second subarray 
//    k = l; // Initial index of merged subarray 

    while (i < leftSize && j < rightSize) {
        if (leftTemp[i].second <= rightTemp[j].second) {
            list[k] = leftTemp[i];
            move_item(*leftTemp[i].first, k);
            i++;
        }
        else {
            list[k] = rightTemp[j];
            move_item(*rightTemp[j].first, k);
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of leftTemp[] */
    while (i < leftSize) {
        list[k] = leftTemp[i];
        move_item(*leftTemp[i].first, k);
        i++;
        k++;
    }

    /* Copy the remaining elements of rightTemp[] */
    while (j < rightSize) {
        list[k] = rightTemp[j];
        move_item(*rightTemp[j].first, k);
        j++;
        k++;
    }
}

void vis_merge_sort(ct::TurtleScreen& screen, ct::Turtle* markers, std::vector<paired_turtle_t>& list, int leftIndex, int rightIndex){
    if (leftIndex < rightIndex) {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        const int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        // Sort left and right halves
        vis_merge_sort(screen, markers, list, leftIndex, middleIndex);
        vis_merge_sort(screen, markers, list, middleIndex + 1, rightIndex);

//        const int skip_frames = (rightIndex - leftIndex) + 1;
        screen.tracer(0, 500);
        
        for(int i = leftIndex; i <= rightIndex; i++){
            ct::Turtle& turtle = *list[i].first;
            if(i == middleIndex)
                turtle.fillcolor({"orange"});
            else
                turtle.fillcolor({i < middleIndex ? "grey25" : "grey75"});
        }
        
        move_markers(markers, leftIndex, middleIndex, rightIndex);

        screen.tracer(1, 500);
        vis_merge(screen, list, leftIndex, middleIndex, rightIndex);

        if(!(leftIndex == 0 && rightIndex == (list.size() - 1)))
            screen.tracer(0, 500);
        else
            screen.tracer(1, 250);
            
        for(int i = leftIndex; i <= rightIndex; i++){
            list[i].first->fillcolor({"black"});
        }
    }
}

int main(int argc, char**argv){
#ifdef HEADLESS
    ct::TurtleScreen screen;
#else
    ct::TurtleScreen screen(400, 400);   
#endif
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

    //pre-assign locations
    for(int i = 0; i < 10; i++){
        turtles[i].speed(ct::TS_FASTEST);
        turtles[i].penup();
        move_item(turtles[i], i);
    }
    
    ct::Turtle marker_turtles[] = {{(screen)}, {screen}, {screen}};
    for(int i = 0; i < 3; i++){
        ct::Turtle& marker_turtle = marker_turtles[i];
        marker_turtle.penup();
        marker_turtle.speed(ct::TS_FASTEST);
        marker_turtle.left(90);
        marker_turtle.shape("arrow");
        marker_turtle.fillcolor({"blue"});
        
        switch(i){
            case 0:
            case 2:
                marker_turtle.fillcolor({"brown"});
                break;
            case 1:
                marker_turtle.fillcolor({"orange"});
                break;
        }
    }
    
    std::vector<paired_turtle_t> turtleList;
    for(int i = 0; i < 10; i++)
        turtleList.push_back({&turtles[i], items[i]});
    
//    screen.tracer(1, 500);
    vis_merge_sort(screen, marker_turtles, turtleList, 0, turtleList.size() - 1);

    screen.tracer(1, 500);

#ifdef HEADLESS
    screen.bye();
#else
    screen.exitonclick();
#endif
    return 0;
}
