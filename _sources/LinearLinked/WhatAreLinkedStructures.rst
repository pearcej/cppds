..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


What Are Linked Structures?
---------------------------

A linked data structure is a data structure which consists of a
set of data structures called nodes which are linked together and organized
by links created via references or pointers.

Linked data structures include linear linked structures like linked lists
as well as a variety of different types of tree data structures.
In this chapter we will consider linear linked structures, both ordered and unordered.

When thinking about an ordered linked data structure, one example is timesharing
on an operating system. Timesharing is a computer's way of multitasking. Much
like when human's multitask, computers do not actually handle all of its tasks
at the same exact time. If you tried to listen to 3 people talk, read a book,
and sing a song then you would fail like most people. What you may notice when
attempting such a feat is that you pick up on bits and pieces of each separate
task. This is due to your attention switching really fast between tasks.

Observe what happens when you play the following three videos simultaneously:

.. youtube:: wxKA9be_3Gk
    :height: 315
    :width: 560
    :align: left


.. youtube:: 5F6orbqZigI
    :height: 315
    :width: 560
    :align: left


.. youtube:: jil0WCh_UoQ
    :height: 315
    :width: 560
    :align: left


You can hear and see all three videos simultaneously, but only because your
computer switches from one task to another so fast that it appears seamless. Just
like you, your computer gives each task some time to use its resources and cycles
between them really fast makes. Timesharing explains why a computer slows down
when there are a bunch of tabs open on a browser: the more things you have to
switch between, the more time it takes to finish them.
