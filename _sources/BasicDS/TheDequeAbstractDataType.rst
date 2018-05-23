..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Deque Abstract Data Type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The deque abstract data type is defined by the following structure and
operations. A deque is structured, as described above, as an ordered
collection of items where items are added and removed from either end,
either front or rear. The deque operations are given below.

-  ``deque<dataType> dequeName`` creates a new deque that is empty. It returns an empty deque.

-  ``push_front(item)`` adds a new item to the front of the deque. It
   needs the item and returns nothing.

-  ``push_back(item)`` adds a new item to the rear of the deque. It needs
   the item and returns nothing.

-  ``pop_front()`` removes the front item from the deque. It needs no
   parameters. The deque is modified.

-  ``pop_back()`` removes the rear item from the deque. It needs no
   parameters. The deque is modified.

-  ``empty()`` tests to see whether the deque is empty. It needs no
   parameters and returns a boolean value.

-  ``size()`` returns the number of items in the deque. It needs no
   parameters and returns an integer.

As an example, if we assume that ``d`` is a deque that has been created
and is currently empty, then Table {dequeoperations} shows the results
of a sequence of deque operations. Note that the contents in front are
listed on the right. It is very important to keep track of the front and
the rear as you move items in and out of the collection as things can
get a bit confusing.

.. _tbl_dequeoperations:

.. table:: **Table 1: Examples of Deque Operations**

    ============================ ============================ ==================
             **Deque Operation**           **Deque Contents**   **Return Value**
    ============================ ============================ ==================
                   ``d.empty()``                       ``[]``           ``True``
              ``d.push_back(4)``                      ``[4]``
             ``d.push_back(17)``                   ``[17,4]``
            ``d.push_front(93)``                ``[17,4,93]``
            ``d.push_front(65)``             ``[17,4,93,65]``
                    ``d.size()``             ``[17,4,93,65]``              ``4``
                   ``d.empty()``             ``[17,4,93,65]``          ``False``
             ``d.push_back(25)``          ``[25,17,4,93,65]``
                ``d.pop_back()``             ``[17,4,93,65]``
               ``d.pop_front()``                ``[17,4,93]``
    ============================ ============================ ==================
