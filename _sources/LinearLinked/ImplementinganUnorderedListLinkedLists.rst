..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Implementing an Unordered Linked List
-------------------------------------

A **linked list** is a linear collection of data elements whose order
is not determined by the placement in memory. Instead, each element is stored
in a node which points to the next node.
In the next sections we implement this linked list data structure.
In doing so, we need to be sure that
we can maintain the relative positioning of the items. However, there is
no requirement that we maintain that positioning in contiguous memory.
For example, consider the collection of items shown in
:ref:`Figure 1 <fig_idea>`. It appears that these values have been placed
randomly. If we can maintain some explicit information in each item,
namely the location of the next item (see :ref:`Figure 2 <fig_idea2>`), then the
relative position of each item can be expressed by simply following the
link from one item to the next.

.. _fig_idea:

.. figure:: Figures/idea.png
   :align: center

   Figure 1: Items Not Constrained in Their Physical Placement

.. _fig_idea2:

.. figure:: Figures/idea2.png
   :align: center

   Figure 2: Relative Positions Maintained by Explicit Links.


It is important to note that the location of the first item of the list
must be explicitly specified. Once we know where the first item is, the
first item can tell us where the second is, and so on. The external
reference is often referred to as the **head** of the list. Similarly,
the last item needs to know that there is no next item.

