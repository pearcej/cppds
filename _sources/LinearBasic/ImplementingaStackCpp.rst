..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
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

	
       //Tests the push, empty, size, pop, and top methods of the stack library.

       #include <iostream>
       #include <stack>    // Calling Stack from the STL

       using namespace std;

       int main() {
           stack<int> newStack;

           newStack.push(3); //Adds 3 to the stack
           newStack.push(8);
           newStack.push(15);

           cout << "Stack Empty? " << newStack.empty() << endl; //Checks if stack is empty.

           cout << "Stack Size: " << newStack.size() << endl; //returns the number of items in the stack.

           cout << "Top Element of the Stack: " << newStack.top() << endl; //returns the top item of the stack.

           newStack.pop(); //removes the top item of the stack.

           cout << "Top Element of the Stack: " << newStack.top() << endl;

           return 0;
       }

  .. tab:: Python

    .. activecode:: stack_1ac_py
       :caption: Implementing a Stack class using Python lists

       #Tests the push, empty, size, pop, and top methods of the stack library.

       class Stack:
           def __init__(self):
               self.items = []

           def isEmpty(self):
	       #checks if the stack is empty.
               return self.items == []

           def push(self, item):
	       #adds item to the top of the stack.
               self.items.append(item)

           def pop(self):
	       #removes the top item of the stack.
               return self.items.pop()

           def top(self):
	       #returns the top item of the stack.
               return self.items[len(self.items)-1]

           def size(self):
	       #returns the number of items in the stack.
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
      :feedback_b: pay attention to the line that says m.pop();. 
      :feedback_c: Good job. This is correct because the 12 was poped of from the end and the 27 was pushed. 
      :feedback_d: This would mean everyting is removed from the stack, when does that happen?

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
      :feedback_c: Good Job, this is true because the stack can not evenly pop off every item within itself, because there is an odd number of items.
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
