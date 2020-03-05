..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Priority Queues with Binary Heaps Example
-----------------------------------------

Before we begin with the implementation of **Binary Heaps**, let us review a real life example of one of the things: **Priority Queues**.
Let us consider a priority queue of homework. If we were trying to decide which homework project to complete, it would make sense to organize
the order of doing any specific project based on the deadline of that homework. Let us say you were assigned homeworks in the following order
and you are told the deadlines for those homeworks: 3, 10, 5, 8, 7, 2 days respectively. You can observe the insertion of these homeworks into our priority queue in :ref:`Figure 1 <PQ_insertion>`.

.. _PQ_insertion:

.. figure:: Figures/Homework_PQ.png
   :scale: 30%
   :align: center
   :alt: image

   Figure 1: Homework insertion process into priority queue

Now that we have the priority queue of which homeworks we need to do in the order. Let us start do the homework with 2 day deadline. We would remove it from the root and put the left most leaf in it place and than rearange the heap back to the proper state, as shown in :ref:`Figure 2 <PQ_del>`.

.. _PQ_del:

.. figure:: Figures/PQ_Del.png
   :scale: 30%
   :align: center
   :alt: image

   Figure 1: Homework insertion process into priority queue