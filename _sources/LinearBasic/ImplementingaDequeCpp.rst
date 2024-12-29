..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Using a Deque in C++
~~~~~~~~~~~~~~~~~~~~

As we have done in previous sections, we will use the Standard Template Library (STL)
of C++ to use a Deque. Again, the Deque library from STL
will provide a very nice set of methods upon which to build the details
of the deque. Our code (:ref:`Listing 1 <lst_dequecode>`) will assume that
the front of the deque is at position 0 in the array.

.. _lst_dequecode:

.. tabbed:: deque_use

  .. tab:: C++

    .. activecode:: dequecode_cpp
      :caption: Using Deque in C++
      :language: cpp

      //Example code of a deque.

      #include <iostream>
      #include <deque>
      #include <string>

      using namespace std;

      int main() {
          deque<string> d;
          cout << "Deque Empty? " << d.empty() << endl;
          d.push_back("Zebra");
          cout << "Deque Empty? " << d.empty() << endl;

          d.push_front("Turtle"); //pushes to the front of the deque.
          d.push_front("Panda");
          d.push_back("Catfish"); //pushes to the back of the deque.
          d.push_back("Giraffe");

          cout << "Deque Size: " << d.size() << endl;
          cout << "Item at the front: " << d.front() << endl;
          cout << "Item at the back: " << d.back() << endl;

          cout << endl << "Items in the Deque: " << endl;
          int dsize = d.size();
          for(int i = 0; i < dsize; i++){
	      //prints each item in the deque.
              cout << d.at(i) << " ";
          }

          cout << endl;

          d.pop_back();
          d.pop_front();

          cout << endl << "Item at the front: " << d.front() << endl;
          cout << "Itm at the back: " << d.back() << endl;
          cout << "Deque Size: " << d.size() << endl;

          cout << endl << "Items in the Deque: " << endl;
          int dsize2 = d.size();
          for(int i = 0; i < dsize2; i++){
	      //prints each item in the deque.
              cout << d.at(i) << " ";

          return 0;
          }
      }

  .. tab:: Python

    .. activecode:: dequecode_py
       :caption: Using Deque in Python
       :optional:

       #Example code of a deque.

       class Deque:
           def __init__(self):
               self.items = []

           def empty(self):
               return self.items == []

           def push_back(self, item):
               self.items.append(item)

           def push_front(self, item):
               self.items.insert(0,item)

           def pop_back(self):
               self.items.pop()

           def pop_front(self):
               self.items.pop(0)

           def back(self):
               return self.items[-1]

           def front(self):
               return self.items[0]

           def size(self):
               return len(self.items)

           def at(self, index):
               return self.items[index]

       def main():
           d = Deque()

           print("Deque Empty? ", d.empty())
           d.push_back("Zebra")
           print("Deque Empty? ", d.empty())

           d.push_front("Turtle") #pushes to the front of the deque.
           d.push_front("Panda")
           d.push_back("Catfish") #pushes to the back of the deque.
           d.push_back("Giraffe")

           print("Deque Size: ", d.size())
           print("Item at the front: ", d.front())
           print("Item at the back: ", d.back())

           print("\n")
           print("Items in the Deque: ")
           for i in range(d.size()):
	       #prints each item in the deque.
               print(d.at(i), end=" ")
           print("\n")

           d.pop_back()
           d.pop_front()

           print("Item at the front: ", d.front())
           print("Item at the back: ", d.back())
           print("Deque Size: ", d.size())

           print("\n")
           print("Items in the Deque: ")
           for i in range(d.size()):
	       #prints each item in the deque.
               print(d.at(i), end=" ")
           print("\n")
       main()

You can see many similarities to C++ code already used for
stacks and queues. In the STL, the deque gives O(1) performance for
adding and removing items from both the front and back of the queue. In the
Python implementation,
adding and removing items from the back is O(1) whereas
adding and removing from the front is O(n). This is to be expected given
the common operations that appear for adding and removing items to lists. Again,
the important thing is to be certain that we know where the front and
rear are assigned in the implementation.
