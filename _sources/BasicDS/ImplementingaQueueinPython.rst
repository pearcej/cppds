..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Using a Queue in C++
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Now that we have clearly defined the queue as an abstract data type, similarly to the how we've previously used the Stack, we
will turn our attention to using a queue with the help of the Standard Template Library (STL) in C++. Recall
that when we give an abstract data type a physical implementation we
refer to the implementation as a data structure.

As we described in Chapter 1, in C++, as in any object-oriented
programming language, the implementation of choice for an abstract data
type such as a queue is the creation of a new class. The queue
operations are implemented as methods. However, the STL already has a well
written implementation of the Queue class.

The following queue implementation (:ref:`ActiveCode 1 <lst_queuecode1>`) assumes that
the end of the list will hold the rear element of the queue. As the queue
grows (as ``push`` operations occur), new items will be added on the end
of the list. ``pop`` operations will manipulate the opposite side, the front end.

.. _lst_queuecode1:

.. tabbed:: sc1

  .. tab:: C++

    .. activecode:: queue_1ac_cpp
      :caption: Using the Queue methods from the STL in C++
      :language: cpp

      #include <iostream>
      #include <queue> // Calling Queue from the STL

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

        	cout << "Top Element of the Queue " << newQueue.front() << endl;

        	return 0;
      }

  .. tab:: Python

    .. activecode:: queue_1ac_py
       :caption: Implementing a Queue class using Python lists

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

       q=Queue()

       q.push(4)
       q.push('dog')
       q.push(True)


       print("Queue Empty? ", q.isEmpty())

       print("Queue Size: ", q.size())

       print("Front Element of the Queue: ", q.front())

       q.pop();

       print("Front Element of the Queue: ", q.front())


.. admonition:: Self Check

  .. mchoice:: queue_1
     :correct: b
     :answer_a: 10, 20
     :answer_b: 20, 30
     :answer_c: 10, 30
     :answer_d: 10, 20, 30
     :feedback_a: Remember the first thing added to the queue is the first thing removed.  FIFO
     :feedback_b: Yes, first in first out means that 10 is gone
     :feedback_c: Queues, and Stacks are both data structures where you can only access the first and the last thing.
     :feedback_d: Ooops, maybe you missed the pop call at the end?

     Suppose you have the following series of queue operations.

     ::

         queue<int> intQueue;
         q.push(10);
         q.push(20);
         q.push(30);
         q.pop();
         q = Queue()
         q.push('hello')
         q.push('dog')
         q.push(3)
         q.pop()

     What items are left on the queue?
