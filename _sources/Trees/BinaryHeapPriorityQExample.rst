..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Priority Queues with Binary Heaps Example
-----------------------------------------

As mentioned before we can use **binary heaps** in order to design a **priority queue**, according to our preference, using a **min or max heap** would allow us to construct a tree in such a way that the children are always larger or smaller than the parent, respectively. In the example in this section we will be using min **heap** structure. That way the smallest element will always be at the root, that is the goal of using a **heap** for a **priority queue**, since this will allow for swift removal of the element with utmost priority. When inserting new elements into the **heap** it is important to maintain the priority structure, therefore every time we insert a new element, not only do we insert it in such a way to fill out the tree from left to right, but we also make sure that every parent node is smaller then the child node that we inserted. This way if the inserted node is the smallest node in the tree it will bubble up to the root and push everything else lower into the **heap**. Deletion of the items is also important, since we know that the element with utmost priority is always at the root we can simply remove the root and replace it with the righmost leaf. However now our priority structure is broken, we can fix this by swaping it with the lesser of its children, then the structure will be correct agian. This structure allows for effective maintenance of the priority of the items and greatly improves the efficiency of our **priority queue**.

Before we begin with the implementation of **Binary Heaps**, let us review a real life example of one of the things: **Priority Queues**.
Let us consider a **priority queue** of homework. If we were trying to decide which homework project to complete, it would make sense to organize
the order of doing any specific project based on the deadline of that homework. Let us say you were assigned homeworks in the following order
and you are told the deadlines for those homeworks: 3, 10, 5, 8, 7, 2 days respectively. You can observe the insertion of these homeworks into our **priority queue** in :ref:`Figure 1 <PQ_insertion>`.

.. _PQ_insertion:

.. figure:: Figures/Homework_PQ.png
   :scale: 25%
   :align: center
   :alt: image

   Figure 1: Homework insertion process into priority queue

Now that we have the priority queue of which homeworks we need to prioritize in order. Let us do the homework with 2 day deadline. We would remove it from the root and put the left most leaf in it place and than rearange the heap back to the proper state, as shown in :ref:`Figure 2 <PQ_del>`.

.. _PQ_del:

.. figure:: Figures/PQ_Del.png
   :scale: 30%
   :align: center
   :alt: image

   Figure 1: Homework insertion process into priority queue
   
As we continue to complete the homework with the closest deadline we will continue to remove the homeworks in the demostrated fashion until we are done.