..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Hash Tables
------------



The second major C++ data structure is the hash table. As you
may recall, hash tables differ from arrays in that you can access
items in a hash table by a key rather than a position. Later in this
book you will see that there are many ways to implement a hash table.
The thing that is most important to notice right now is that the get
item and set item operations on a hash table is :math:`O(1)`. Another
important hash table operation is the contains operation. Checking to
see whether a key is in the hash table or not is also :math:`O(1)`.
The efficiency of all hash table operations is summarized in
:ref:`Table 3 <tbl_dictbigo_cpp>`. One important side note on hash table performance
is that the efficiencies we provide in the table below are for average
performance. In some rare cases the contains, get item, and set item
operations can degenerate into :math:`O(n)` performance but we will
get into that in a later chapter when we talk about the different ways
that a hash table could be implemented.

.. _tbl_dictbigo_cpp:

.. table:: **Table 3: Big-O Efficiency of C++ hash table Operations**

    ================== ==================
             operation   Big-O Efficiency
    ================== ==================
                  find               O(1)
                insert               O(1)
                 erase               O(1)
             iteration               O(n)
    ================== ==================



For our last performance experiment we will compare the performance of
the contains operation between arrays and hash tables. In the process we
will confirm that the contains operator for arrays is :math:`O(n)` and
the contains operator for hash tables is :math:`O(1)`. The experiment
we will use to compare the two is simple. We’ll make an array with a range
of numbers in it. Then we will pick numbers at random and check to see
if the numbers are in the array. If our performance tables are correct
the bigger the array the longer it should take to determine if any one
number is contained in the array.

We will repeat the same experiment for a hash table that contains
numbers as the keys. In this experiment we should see that determining
whether or not a number is in the hash table is not only much faster,
but the time it takes to check should remain constant even as the
hash table grows larger.

:ref:`Listing 6 <lst_listvdict_cpp>` implements this comparison. Notice that we are
performing exactly the same operation, ``number in container``. The
difference is that on line 7 ``x`` is array, and on line 9 ``x`` is a
hash table.

.. _lst_listvdict_cpp:

**Listing 6**

.. sourcecode:: cpp
    :linenos:

    #include <iostream>
    #include <ctime>
    #include <list>
    #include <unordered_map>
    using namespace std;

    int main() {

        for( int a = 10000; a < 1000001; a = a + 20000) {
            // List Part
            clock_t begin = clock();
            list<int> x;
            for( int i = 0; i < a; i++){
                x.push_back(i);
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


:ref:`Figure 4 <fig_listvdict_cpp>` summarizes the results of running
:ref:`Listing 6 <lst_listvdict_cpp>`. You can see that the hash table is consistently
faster. For the smallest array size of 10,000 elements a hash table is
89.4 times faster than an array. For the largest array size of 990,000
elements the hash table is 11,603 times faster! You can also see that
the time it takes for the contains operator on the array grows linearly
with the size of the array. This verifies the assertion that the contains
operator on a list is :math:`O(n)`. It can also be seen that the time
for the contains operator on a hash table is constant even as the
hash table size grows. In fact for a hash table size of 10,000 the
contains operation took 0.004 milliseconds and for the hash table size
of 990,000 it also took 0.004 milliseconds.

.. _fig_listvdict_cpp:

.. figure:: Figures/listvdict.png

    Figure 4: Comparing the ``in`` Operator for C++ Arrays and Hash Tables

Since C++ is an evolving language, there are always changes going on
behind the scenes. The latest information on the performance of C++
data structures can be found on the C++ website.

.. admonition:: Self Check

    .. mchoice:: mccppmapperfcpp3
        :answer_a: Popping the first index from an array.
        :answer_b: Popping an element from the end of an array.
        :answer_c: Adding a new element to an array.
        :answer_d: array[10]
        :answer_e: all of the above are O(1)
        :correct: a
        :feedback_a: When you remove the first element of a list, all the other elements of the list must be shifted forward.
        :feedback_b: Removing an element from the end of the list is a constant operation.
        :feedback_c: Adding to the end of an array is a constant operation
        :feedback_d: Indexing a array is a constant operation
        :feedback_e: There is one operation that requires all other list elements to be moved.

        Which of the list operations shown below is not O(1)?

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
