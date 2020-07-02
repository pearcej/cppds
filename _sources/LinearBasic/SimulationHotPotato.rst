..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Simulation: Hot Potato
~~~~~~~~~~~~~~~~~~~~~~

One of the typical applications for showing a queue in action is to
simulate a real situation that requires data to be managed in a FIFO
manner. To begin, let’s consider the children’s game Hot Potato. In this
game (see :ref:`Figure 2 <fig_quhotpotato>`) children line up in a circle and
pass an item from neighbor to neighbor as fast as they can. At a certain
point in the game, the action is stopped and the child who has the item
(the potato) is removed from the circle. Play continues until only one
child is left.

.. _fig_quhotpotato:

.. figure:: Figures/hotpotato.png
   :align: center

   Figure 2: A Six Person Game of Hot Potato


This game is a modern-day equivalent of the famous Josephus problem.
Based on a legend about the famous first-century historian Flavius
Josephus, the story is told that in the Jewish revolt against Rome,
Josephus and 39 of his comrades held out against the Romans in a cave.
With defeat imminent, they decided that they would rather die than be
slaves to the Romans. They arranged themselves in a circle. One man was
designated as number one, and proceeding clockwise they killed every
seventh man. Josephus, according to the legend, was among other things
an accomplished mathematician. He instantly figured out where he ought
to sit in order to be the last to go. When the time came, instead of
killing himself, he joined the Roman side. You can find many different
versions of this story. Some count every third man and some allow the
last man to escape on a horse. In any case, the idea is the same.

We will implement a general **simulation** of Hot Potato. Our program
will input an array of names and a constant, call it “num,” to be used for
counting. It will return the name of the last person remaining after
repetitive counting by ``num``. What happens at that point is up to you.

To simulate the circle, we will use a queue (see
:ref:`Figure 3 <fig_qupotatoqueue>`). Assume that the child holding the potato will
be at the front of the queue. Upon passing the potato, the simulation
will simply dequeue and then immediately enqueue that child, putting her
at the end of the line. She will then wait until all the others have
been at the front before it will be her turn again. After ``num``
dequeue/enqueue operations, the child at the front will be removed
permanently and another cycle will begin. This process will continue
until only one name remains (the size of the queue is 1).

.. _fig_qupotatoqueue:

.. figure:: Figures/namequeue.png
   :align: center

   Figure 3: A Queue Implementation of Hot Potato

The program is shown in :ref:`ActiveCode 1 <lst_josephussim>`. A call to the
``hotPotato`` function using 7 as the counting constant returns ``Susan``.

.. _lst_josephussim:

.. tabbed:: hp1

  .. tab:: C++

    .. activecode:: hot_potato_cpp
      :caption: Using Queues in C++ to simulate Hot Potato
      :language: cpp

      //This program creates a simulation of hot potato.

      #include <iostream>
      #include <queue>
      #include <string>

      using namespace std;

      string hotPotato(string nameArray[], int num) {
          queue<string> simqueue;
          int namelsLenght = nameArray->length();
          for (int i = 0; i < namelsLenght; i++) {
	      //puts the entire array into a queue.
              simqueue.push(nameArray[i]);
          }

      while (simqueue.size() > 1) { //loop continues until there is one remaining item.
              for (int i = 0; i < num; i++) {
                  simqueue.push(simqueue.front());
                  simqueue.pop();
              }
              simqueue.pop();
          }

          return simqueue.front();
      }

      int main() {
          string s[] = {"Bill", "David", "Susan", "Jane", "Kent", "Brad"};

          cout << hotPotato(s, 7) << endl;

          return 0;
      }


  .. tab:: Python

    .. activecode:: hot_potato_py
       :caption: Hot Potato Simulation
       :optional:

       #This program creates a simulation of hot potato.

       from pythonds.basic.queue import Queue

       def hotPotato(namelist, num):
           simqueue = Queue()
           for name in namelist:
	       #adds all items in the list into a queue.
               simqueue.enqueue(name)

           while simqueue.size() > 1: #continues until there is only one remaining item.
               for i in range(num):
                   simqueue.enqueue(simqueue.dequeue())

               simqueue.dequeue()

           return simqueue.dequeue()

       def main():
           print(hotPotato(["Bill","David","Susan","Jane","Kent","Brad"],7))
       main()

Note that in this example the value of the counting constant is greater
than the number of names in the array. This is not a problem since the
queue acts like a circle and counting continues back at the beginning
until the value is reached. Also, notice that the array is loaded into
the queue such that the first name on the array will be at the front of
the queue. ``Bill`` in this case is the first item in the array and
therefore moves to the front of the queue. A variation of this
implementation, described in the exercises, allows for a random counter.
