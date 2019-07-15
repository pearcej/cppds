..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Analysis of Array and Vector Operators
--------------------------------------

As we know, **vectors** use **contiguous** storage locations
in an underlying (typically larger) array.
Both array and vector elements can be accessed and
traversed with the help of iterators, and they
can also be accessed randomly using indexes.

However, unlike basic arrays, vectors have a **dynamic size** meaning that whenever
a new element is inserted or deleted,
their size changes automatically.
A new element can be inserted into or deleted from any part of a vector,
and automatic reallocation for other existing items in the vector is applied.
Nevertheless, computing time for
insertion and deletion might differ depending on the location of the item,
and how many items need to be
reallocated.
For example, the last item in a vector is typically
removed at a constant time,
because no resizing of
the vector is typically needed for this operation,
while an item is removed or inserted into the beginning or the
middle of a vector at a linear time because all of the remaining
items to the right of that element must be shifted.

Two common operations for both arrays and vectors
are indexing and assigning to an index position
that already exists.
Both of these operations take the same amount of time no matter how
large the array or vector is. When an operation like this is independent of
the size of the array or vector they are :math:`O(1)`.

Although not possible with basic arrays, a common programming technique is growing a vector.
As we have seen, one
way to create a longer vector is to use the ``push_back()`` method.
The ``push_back()`` method is typically :math:`O(1)`, provided
there is adequate capacity in the underlying array.

First we’ll use ``push_back()`` method.
:ref:`Listing 3 <lst_mkvectcpp>` shows the code for
making our vector.

.. _lst_mkvectcpp:

**Listing 3**

::

    #include <iostream>
    #include <vector>
    using namespace std;

    void test1(int num){
        vector <int> vect;
        vect.reserve(num);
        for (int i = 0; i < num; i++){
            vect.push_back(i);
        }
    }

    int main() {
        test1(1000);
    }

To capture the time it takes for each of our functions to execute we
will use C++'s ``ctime`` module. The ``ctime`` module is designed
to allow C++ developers to make cross-platform timing measurements by
running functions in a consistent environment and using timing
mechanisms that are as similar as possible across operating systems.

To use ``ctime`` you create two ``clock`` objects. The first clock object marks
the current start time; the second clock object marks the current time after
the function runs a set number of times (the end time). To get the total runtime,
you subtract the end time from the start time to get the elapsed time.
The following session shows how long it takes to run each
of our test functions 10,000 times within a ``for`` loop.

.. activecode:: vectcpp2
    :language: cpp

    #include <iostream>
    #include <vector>
    using namespace std;

    //Tests the time of the vector "push_back()" operation 

    void test1(int num){
        vector<int> vect;
        for (int i = 0; i < num; i++){
            vect.push_back(i);
        }
    }

    int main(){
        int numruns = 10000;
        clock_t begin_t1 = clock();
        for (int i = 0; i < numruns; i++){
            test1(numruns);
        }
        clock_t end_t1 = clock();
        double elapsed_secs = double(end_t1 - begin_t1) /CLOCKS_PER_SEC;
        cout << fixed << endl;
        cout << "push_back " << elapsed_secs << " milliseconds" << endl;

        return 0;
    }

In the experiment above the statement that we are timing is the function
call to ``test1``. From the experiment, we see the amount of time taken by the push_back operation.

We can improve the runtime a bit further by setting an adequate reserve for the vector
in advance. Doing this will keep us from having to move the entire vector to an
adequately sized space in memory.

.. activecode:: vectcpp3
    :language: cpp

    #include <iostream>
    #include <vector>
    using namespace std;

    //Tests the time of the vector push_back() operation "reserved" versus "unreserved"

    void test1(int num){
        vector<int> vect;
        // no reserve set
        for (int i = 0; i < num; i++){
            vect.push_back(i);
        }
    }

    void test2(int num){
        vector<int> vect2;
        vect2.reserve(num);
        for (int i = 0; i < num; i++){
            vect2.push_back(i);
        }
    }

    int main(){
        int numruns = 10000;
        clock_t begin_t1 = clock();
        for (int i = 0; i < numruns; i++){
            test1(numruns);
        }
        clock_t end_t1 = clock();
        double elapsed_secs1 = double(end_t1 - begin_t1) /CLOCKS_PER_SEC;
        cout << fixed << endl;
        cout << "unreserved push_back " << elapsed_secs1 << " milliseconds" << endl;

        clock_t begin_t2 = clock();
        for (int i = 0; i < numruns; i++){
            test2(numruns);
        }
        clock_t end_t2 = clock();
        double elapsed_secs2 = double(end_t2 - begin_t2) /CLOCKS_PER_SEC;
        cout << fixed << endl;
        cout << "reserved push_back " << elapsed_secs2 << " milliseconds" << endl;


        return 0;
    }


Now that we have seen how performance can be measured concretely you can
look at :ref:`Table 2 <tbl_vectbigocpp>` to see the Big-O efficiency of all the
basic vector operations. When ``pop_back()`` is called, the element
at the end of the vector is removed and it typically takes
:math:`O(1)` but when ``erase()`` is called on the first element in the vector
or anywhere in the middle it is :math:`O(n)`. The reason for this lies
in how C++ chooses to implement vectors. When an item is taken from the
front of the vector, in C++ implementation, all the other elements in
the vector are shifted one position closer to the beginning. This may seem
silly to you now, but if you look at :ref:`Table 2 <tbl_vectbigocpp>` you will see
that this implementation also allows the index operation to be
:math:`O(1)`. This is a tradeoff that the C++ implementers thought
was a good one.


.. _tbl_vectbigocpp:

.. table:: **Table 2: Big-O Efficiency of C++ Vector Operators**

    ===================== ==================
                Operation   Big-O Efficiency
    ===================== ==================
                 index []               O(1)
       index assignment =               O(1)
              push_back()     typically O(1)
               pop_back()               O(1)
                 erase(i)               O(n)
          insert(i, item)               O(n)
     find(srt, stp, item)   O(log n) or O(n)
                reserve()               O(n)
                  begin()               O(1)
                    end()               O(1)
                   size()               O(1)
    ===================== ==================

The `push_back()` operation is :math:`O(1)` unless there is inadequate capacity,
in which case the entire
vector is moved to a larger contiguous underlying array, which
is :math:`O(n)`.

Note that the vector class provides a find command which can determine
whether a given item is in the vector. It is :math:`O(log n)` if
the vector is sorted and is :math:`O(n)` otherwise. We will explain
why this is in Chapter 3.

As a way of demonstrating the difference in performance between push_back
and insert, let’s do
another experiment using the ``ctime`` module. Our goal is to be able
to verify the performance of the ``pop_back()`` operation on a vector of a known
size when the program pops from the end of the vector using ``pop_back()``, and again when the
program pops from the beginning of the vector using ``erase()``. We will also want to
measure this time for vectors of different sizes. What we would expect to
see is that the time required to pop from the end of the vector will stay
constant even as the vector grows in size, while the time to pop from the
beginning of the vector will continue to increase as the vector grows.

:ref:`Listing 4 <lst_popmeascpp>` shows one attempt to measure the difference
between the ``pop_back()`` and ``erase()``.

There are a couple of things to notice about :ref:`Listing 4 <lst_popmeascpp>`.
This approach allows us to time just the single ``pop_back()`` statement
and get the most accurate measure of the time for that single operation.
Because the timer repeats 10,000 times it is also important to point out
that the vector is decreasing in size by 1 each time through the loop.

.. _lst_popmeascpp:

**Listing 4**

.. activecode:: popbackvserase
    :language: cpp

    #include <iostream>
    #include <vector>
    using namespace std;

    //Tests the time of the vector "pop_back()" operation versus the vector "erase" operation
    
    int main(){
        int num = 10000;
        vector<int> vect;
        vector<int> vect2;
        vect.reserve(num);
        vect2.reserve(num);

        for (int i = 0; i < num; i++){
            vect.push_back(i);
        }

        for (int i = 0; i < num; i++){
            vect2.push_back(i);
        }

        clock_t begin = clock();
        for (int i = 0; i < num; i++){
            vect.erase(vect.begin()+0);
        }
        clock_t end = clock();
        double elapsed_secs = double(end - begin) /CLOCKS_PER_SEC;
        cout << fixed << endl;
        cout << "popzero = " << elapsed_secs << endl;

        clock_t begin2 = clock();
        for (int i = 0; i < num; i++){
            vect2.pop_back();
        }
        clock_t end2 = clock();
        double elapsed_secs2 = double(end2 - begin2) /CLOCKS_PER_SEC;
        cout << fixed << endl;
        cout << "popend = " << elapsed_secs2 << endl;

        cout << "\nPopping from the end is " << elapsed_secs/elapsed_secs2 <<" times faster." << endl;

        return 0;
    }

.. dragndrop:: matching_VectorBO
    :feedback: Review operations and thier Big(O)
    :match_1: begin(), end(), size(), index [], index assignment = ,push_back(), pop_back()||| O(1) 
    :match_2: reserve(), erase(i), insert(i, item),find(srt, stp, item)|||O(n)
    :match_3: find(srt, stp, item)|||O(log n)
   
    Drag the operation(s) on the left to their corresponding Big(O)