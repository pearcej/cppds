..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Programming Exercises
---------------------

#. Using a random number generator, create a list of 500 integers.
   Perform a benchmark analysis using some of the sorting algorithms
   from this chapter. What is the difference in execution speed?

#. Implement the bubble sort using simultaneous assignment.

#. A bubble sort can be modified to “bubble” in both directions. The
   first pass moves “up” the list, and the second pass moves “down.”
   This alternating pattern continues until no more passes are
   necessary. Implement this variation and describe under what
   circumstances it might be appropriate.

#. Implement the selection sort using simultaneous assignment.

#. Perform a benchmark analysis for a shell sort, using different
   increment sets on the same vector.

#. One way to improve the quick sort is to use an insertion sort on
   lists that have a small length (call it the “partition limit”). Why
   does this make sense? Re-implement the quick sort and use it to sort
   a random list of integers. Perform an analysis using different list
   sizes for the partition limit.

#. Implement the median-of-three method for selecting a pivot value as a
   modification to ``quickSort``. Run an experiment to compare the two
   techniques.
