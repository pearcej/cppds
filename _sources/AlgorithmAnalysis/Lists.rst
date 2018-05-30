..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Vectors
-------



The designers of C++ had many choices to make when they implemented
the vector data structure. Each of these choices could have an impact on
how fast array operations perform. To help them make the right choices
they looked at the ways that people would most commonly use the array
data structure and they optimized their implementation of a vector so that
the most common operations were very fast. Of course they also tried to
make the less common operations fast, but when a tradeoff had to be made
the performance of a less common operation was often sacrificed in favor
of the more common operation.

Two common operations are indexing and assigning to an index position.
Both of these operations take the same amount of time no matter how
large the vector becomes. When an operation like this is independent of
the size of the vector they are :math:`O(1)`.

Another very common programming task is to grow a vector. There is one
way to create a longer  vector.  You can use the push_back() method. The push_back() method is :math:`O(1)`.

Let's look at two different ways we might generate an vector of ``n``
numbers starting with 0.

First we’ll try to the use push_back() method.  :ref:`Listing 3 <lst_mklistcpp>` shows the code for
making our vector.

.. _lst_mklistcpp:

**Listing 3**

::

    #include <iostream>
    #include <vector>
    using namespace std;

    int test1(){
        vector <int> vect;
        for (int i = 0; i < 1000; i++){
            vect.push_back(i);
            cout << vect[i] << endl;
        }
    }

    int main() {
        test1();
    }

To capture the time it takes for each of our functions to execute we
will use C++'s ``ctime`` module. The ``ctime`` module is designed
to allow C++ developers to make cross-platform timing measurements by
running functions in a consistent environment and using timing
mechanisms that are as similar as possible across operating systems.

To use ``ctime`` you create two ``clock`` object The first clock object marks the current time; the second clock object marks the current time after the function runs a set number of times. The following session shows how long it takes to run each
of our test functions 1000 times within a ``for`` loop.

::

    t1 = clock_t begin = clock();
    for (int i = 0; i < 1000; i++){
        test1();
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) /CLOCKS_PER_SEC;
    cout << "push back " << elapsed_secs << " milliseconds" << endl;

In the experiment above the statement that we are timing is the function
call to ``test1()``. From the experiment we see that the push_back operation at 0.018
milliseconds.

Now that we have seen how performance can be measured concretely you can
look at :ref:`Table 2 <tbl_listbigocpp>` to see the Big-O efficiency of all the
basic vector operations. After thinking carefully about
:ref:`Table 2 <tbl_listbigocpp>`, you may be wondering about the two different times
for ``pop``. When ``pop`` is called on the end of the list it takes
:math:`O(1)` but when pop is called on the first element in the list
or anywhere in the middle it is :math:`O(n)`. The reason for this lies
in how C++ chooses to implement vectors. When an item is taken from the
front of the vector, in C++ implementation, all the other elements in
the vector are shifted one position closer to the beginning. This may seem
silly to you now, but if you look at :ref:`Table 2 <tbl_listbigocpp>` you will see
that this implementation also allows the index operation to be
:math:`O(1)`. This is a tradeoff that the C++ implementers thought
was a good one.


.. _tbl_listbigocpp:

.. table:: **Table 2: Big-O Efficiency of C++ Vector Operators**

    ================== ==================
             Operation   Big-O Efficiency
    ================== ==================
              index []               O(1)
      index assignment               O(1)
             push_back               O(1)
            pop_back()               O(1)
              erase(i)               O(n)
        insert(i,item)               O(n)
    ================== ==================

As a way of demonstrating this difference in performance let’s do
another experiment using the ``ctime`` module. Our goal is to be able
to verify the performance of the ``pop_back()`` operation on a vector of a known
size when the program pops from the end of the vector using pop_back(), and again when the
program pops from the beginning of the vector using erase(). We will also want to
measure this time for vectors of different sizes. What we would expect to
see is that the time required to pop from the end of the vector will stay
constant even as the vector grows in size, while the time to pop from the
beginning of the vector will continue to increase as the vector grows.

:ref:`Listing 4 <lst_popmeascpp>` shows one attempt to measure the difference
between the pop_back() and erase(). As you can see from this first example,
popping from the end takes 0.000023 milliseconds, whereas popping from the
beginning takes 0.473672 milliseconds.

There are a couple of things to notice about :ref:`Listing 4 <lst_popmeascpp>`. This approach allows us to time just the single ``pop_back()`` statement
and get the most accurate measure of the time for that single operation.
Because the timer repeats 1000 times it is also important to point out
that the vector is decreasing in size by 1 each time through the loop. But
since the initial list is two million elements in size we only reduce
the overall size by :math:`0.05\%`

.. _lst_popmeascpp:

**Listing 4**

::

    clock_t begin = clock();
    for (int i = 0; i < 1000; i++){
        vect.erase(vect.begin()+0);
    }
    clock_t end = clock();
    popzero 0.473672 milliseconds

    clock_t begin = clock();
    for (int i = 0; i < 1000; i++){
        vect.pop_back();
    }
    clock_t end = clock();
    popend 0.000023 milliseconds
