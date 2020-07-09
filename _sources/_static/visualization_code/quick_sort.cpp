/*
Quick Sort Visualization with C - Turtle
Author : Cody A.Auen
(C - Turtle by Jesse  W.Walker)
*/

#define CTURTLE_HEADLESS
#define CTURTLE_HEADLESS_WIDTH 400
#define CTURTLE_HEADLESS_HEIGHT 400
#define CTURTLE_HEADLESS_NO_HTML
#define _CRT_SECURE_NO_WARNINGS

#include "CTurtle.hpp" //This brings in the CTurtle library for use
#include <iostream> //for input & output
#include <dos.h>

using namespace std;
namespace ct = cturtle;  //This makes it possible to use the CTurtle commands using ct::

void quickSort() {

    //makes screen
    ct::TurtleScreen scr;
    //ct::TurtleScreen scr(400,400);

    //makes Turtle on screen
    ct::Turtle a(scr);
    ct::Turtle b(scr);
    ct::Turtle c(scr);
    ct::Turtle d(scr);
    ct::Turtle e(scr);
    ct::Turtle f(scr);
    ct::Turtle g(scr);
    ct::Turtle h(scr);
    ct::Turtle ptr(scr);

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
    ptr.fillcolor({ "black" });


    //disables pen
    a.penup();
    b.penup();
    c.penup();
    d.penup();
    e.penup();
    f.penup();
    g.penup();
    h.penup();
    ptr.penup();

    //creates line of turtles
    a.shift(-150, -60);
    b.shift(-110, -50);
    c.shift(-70, 00);
    d.shift(-30, 10);
    e.shift(10, -40);
    f.shift(50, -20);
    g.shift(90, -10);
    h.shift(130, 30);
    ptr.shift(-150, -110);
    ptr.left(90);

    //changes shape of turtle to custom polygon shapes.
    a.shape(square1);
    b.shape(square2);
    c.shape(square3);
    d.shape(square4);
    e.shape(square5);
    f.shape(square6);
    g.shape(square7);
    h.shape(square8);
    ptr.shape("arrow");

    //sets speed to normal (e.g. speed = 6)
    a.speed(ct::TS_NORMAL);
    b.speed(ct::TS_NORMAL);
    c.speed(ct::TS_NORMAL);
    d.speed(ct::TS_NORMAL);
    e.speed(ct::TS_NORMAL);
    f.speed(ct::TS_NORMAL);
    g.speed(ct::TS_NORMAL);
    h.speed(ct::TS_NORMAL);
    ptr.speed(ct::TS_NORMAL);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    scr.delay(150);
    a.fillcolor({ "white" });
    //ct::detail::sleep(1000); //delay added for better visulization
    b.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    b.fd(1);
    b.bk(1);
    b.fillcolor({ "blue" });
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.fd(1);
    c.bk(1);
    c.fillcolor({ "blue" });
    d.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    d.fd(1);
    d.bk(1);
    d.fillcolor({ "blue" });
    e.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    e.fd(1);
    e.bk(1);
    e.fillcolor({ "blue" });
    f.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    f.fd(1);
    f.bk(1);
    f.fillcolor({ "blue" });
    g.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    g.fd(1);
    g.bk(1);
    g.fillcolor({ "blue" });
    h.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    h.fillcolor({ "blue" });

    a.fillcolor({ "yellow" });
    b.fillcolor({ "white" });
    c.fillcolor({ "white" });
    d.fillcolor({ "white" });
    e.fillcolor({ "white" });
    f.fillcolor({ "white" });
    g.fillcolor({ "white" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ptr.shift(0, -40);
    b.fillcolor({ "white" });
    //ct::detail::sleep(1000);
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.fd(1);
    c.bk(1);
    c.fillcolor({ "blue" });
    d.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    d.fd(1);
    d.bk(1);
    d.fillcolor({ "blue" });
    e.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    e.fd(1);
    e.bk(1);
    e.fillcolor({ "blue" });
    f.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    f.fd(1);
    f.bk(1);
    f.fillcolor({ "blue" });
    g.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    g.fd(1);
    g.bk(1);
    g.fillcolor({ "blue" });
    h.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    h.fillcolor({ "blue" });
    b.fillcolor({ "yellow" });
    c.fillcolor({ "white" });
    d.fillcolor({ "white" });
    e.fillcolor({ "white" });
    f.fillcolor({ "white" });
    g.fillcolor({ "white" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    ptr.shift(0, -40);
    c.fillcolor({ "white" });
    //ct::detail::sleep(1000);
    d.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    d.fd(1);
    d.bk(1);
    d.fillcolor({ "blue" });
    e.fillcolor({ "red" });
    ct::detail::sleep(1000);
    e.shift(-40, 0);
    d.shift(40, 0);
    f.fillcolor({ "red" });
    ct::detail::sleep(1000);
    f.shift(-40, 0);
    d.shift(40, 0);
    g.fillcolor({ "red" });
    ct::detail::sleep(1000);
    g.shift(-40, 0);
    d.shift(40, 0);
    h.fillcolor({ "blue" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    e.shift(-40, 0);
    f.shift(-40, 0);
    g.shift(-40, 0);
    c.shift(120, 0);
    c.fillcolor({ "white" });
    d.fillcolor({ "yellow" });
    e.fillcolor({ "white" });
    f.fillcolor({ "white" });
    g.fillcolor({ "white" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    e.fillcolor({ "white" });
    //ct::detail::sleep(1000);
    f.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    f.fd(1);
    f.bk(1);
    f.fillcolor({ "blue" });
    g.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    g.fd(1);
    g.bk(1);
    g.fillcolor({ "blue" });
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.fd(1);
    c.bk(1);
    c.fillcolor({ "blue" });
    h.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    h.fillcolor({ "blue" });
    c.fillcolor({ "white" });
    e.fillcolor({ "yellow" });
    f.fillcolor({ "white" });
    g.fillcolor({ "white" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ptr.shift(0, -40);
    f.fillcolor({ "white" });
    //ct::detail::sleep(1000);
    g.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    g.fd(1);
    g.bk(1);
    g.fillcolor({ "blue" });
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.fd(1);
    c.bk(1);
    c.fillcolor({ "blue" });
    h.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    h.fillcolor({ "blue" });
    c.fillcolor({ "white" });
    f.fillcolor({ "yellow" });
    g.fillcolor({ "white" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ptr.shift(0, -40);
    g.fillcolor({ "white" });
    //ct::detail::sleep(1000);
    c.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    c.fd(1);
    c.bk(1);
    c.fillcolor({ "blue" });
    h.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    h.fillcolor({ "blue" });
    c.fillcolor({ "white" });
    g.fillcolor({ "yellow" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ptr.shift(0, -40);
    c.fillcolor({ "white" });
    //ct::detail::sleep(1000);
    h.fillcolor({ "orange" });
    ct::detail::sleep(1000);
    h.fd(1);
    h.bk(1);
    h.fillcolor({ "blue" });
    c.fillcolor({ "yellow" });
    h.fillcolor({ "white" });

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ptr.shift(0, -80);
    h.fillcolor({ "white" });
    //ct::detail::sleep(1000);

    h.fillcolor({ "yellow" });

    //scr.exitonclick();
    scr.bye();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() {
    quickSort();
    return 0;
}