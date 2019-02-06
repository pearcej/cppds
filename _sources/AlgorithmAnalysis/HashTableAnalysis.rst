..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Analysis of Hash Tables
-----------------------

The second major C++ data structure to analyze is the **hash table** or hash map. As you
may recall, hash tables differ from vectors in that you access
items in a hash table by a key rather than a position. A hash table (hash map)
is a data structure that maps keys to their associated values using a hash function.
The underlying structure is a mostly empty array, but unlike the array or vector data
structures, the hash table values are not stored contiguously.
The hash function computes an index into the array of "buckets" from which the correct
associated value can be located. Ideally, the hash table values are distributed uniformly
in the underlying array and, again ideally, the hash function will assign
each key to a unique bucket. However, most hash tables are designed to handle
hash collisions when the hash function generates the same bucket index for more than one key.
More about this when we discuss implementations in more depth.

Later in this
book you will see that there are many ways to implement a hash table.
The thing that is most important to note  now is that the get
item and set item operations on a hash table are :math:`O(1)`. Another
important hash table operation is the **contains** operation. Unlike a vector, checking to
see whether a value is in the hash table or not is also :math:`O(1)`.

The efficiency of all hash table operations is summarized in
:ref:`Table 6 <tbl_hashbigo_cpp>`. One important side note on hash table performance
is that the efficiencies we provide in the table below are for average
performance. In some rare cases the contains, get item, and set item
operations can degenerate into :math:`O(n)` performance but we will
get into that in a later chapter when we talk about the different ways
that a hash table could be implemented.

.. _tbl_hashbigo_cpp:

.. table:: **Table 6: Big-O Efficiency of C++ hash table Operations**

    ================== ==================
             operation   Big-O Efficiency
    ================== ==================
                  find               O(1)
                insert               O(1)
                 erase               O(1)
              contains               O(1)
             iteration               O(n)
    ================== ==================

Note that it is not typical to iterate through a hash table because it is
a data structure designed for look-up, not for iteration. The big
advantage of the hash table is the constant speed of the contains
operation.

For our last performance experiment we will compare the performance of
the contains operation between vectors and hash tables. In the process we
will confirm that the contains operator for vectors is :math:`O(n)` and
the contains operator for hash tables is :math:`O(1)`. The experiment
we will use to compare the two is simple. We’ll make an vector with a range
of numbers in it. Then we will pick numbers at random and check to see
if the numbers are in the vector. If our performance tables are correct
the bigger the vector the longer it should take to determine if any one
number is contained in the vector.

We will repeat the same experiment for a hash table that contains
numbers as the keys. In this experiment we should see that determining
whether or not a number is in the hash table is not only much faster,
but the time it takes to check should remain constant even as the
hash table grows larger.

:ref:`Listing 6 <lst_vectvshash_cpp>` implements this comparison. Notice that we are
performing exactly the same operation, ``number in container``. The
difference is that on line 7 ``x`` is vector, and on line 9 ``x`` is a
hash table.

.. _lst_vectvshash_cpp:

**Listing 6**

.. sourcecode:: cpp
    :linenos:

    #include <iostream>
    #include <ctime>
    #include <vector>
    #include <unordered_map>
    using namespace std;

    int main() {

        for( int a = 10000; a < 1000001; a = a + 20000) {
            // vector Part
            clock_t begin = clock();
            vector<int> avector;
            for( int i = 0; i < a; i++){
                avector.push_back(i);
            }
            clock_t end = clock();
            double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

            // Hash Table Part
            clock_t  begin_ht = clock();
            unordered_map<int, int> y;
            for( int j = 0; j < a; j++ ){
                y[j] = NULL;
            }
            clock_t end_ht = clock();
            double elapsed_secs_ht = double(end_ht - begin_ht) / CLOCKS_PER_SEC;

            // Printing final output
            cout << a << "\t" << elapsed_secs << "\t" << elapsed_secs_ht << endl;
        }

        return 0;
    }


.. sourcecode:: python
    :linenos:

    import timeit
    import random

    for i in range(10000,1000001,20000):
        t = timeit.Timer("random.randrange(%d) in x"%i,
                         "from __main__ import random,x")
        x = list(range(i))
        lst_time = t.timeit(number=1000)
        x = {j:None for j in range(i)}
        d_time = t.timeit(number=1000)
        print("%d,%10.3f,%10.3f" % (i, lst_time, d_time))


:ref:`Figure 4 <fig_vectvshash_cpp>` summarizes the results of running
:ref:`Listing 6 <lst_vectvshash_cpp>`. You can see that the hash table is consistently
faster. For the smallest vector size of 10,000 elements a hash table is
89.4 times faster than an vector. For the largest vector size of 990,000
elements the hash table is 11,603 times faster! You can also see that
the time it takes for the contains operator on the vector grows linearly
with the size of the vector. This verifies the assertion that the contains
operator on a vector is :math:`O(n)`. It can also be seen that the time
for the contains operator on a hash table is constant even as the
hash table size grows. In fact for a hash table size of 10,000 the
contains operation took 0.004 milliseconds and for the hash table size
of 990,000 it also took 0.004 milliseconds.

.. _fig_vectvshash_cpp:

.. figure:: Figures/vectvshash.png

    Figure 4: Comparing the ``in`` Operator for C++ vectors and Hash Tables

Since C++ is an evolving language, there are always changes going on
behind the scenes. The latest information on the performance of C++
data structures can be found on the C++ website.

.. admonition:: Self Check

    .. mchoice:: mccppmapperfcpp3
        :answer_a: Popping the first index from an vector.
        :answer_b: Popping an element from the end of an vector.
        :answer_c: Adding a new element to an vector.
        :answer_d: vector[10]
        :answer_e: all of the above are O(1)
        :correct: a
        :feedback_a: When you remove the first element of a vector, all the other elements of the vector must be shifted forward.
        :feedback_b: Removing an element from the end of the vector is a constant operation.
        :feedback_c: Adding to the end of an vector is a constant operation
        :feedback_d: Indexing a vector is a constant operation
        :feedback_e: There is one operation that requires all other vector elements to be moved.

        Which of the vector operations shown below is not O(1)?

    .. mchoice:: mccppmapperfcpp4
        :answer_a: mymap.count('x')
        :answer_b: mymap.erase('x')
        :answer_c: mymap['x'] = 10;
        :answer_d: mymap['x'] = mymap['x'] + 1;
        :answer_e: all of the above are O(1)
        :correct: e
        :feedback_a: count is a constant operation for a hash table because you do not have to iterate but there is a better answer.
        :feedback_b: removing an element from a hash table is a constant operation but there is a better answer.
        :feedback_c: Assignment to a hash table key is constant but there is a better answer.
        :feedback_d: Re-assignment to a hash table key is constant but there is a better answer.
        :feedback_e: The only hash table operations that are not O(1) are those that require iteration.

        Which of the hash table operations shown below is O(1)?

..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Summary
-------

-  Algorithm analysis is an implementation-independent way of measuring
   an algorithm.

-  Big-O notation allows algorithms to be classified by their dominant
   process with respect to the size of the problem.


Self Check
-----------

.. dragndrop:: growth
    :feedback: Compare the functions at different values to see how they compare
    :match_1: n^2|||1st
    :match_2: 2^n|||2nd
    :match_3: nlogn|||3rd
    :match_4: logn|||4th

    Drag the order of growth rates to their rankings from lowest to highest (the highest growth rate should be #1)

.. mchoice:: resources
   :multiple_answers:
   :answer_a: language constraints
   :answer_b: Space
   :answer_c: Time
   :answer_d: Energy
   :correct: b,c
   :feedback_a: No, we do not consider the restraints of a language when thinking about how efficient an algorithm is.
   :feedback_b: Yes, we consider how much space we need to solve a problem.
   :feedback_c: Yes, we consider how much time it takes to solve a problem
   :feedback_d: No, we do not consider how much energy it takes at this point.

   When considering computer resources, what factors do we have in mind?

.. mchoice:: bigO
  :answer_a: the space it takes
  :answer_b: the time it takes
  :answer_c: the number of steps
  :answer_d: the readability of the code
  :correct: c
  :feedback_a: This can be dependent of the programming language
  :feedback_b: This can be dependent on the machine, programming language, and other factors
  :feedback_c: Yes, when quantifying the time it takes to execute an algorithm we base it on the number of steps it takes to solve the problem, not the time it takes
  :feedback_d: No, a very efficient algorithm can be programmed efficiently in C++ without any extra spaces making it unreadable, however the solution would still be efficient.

  When considering the Big O of an algorithm, what do we use to quantify our description of an algorithm.
