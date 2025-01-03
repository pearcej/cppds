..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Big-O Notation
--------------

When trying to characterize an algorithm’s efficiency in terms of
execution time, independent of any particular program or computer, it is
important to quantify the number of operations or steps that the
algorithm will require. If each of these steps is considered to be a
basic unit of computation, then the execution time for an algorithm can
be expressed as the number of steps required to solve the problem.
Deciding on an appropriate basic unit of computation can be a
complicated problem and will depend on how the algorithm is implemented.

A good basic unit of computation for comparing the summation algorithms
shown earlier might be to count the number of assignment statements
performed to compute the sum. In the function ``sumOfN``, the number of
assignment statements is 1 (:math:`theSum = 0`)
plus the value of *n* (the number of times we perform
:math:`theSum=theSum+i`). We can denote this by a function, call it T,
where :math:`T(n)=1 + n`. The parameter *n* is often referred to as
the “size of the problem,” and we can read this as “T(n) is the time
it takes to solve a problem of size n, namely 1+n steps.”

In the summation functions given above, it makes sense to use the number
of terms in the summation to denote the size of the problem. We can then
say that the sum of the first 100,000 integers is a bigger instance of
the summation problem than the sum of the first 1,000. Because of this,
it might seem reasonable that the time required to solve the larger case
would be greater than for the smaller case. Our goal then is to show how
the algorithm’s execution time changes with respect to the size of the
problem.

Computer scientists prefer to take this analysis technique one step
further. It turns out that the exact number of operations is not as
important as determining the most dominant part of the :math:`T(n)`
function. In other words, as the problem gets larger, some portion of
the :math:`T(n)` function tends to overpower the rest. This dominant
term is what, in the end, is used for comparison. The **order of
magnitude** function describes the part of :math:`T(n)` that increases
the fastest as the value of *n* increases. Order of magnitude is often
called **Big-O notation** (for “order”) and written as
:math:`O(f(n))`. It provides a useful approximation to the actual
number of steps in the computation. The function :math:`f(n)` provides
a simple representation of the dominant part of the original
:math:`T(n)`.

In the above example, :math:`T(n)=1+n`. As *n* gets large, the
constant 1 will become less and less significant to the final result. If
we are looking for an approximation for :math:`T(n)`, then we can drop
the 1 and simply say that the running time is :math:`O(n)`. It is
important to note that the 1 is certainly significant for
:math:`T(n)`. However, as *n* gets large, our approximation will be
just as accurate without it.

As another example, suppose that for some algorithm, the exact number of
steps is :math:`T(n)=5n^{2}+27n+1005`. When *n* is small, say 1 or 2,
the constant 1005 seems to be the dominant part of the function.
However, as *n* gets larger, the :math:`n^{2}` term becomes the most
important. In fact, when *n* is really large, the other two terms become
insignificant in the role that they play in determining the final
result. Again, to approximate :math:`T(n)` as *n* gets large, we can
ignore the other terms and focus on :math:`5n^{2}`. In addition, the
coefficient :math:`5` becomes insignificant as *n* gets large. We
would say then that the function :math:`T(n)` has an order of
magnitude :math:`f(n)=n^{2}`, or simply that it is :math:`O(n^{2})`.


.. mchoice:: bigo3
    :answer_a: O(2n)
    :answer_b: O(n)
    :answer_c: O(3n<sup>2</sup>)
    :answer_d: O(n<sup>2</sup>)
    :answer_e: More than one of the above
    :correct: d
    :feedback_a: No, 3n<sup>2</sup> dominates 2n. Try again.
    :feedback_b: No, n<sup>2</sup> dominates n. Try again.
    :feedback_c: No, the 3 should be omitted because n<sup>2</sup> dominates.
    :feedback_d: Right!
    :feedback_e: No, only one of them is correct. Try again.


    If the exact number of steps is :math:`T(n)=2n+3n^{2}-1` what is the Big O?


Although we do not see this in the summation example, sometimes the
performance of an algorithm depends on the exact values of the data
rather than simply the size of the problem. For these kinds of
algorithms we need to characterize their performance in terms of **best
case**, **worst case**, or **average case** performance. The worst-case 
performance refers to a particular data set where the algorithm performs 
extremely poorly. At the same time, a different data set for the exact 
same algorithm might have outstanding performance. However, in most
cases the algorithm performs somewhere in between these two extremes
(average case). It is important for a computer scientist to understand
these distinctions so they are not misled by one particular case.


A number of very common order of magnitude functions will come up over
and over as you study algorithms. These are shown in :ref:`Table 1 <tbl_fntablecpp>`. In
order to decide which of these functions is the dominant part of any
:math:`T(n)` function, we must see how they compare with one another
as *n* gets large.

.. _tbl_fntablecpp:

.. table:: **Table 1: Common Big-O Functions**

    ================= =============
             **f(n)**      **Name**
    ================= =============
          :math:`1`      Constant
     :math:`\log n`   Logarithmic
          :math:`n`        Linear
    :math:`n\log n`    Log Linear
      :math:`n^{2}`     Quadratic
      :math:`n^{3}`         Cubic
      :math:`2^{n}`   Exponential
    ================= =============


:ref:`Figure 1 <fig_graphfigurecpp>` shows graphs of the common
functions from :ref:`Table 1 <tbl_fntablecpp>`. Notice that when *n* is small, the
functions are not very well defined with respect to one another. It is
hard to tell which is dominant. However, as *n* grows, there is a
definite relationship and it is easy to see how they compare with one
another.

.. _fig_graphfigurecpp:

.. figure:: Figures/newplot.png

   Figure 1: Common Big-O Functions


.. parsonsprob:: parsonsBigO

    Without looking at the graph above, from top to bottom order the following from most to least efficient.
    -----
    constant
    logarithmic
    linear
    log linear
    quadratic
    cubic
    exponential

As a final example, suppose that we have the fragment of C++ code
shown in :ref:`Listing 2 <lst_dummycode>`. Although this program does not really do
anything, it is instructive to see how we can take actual code and
analyze performance.

.. _lst_dummycode:

**Listing 2**

**C++ Implementation**

::

    #include <iostream>
    using namespace std;

    int main(){
        int a=5;
        int b=6;
        int c=10;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int x = i * i;
                int y = j * j;
                int z = i * j;
            }
        }

        for (int k = 0; k < n; k++){
            int w = a*k + 45;
            int v = b*b;
        }
        int d = 33;
        return 0;
    }

**Python Implementation**

::

    def main():
        a=5
        b=6
        c=10
        for i in range(n):
            for j in range(n):
               x = i * i
               y = j * j
               z = i * j
        for k in range(n):
            w = a*k + 45
            v = b*b
        d = 33
    main()



The number of assignment operations is the sum of four terms. The first
term is the constant 3, representing the three assignment statements at
the start of the fragment. The second term is :math:`3n^{2}`, since
there are three statements that are performed :math:`n^{2}` times due
to the nested iteration. The third term is :math:`2n`, two statements
iterated *n* times. Finally, the fourth term is the constant 1,
representing the final assignment statement. This gives us
:math:`T(n)=3+3n^{2}+2n+1=3n^{2}+2n+4`. By looking at the exponents,
we can easily see that the :math:`n^{2}` term will be dominant and
therefore this fragment of code is :math:`O(n^{2})`. Note that all of
the other terms as well as the coefficient on the dominant term can be
ignored as *n* grows larger.

.. _fig_graphfigure2cpp:

.. figure:: Figures/newplot2.png

   Figure 2: Comparing :math:`T(n)` with Big-O Functions


:ref:`Figure 2 <fig_graphfigure2cpp>` shows a few of the common Big-O functions as they
compare with the :math:`T(n)` function discussed above. Note that
:math:`T(n)` is initially larger than the cubic function. However, as
n grows, the cubic function quickly overtakes :math:`T(n)`. It is easy
to see that :math:`T(n)` then follows the quadratic function as
:math:`n` continues to grow.

.. mchoice:: crossoverefficiency
    :answer_a: Algorithm 1 will require a greater number of steps to complete than Algorithm 2
    :answer_b: Algorithm 2 will require a greater number of steps to complete than Algorithm 1
    :answer_c: Algorithm 1 will require a greater number of steps to complete than Algorithm 2 until they reach the crossover point
    :answer_d: Algorithm 1 and 2 will always require the same number of steps to complete
    :correct: c
    :feedback_a: This could be true depending on the input, but consider the broader picture
    :feedback_b: This could be true depending on the input, but consider the broader picture
    :feedback_c: Correct!
    :feedback_d: No, the efficiency of both will depend on the input

    Which of the following statements is true about the two algorithms?
    Algorithm 1: 100n + 1
    Algorithm 2: n^2 + n + 1


.. admonition:: Self Check

    

    .. mchoice:: BIGO1
        :answer_a: 3.444
        :answer_b: 2.53
        :answer_c: 2.04
        :answer_d: 4
        :answer_e: More than one of the above
        :correct: c
        :feedback_a: Incorrect. Try again.
        :feedback_b: Incorrect. Try again.
        :feedback_c: Correct!
        :feedback_d:  Incorrect. Try again.
        :feedback_e: No, only one of them is correct. Try again.

        The Big O of a particular algorithm is :math:`O(log_{2}n)`.
        Given that it takes 2 seconds to complete the algorithm with 3 million inputs;
        how long would it take with 4 million inputs?


    .. mchoice:: BIGO2
        :answer_a: 3.444
        :answer_b: 2.53
        :answer_c: 2
        :answer_d: 4.2
        :answer_e: More than one of the above
        :correct: d
        :feedback_a: Incorrect. Try again.
        :feedback_b: Incorrect. Try again.
        :feedback_c: Incorrect. Try again.
        :feedback_d: Right!
        :feedback_e: No, only one of them is correct. Try again.

        The Big O of a particular algorithm is :math:`O(log_{2}n)`.
        Given that it takes 2 seconds to complete the algorithm with 3 million inputs;
        how long would it take with 10 million inputs?

    .. mchoice:: BIGO3
        :answer_a: 2000
        :answer_b: 3000
        :answer_c: 16
        :answer_d: 1500
        :answer_e: More than one of the above
        :correct: c
        :feedback_a: Incorrect. Try again. Think about what happens to the time as more operations occur.
        :feedback_b: Incorrect. Try again. Think about what happens to the time as more operations occur.
        :feedback_c: Correct!
        :feedback_d:  Incorrect. Try again. Think about what happens to the time as more operations occur.
        :feedback_e: No, only one of them is correct. Try again.

        The Big O of a particular algorithm is :math:`O(n^{3})`.
        Given that it takes 2 seconds to complete the algorithm with 1000 inputs;
        how long would it take with 2000 inputs?

    .. mchoice:: BIGO4
        :answer_a: 2000
        :answer_b: 3000
        :answer_c: 16
        :answer_d: 1500
        :answer_e: More than one of the above
        :correct: a
        :feedback_a: Right!
        :feedback_b: Incorrect. Try again. Think about what happens to the time as more operations occur.
        :feedback_c: Incorrect. Try again. Think about what happens to the time as more operations occur.
        :feedback_d:  Incorrect. Try again. Think about what happens to the time as more operations occur.
        :feedback_e: No, only one of them is correct. Try again.

        The Big O of a particular algorithm is :math:`O(n^{3})`.
        Given that it takes 2 seconds to complete the algorithm with 1000 inputs;
        how long would it take with 10,000 inputs?
