 /* 
    Bubble Sort Visualization with C-Turtle
    Author: Cody A. Auen
	(C-Turtle by Jesse  W.  Walker)

 */

#define CTURTLE_HEADLESS
#define CTURTLE_HEADLESS_WIDTH 400
#define CTURTLE_HEADLESS_HEIGHT 400
#define CTURTLE_HEADLESS_NO_HTML

#include "CTurtle.hpp"   //This brings in the CTurtle library for use
#include <iostream> //for input & output
#include <dos.h>

namespace ct = cturtle;  //This makes it possible to use the CTurtle commands using ct::
using namespace std;

void bubble_Sort() {

    //makes screen
    ct::TurtleScreen scr;
    scr.delay(200);

    //makes Turtle on screen
    ct::Turtle a(scr);   
    ct::Turtle b(scr);   
    ct::Turtle c(scr);  
    ct::Turtle d(scr);   
    ct::Turtle e(scr);   
    ct::Turtle f(scr); 
    ct::Turtle g(scr);   
    ct::Turtle h(scr);   

    //creates custom polygons to use for turtle shape
    ct::Polygon square1 = {
    {-40, -15},   //First point
    {-40, 15}, //Second point
    {40, 15},  //and so on.
    {40, -15}
    };

    ct::Polygon square2 = {
    {-50, -15},   //First point
    {-50, 15}, //Second point
    {50, 15},  //and so on.
    {50, -15}
    };

    ct::Polygon square3 = {
    {-100, -15},   //First point
    {-100, 15}, //Second point
    {100, 15},  //and so on.
    {100, -15}
    };

    ct::Polygon square4 = {
    {-110, -15},   //First point
    {-110, 15}, //Second point
    {110, 15},  //and so on.
    {110, -15}
    };

    ct::Polygon square5 = {
    {-60, -15},   //First point
    {-60, 15}, //Second point
    {60, 15},  //and so on.
    {60, -15}
    };

    ct::Polygon square6 = {
    {-80, -15},   //First point
    {-80, 15}, //Second point
    {80, 15},  //and so on.
    {80, -15}
    };

    ct::Polygon square7 = {
    {-90, -15},   //First point
    {-90, 15}, //Second point
    {90, 15},  //and so on.
    {90, -15}
    };

    ct::Polygon square8 = {
    {-130, -15},   //First point
    {-130, 15}, //Second point
    {130, 15},  //and so on.
    {130, -15}
    };

    //presets all colors to white
    a.fillcolor({ "white" });
    b.fillcolor({ "white" });
    c.fillcolor({ "white" });
    d.fillcolor({ "white" });
    e.fillcolor({ "white" });
    f.fillcolor({ "white" });
    g.fillcolor({ "white" });
    h.fillcolor({ "white" });

    //disables pen
    a.penup();
    b.penup();
    c.penup();
    d.penup();
    e.penup();
    f.penup();
    g.penup();
    h.penup();

    //creates line of turtles
    a.shift(-150, -60);
    b.shift(-110, -50);
    c.shift(-70, 00);
    d.shift(-30, 10);
    e.shift(10, -40);
    f.shift(50, -20);
    g.shift(90, -10);
    h.shift(130, 30);

    //changes shape of turtle to custom polygon shapes.
    a.shape(square1);
    b.shape(square2);
    c.shape(square3);
    d.shape(square4);
    e.shape(square5);
    f.shape(square6);
    g.shape(square7);
    h.shape(square8);

    //sets speed to normal (e.g. speed = 6)
    a.speed(ct::TS_NORMAL);
    b.speed(ct::TS_NORMAL);
    c.speed(ct::TS_NORMAL);
    d.speed(ct::TS_NORMAL);
    e.speed(ct::TS_NORMAL);
    f.speed(ct::TS_NORMAL);
    g.speed(ct::TS_NORMAL);
    h.speed(ct::TS_NORMAL);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //begins first pass through
    a.fillcolor({ "blue" });
    ct::detail::sleep(1000); //delay added for better visulization
    a.lt(1);
    a.rt(1);
    b.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    b.lt(1);
    b.rt(1);
    a.fillcolor({ "white" }); 
    c.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    b.fillcolor({ "white" });
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    c.fillcolor({ "white" });
    e.fillcolor({ "orange" }); //detecs shape out of place
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    e.shift(-80, 0);
    d.shift(40, 0);
    c.shift(40, 0);
    d.fillcolor({ "white" });
    e.fillcolor({ "white" });

    //begins second pass through
    a.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    a.lt(1);
    a.rt(1);
    b.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    b.lt(1);
    b.rt(1);
    a.fillcolor({ "white" });
    e.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    b.fillcolor({ "white" });
    c.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    e.fillcolor({ "white" });
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    c.fillcolor({ "white" });
    f.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    f.shift(-80, 0);
    d.shift(40, 0);
    c.shift(40,0);
    d.fillcolor({ "white" });
    f.fillcolor({ "white" });

    //begins third pass through
    a.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    a.lt(1);
    a.rt(1);
    b.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    b.lt(1);
    b.rt(1);
    a.fillcolor({ "white" });
    e.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    b.fillcolor({ "white" });
    f.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    e.fillcolor({ "white" });
    c.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    f.fillcolor({ "white" });
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    c.fillcolor({ "white" });
    g.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    g.shift(-80, 0);
    d.shift(40, 0);
    c.shift(40, 0);
    d.fillcolor({ "white" });
    g.fillcolor({ "white" });

    //begins final pass through
    a.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    a.lt(1);
    a.rt(1);
    b.fillcolor({ "blue" });
    ct::detail::sleep(500);
    b.lt(1);
    b.rt(1);
    a.fillcolor({ "white" });
    e.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    b.fillcolor({ "white" });
    f.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    e.fillcolor({ "white" });
    g.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    f.fillcolor({ "white" });
    c.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    g.fillcolor({ "white" });
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    c.fillcolor({ "white" });
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    d.fillcolor({ "white" });
    h.fillcolor({ "white" });

    scr.bye();  //exists graphics screen

}


int main() {
    bubble_Sort();
    return 0;
}
