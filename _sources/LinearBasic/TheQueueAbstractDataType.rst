..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Queue Abstract Data Type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The **queue** abstract data type is defined by the following structure and
operations. A queue is structured, as described above, as an ordered
collection of items which are added at one end, called the “rear,” and
removed from the other end, called the “front.” Queues maintain a
**first-in-first-out (FIFO)**
ordering property. The standard queue operations are given below.

-  ``queue<dataType> queueName`` creates a new queue that is empty. It returns an empty queue.

-  ``push(item)`` adds a new item to the rear of the queue. It needs
   the item and returns nothing.

-  ``pop()`` removes the front item from the queue. It needs no
   parameters. The queue is modified.

-  ``empty()`` tests to see whether the queue is empty. It needs no
   parameters and returns a Boolean value.

-  ``size()`` returns the number of items in the queue. It needs no
   parameters and returns an integer.

-  ``front()`` returns the first item in the queue without removing the item.

-  ``back()`` returns the last item in the queue without removing the item.

As an example, if we assume that ``q`` is a queue that has been created
and is currently empty, then :ref:`Table 1 <tbl_queueoperations>` shows the
results of a sequence of queue operations. The queue contents are shown
such that the front is on the right. 4 was the first item pushed so it
is the first item returned by dequeue.

.. _tbl_queueoperations:

.. table:: **Table 1: Example Queue Operations**

    ============================ ======================== ==================
             **Queue Operation**       **Queue Contents**   **Return Value**
    ============================ ======================== ==================
                   ``q.empty()``                   ``[]``           ``true``
                   ``q.push(4)``                  ``[4]``
                  ``q.push(12)``               ``[12,4]``
                   ``q.push(3)``             ``[3,12,4]``
                    ``q.size()``             ``[3,12,4]``              ``3``
                   ``q.empty()``             ``[3,12,4]``          ``false``
                  ``q.push(97)``          ``[97,3,12,4]``
                     ``q.pop()``            ``[97,3,12]``
                     ``q.pop()``               ``[97,3]``
                    ``q.size()``               ``[97,3]``              ``2``
    ============================ ======================== ==================
