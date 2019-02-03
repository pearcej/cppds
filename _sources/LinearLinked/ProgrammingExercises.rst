..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Programming Exercises
---------------------

#. Implement the ``Queue`` ADT, using a list such that the rear of the
   queue is at the end of the list.

#. Design and implement an experiment to do benchmark comparisons of the
   two queue implementations. What can you learn from such an
   experiment?

#. It is possible to implement a queue using a linked list such that both enqueue and
   dequeue have :math:`O(1)` performance *on average*. In this case it
   means that most of the time enqueue and dequeue will be
   :math:`O(1)` except in one particular circumstance where dequeue
   will be :math:`O(n)`.

#. To implement the ``length`` method, we counted the number of nodes in
   the list. An alternative strategy would be to store the number of
   nodes in the list as an additional piece of data in the head of the
   list. Modify the ``UnorderedList`` class to include this information
   and rewrite the ``length`` method.

#. Implement the ``remove`` method so that it works correctly in the
   case where the item is not in the list.

#. Modify the list classes to allow duplicates. Which methods will be
   impacted by this change?

#. Overload the cout operator in the UnorderedList class. What
   would be a good printed representation for a list?

#. Overload the cout operator so that lists are displayed the
   with square brackets.

#. Implement the remaining operations defined in the UnorderedList ADT
   (append, index, pop, insert).

#. Implement a slice method for the ``UnorderedList`` class. It should
   take two parameters, ``start`` and ``stop``, and return a copy of the
   list starting at the ``start`` position and going up to but not
   including the ``stop`` position.

#. Implement the remaining operations defined in the OrderedList ADT.

#. Consider the relationship between Unordered and Ordered lists. Is it
   possible that inheritance could be used to build a more efficient
   implementation? Implement this inheritance hierarchy.

#. Implement a stack using linked lists.

#. Implement a queue using linked lists.

#. Implement a deque using linked lists.

#. Design and implement an experiment that will compare the performance
   of a C++ vector with a list implemented as a linked list.

#. Design and implement an experiment that will compare the performance
   of the C++ vector based stack and queue with the linked list
   implementation.

#. The linked list implementation given above is called a singly linked
   list because each node has a single pointer to the next node in
   sequence. An alternative implementation is known as a doubly linked
   list. In this implementation, each node has a pointer to the next
   node (commonly called next) as well as a pointer to the preceding
   node (commonly called back). The head pointer also contains two
   pointers, one to the first node in the linked list and one to the
   last. Code this implementation in C++.
