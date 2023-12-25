/* 
Selection Sort Visualization with C - Turtle
Author : Cody A.Auen
(C - Turtle by Jesse  W.Walker)
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

void sel_Sort() {

    //makes screen
    ct::TurtleScreen scr;

    //makes Turtle on screen
    ct::Turtle a(scr);
    ct::Turtle b(scr);
    ct::Turtle c(scr);
    ct::Turtle d(scr);
    ct::Turtle e(scr);
    ct::Turtle f(scr);
    ct::Turtle g(scr);
    ct::Turtle h(scr);
    ct::Turtle ctr(scr);

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

    ct::Polygon counter = {
    {-135, 135},
    {-135, -135}
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
    ctr.fillcolor({ "black" });



    //disables pen
    a.penup();
    b.penup();
    c.penup();
    d.penup();
    e.penup();
    f.penup();
    g.penup();
    h.penup();
    ctr.penup();

    //creates line of turtles
    a.shift(-150, -60);
    b.shift(-110, -50);
    c.shift(-70, 00);
    d.shift(-30, 10);
    e.shift(10, -40);
    f.shift(50, -20);
    g.shift(90, -10);
    h.shift(130, 30);
    ctr.shift(-305, 35);
    ctr.lt(90);

    //changes shape of turtle to custom polygon shapes.
    a.shape(square1);
    b.shape(square2);
    c.shape(square3);
    d.shape(square4);
    e.shape(square5);
    f.shape(square6);
    g.shape(square7);
    h.shape(square8);
    ctr.shape(counter);

    //sets speed to normal (e.g. speed = 6)
    a.speed(ct::TS_NORMAL);
    b.speed(ct::TS_NORMAL);
    c.speed(ct::TS_NORMAL);
    d.speed(ct::TS_NORMAL);
    e.speed(ct::TS_NORMAL);
    f.speed(ct::TS_NORMAL);
    g.speed(ct::TS_NORMAL);
    h.speed(ct::TS_NORMAL);
    ctr.speed(ct::TS_NORMAL);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //scr.delay(200);
    a.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    a.lt(1);
    a.rt(1);
    b.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    b.lt(1);
    b.rt(1);
    b.fillcolor({ "white" });
    c.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    c.fillcolor({ "white" });
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    d.fillcolor({ "white" });
    e.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    e.fillcolor({ "white" });
    f.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    f.fillcolor({ "white" });
    g.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    g.fillcolor({ "white" });
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    a.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    b.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    b.lt(1);
    b.rt(1);
    c.fillcolor({ "blue" });
    ct::detail::sleep(1000); 
    c.lt(1);
    c.rt(1);
    c.fillcolor({ "white" });
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    d.fillcolor({ "white" });
    e.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    e.fillcolor({ "white" });
    f.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    f.fillcolor({ "white" });
    g.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    g.fillcolor({ "white" });
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    b.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    c.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    c.lt(1);
    c.rt(1);
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    c.fillcolor({ "white" });
    d.fillcolor({ "white" });
    e.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    e.lt(1);
    e.rt(1);
    f.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    f.fillcolor({ "white" });
    g.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    g.fillcolor({ "white" });
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    e.shift(-80, 0);
    c.shift(80, 0); 
    e.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    d.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    d.lt(1);
    d.rt(1);
    d.fillcolor({ "white" });
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    c.fillcolor({ "white" });
    f.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    f.lt(1);
    f.rt(1);
    g.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    g.fillcolor({ "white" });
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    f.shift(-80, 0);
    d.shift(80, 0);
    f.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    c.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    c.lt(1);
    c.rt(1);
    d.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    d.lt(1);
    d.rt(1);
    c.fillcolor({ "white" });
    d.fillcolor({ "white" });
    g.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    g.lt(1);
    g.rt(1);
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    g.shift(-80, 0);
    c.shift(80, 0);
    g.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    d.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    d.lt(1);
    d.rt(1);
    d.fillcolor({ "white" });
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.lt(1);
    c.rt(1);
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    c.shift(-40, 0);
    d.shift(40, 0);
    c.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    d.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    d.lt(1);
    d.rt(1);
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.lt(1);
    h.rt(1);
    d.fillcolor({ "white" });
    h.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    h.fillcolor({ "orange" });
    ct::detail::sleep(1000); //delay added for better visulization
    h.lt(1);
    h.rt(1);
    h.fillcolor({ "white" });
    ctr.shift(0, -40);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    scr.bye();
}

// Driver program to test above functions  
int main(){
    sel_Sort();
    return 0;
    }