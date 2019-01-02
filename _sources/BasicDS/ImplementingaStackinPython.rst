..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Using a Stack in C++
~~~~~~~~~~~~~~~~~~~~

Now that we have clearly defined the stack as an abstract data type we
will turn our attention to using a stack with the help of the Standard Template Library (STL) in C++. Recall
that when we give an abstract data type a physical implementation we
refer to the implementation as a data structure.

As we described in Chapter 1, in C++, as in any object-oriented
programming language, the implementation of choice for an abstract data
type such as a stack is the creation of a new class. The stack
operations are implemented as methods. However, the STL already has a well
written implementation of the Stack class.

The following stack implementation (:ref:`ActiveCode 1 <lst_stackcode1>`) assumes that
the end of the array will hold the top element of the stack. As the stack
grows (as ``push`` operations occur), new items will be added on the end
of the array. ``pop`` operations will manipulate that same end.

.. _lst_stackcode1:

.. tabbed:: sc1

  .. tab:: C++

    .. activecode:: stack_1ac_cpp
       :caption: Using the Stack methods from the STL in C++
       :language: cpp

       #include <iostream>
       #include <stack>    // Calling Stack from the STL

       using namespace std;

       int main() {
           stack<int> newStack;

           newStack.push(3);
           newStack.push(8);
           newStack.push(15);

           cout << "Stack Empty? " << newStack.empty() << endl;

           cout << "Stack Size: " << newStack.size() << endl;

           cout << "Top Element of the Stack: " << newStack.top() << endl;

           newStack.pop();

           cout << "Top Element of the Stack: " << newStack.top() << endl;

           return 0;
       }

  .. tab:: Python

    .. activecode:: stack_1ac_py
       :caption: Implementing a Stack class using Python lists

       class Stack:
           def __init__(self):
               self.items = []

           def isEmpty(self):
               return self.items == []

           def push(self, item):
               self.items.append(item)

           def pop(self):
               return self.items.pop()

           def top(self):
               return self.items[len(self.items)-1]

           def size(self):
               return len(self.items)

       def main():
           newStack = Stack()
           newStack.push(4)
           newStack.push(8)
           newStack.push(15)

           print("Stack Empty? ", newStack.isEmpty())

           print("Stack Size: ", newStack.size())

           print("Top Element of the Stack: ", newStack.top())

           newStack.pop();

           print("Top Element of the Stack: ", newStack.top())
       main()

.. admonition:: Self Check

   .. mchoice:: stack_1
      :answer_a: 5
      :answer_b: 12
      :answer_c: 27
      :answer_d: The stack is empty
      :correct: c
      :feedback_a: Remember that a stack is built from the bottom up.
      :feedback_b: Remember that a stack is built from the bottom up.
      :feedback_c: Good job.
      :feedback_d: Remember that a stack is built from the bottom up.

      Given the following sequence of stack operations, what is the top item on the stack when the sequence is complete?

      .. code-block:: cpp

       stack<int> m;
       m.push(5);
       m.push(12);
       m.pop();
       m.push(27);
       cout << m.top();

   .. mchoice:: stack_2
      :answer_a: 37
      :answer_b: the stack is empty
      :answer_c: an error will occur
      :answer_d: 4
      :correct: c
      :feedback_a: You may want to check out the docs for
      :feedback_b: There is an odd number of things on the stack but each time through the loop 2 things are popped.
      :feedback_c: Good Job.
      :feedback_d: You may want to check out the docs for isEmpty

      Given the following sequence of stack operations, what is the top item on the stack when the sequence is complete?

      .. code-block:: cpp

        stack<int> m;
        m.push(37);
        m.push(56);
        m.push(4);
        while (!m.empty()){
            m.pop();
            m.pop();
        }

.. video:: stack1_video
    :controls:
    :thumb: ../_static/activecodethumb.png

    http://media.interactivepython.org/pythondsVideos/Stack1.mov
    http://media.interactivepython.org/pythondsVideos/Stack1.webm
