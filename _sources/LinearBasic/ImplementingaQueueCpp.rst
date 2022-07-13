..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Using a Queue in C++
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Now we will turn our attention to using the queue data structure
with the help of the Standard Template Library (STL) in C++.

As we described in Chapter 1, in C++, as in any object-oriented
programming language,
the implementation of choice for an abstract data
type such as a queue is a class in which the queue
operations are implemented as methods.
Fortunately, the STL already has a well
written implementation of the queue class.

In following queue implementation (:ref:`ActiveCode 1 <lst_queuecode1>`)
as ``push`` operations occur, new items are always added on the **rear** end
of the queue and ``pop`` operations will
manipulate the opposite side, the **front** end.

.. _lst_queuecode1:

.. tabbed:: sc10

  .. tab:: C++

    .. activecode:: queue1accpp
      :caption: Using the queue methods from the STL in C++
      :language: cpp

      #include <iostream>
      #include <queue> // Using an STL queue

      using namespace std;

      int main() {
        	queue<int> newQueue;

        	newQueue.push(3);
        	newQueue.push(8);
        	newQueue.push(15);

        	cout << "Queue Empty? " << newQueue.empty() << endl;

        	cout << "Queue Size: " << newQueue.size() << endl;

        	cout << "Top Element of the Queue: " << newQueue.front() << endl;

        	newQueue.pop();

        	cout << "Top Element of the Queue: " << newQueue.front() << endl;

        	return 0;
      }

  .. tab:: Python

    .. activecode:: queue1acpy
       :caption: Implementing a Queue class using Python lists
       :optional:

       class Queue:
           def __init__(self):
               self.items = []

           def isEmpty(self):
               return self.items == []

           def push(self, item):
               self.items.insert(0,item)

           def pop(self):
               return self.items.pop()

           def front(self):
               return self.items[len(self.items)-1];

           def size(self):
               return len(self.items)

       def main():
           q=Queue()

           q.push(3)
           q.push(8)
           q.push(15)

           print("Queue Empty? ", q.isEmpty())

           print("Queue Size: ", q.size())

           print("Front Element of the Queue: ", q.front())

           q.pop();

           print("Front Element of the Queue: ", q.front())
       main()


.. admonition:: Self Check

  .. mchoice:: queue_1
     :correct: b
     :answer_a: 10, 20
     :answer_b: 20, 30
     :answer_c: 10, 30
     :answer_d: 10, 20, 30
     :feedback_a: Remember the first item added to the queue is the first item removed. Remember FIFO.
     :feedback_b: Yes, first in first out means that the 10 is now gone.
     :feedback_c: Queues and stacks are both data structures where you can only access the first or the last items.
     :feedback_d: Oops, maybe you missed the pop call at the end?

     Suppose you have the following series of queue operations.

     ::

         queue<int> q;
         q.push(10);
         q.push(20);
         q.push(30);
         q.pop();

     What items are left on the queue?
