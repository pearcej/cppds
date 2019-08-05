..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Three Laws of Recursion
---------------------------

Like the robots of Asimov, all recursive algorithms must obey three
important laws:


   #. A recursive algorithm must have a **base case**.

   #. A recursive algorithm must change its state and move toward the base
      case.

   #. A recursive algorithm must call itself, recursively.

Let’s look at each one of these laws in more detail and see how it was
used in the ``vectsum`` algorithm. First, a base case is the condition
that allows the algorithm to stop recursing. A base case is typically a
problem that is small enough to solve directly. In the ``vectsum``
algorithm the base case is a list of length 1.

To obey the second law, we must arrange for a change of state that moves
the algorithm toward the base case. A change of state means that some
data that the algorithm is using is modified. Usually the data that
represents our problem gets smaller in some way. In the ``vectsum``
algorithm our primary data structure is a vector, so we must focus our
state-changing efforts on the vector. Since the base case is a list of
length 1, a natural progression toward the base case is to shorten the
vector. This is exactly what happens on line 5 of :ref:`ActiveCode 2 <lst_recsumcpp>` when we call ``vectsum`` with a shorter list.

The final law is that the algorithm must call itself. This is the very
definition of recursion. Recursion is a confusing concept to many
beginning programmers. As a novice programmer, you have learned that
functions are good because you can take a large problem and break it up
into smaller problems. The smaller problems can be solved by writing a
function to solve each problem. When we talk about recursion it may seem
that we are talking ourselves in circles. We have a problem to solve
with a function, but that function solves the problem by calling itself!
But the logic is not circular at all; the logic of recursion is an
elegant expression of solving a problem by breaking it down into smaller 
and easier problems.

It is important to note that regardless of whether or not a recursive function
implements these three rules, it may still take an unrealistic amount of time
to compute (and thus not be particularly useful). A great example of this is the
ackermann function, named after Wilhelm Ackermann, which recursively expands to 
unrealistic proportions. An example as to how many calls this function makes to 
itself is the case of ackermann(4,3). In this case, it calls itself well over 100
billion times, with an average time of expected completion that falls after the
predicted end of the universe. Despite this, it will eventually come to an answer,
but you probably won't be around to see it. This goes to show that the efficiency
of recursive functions are largely dependent on how they're implemented.

.. activecode:: ackermann
   :language: cpp
   :nocodelens:

   //ackermann function example
   #include <iostream>
   using namespace std;

   unsigned int ackermann(unsigned int m, unsigned int n) {
      if (m == 0) {//Base case
         return n + 1;
      }
      if (n == 0) {
         return ackermann(m - 1, 1);// subtract, move to base case
      }
      //notice a call to the ackermann function as a parameter
      //for another call to the ackermann function. This is where
      //it gets unrealistically complicated.
      return ackermann(m - 1, ackermann(m, n - 1));//subtract here too
   }

   int main(){
      //compute the ackermann function.
      //Try replacing the 1,2 parameters with 4,3 and see what happens
      cout << ackermann(1,2) << endl;
      return 0;
   }

In the remainder of this chapter we will look at more examples of
recursion. In each case we will focus on designing a solution to a
problem by using the three laws of recursion.


.. admonition:: Self Check

   .. mchoice:: question_recsimp_1
      :answer_c: If a recursive function didn't have a base case, then the function would continue to make recursive calls creating an infinite loop.
      :answer_b: If a recursive function didn't have a base case, then the function would return an undesired outcome.
      :answer_a: If a recursive function didn't have a base case, then the function would end too early.
      :answer_d: If a recursive function didn't have a base case, then the function would not be able to ever make recursive calls in the first place.
      :correct: c
      :feedback_c: Correct! a base case is needed to end the continuous recursive calls, so that the program doesn't get stuck in a never ending loop.
      :feedback_b: Incorrect. In fact, the program wouldn't return anything. 
      :feedback_a: Incorrect. The complete opposite would happen instead.
      :feedback_d: Incorrect. Recursive calls will continue to be called even without a base case.

      Why is a base case needed in a recursive function?

   .. mchoice:: question_recsimp_2
      :correct: c
      :answer_a: 6
      :answer_b: 5
      :answer_c: 4
      :answer_d: 3
      :feedback_a: There are only five numbers on the vector, the number of recursive calls will not be greater than the size of the vector.
      :feedback_b: The initial call to vectsum is not a recursive call.
      :feedback_c: the first recursive call passes the vector {4,6,8,10}, the second {6,8,10} and so on until [10].
      :feedback_d: This would not be enough calls to cover all the numbers on the vector

      How many recursive calls are made when computing the sum of the vector {2,4,6,8,10}?

   .. mchoice:: question_recsimp_3
      :correct: d
      :answer_a: n == 0
      :answer_b: n == 1
      :answer_c: n &gt;= 0
      :answer_d: n &lt;= 1
      :feedback_a:  Although this would work there are better and slightly more efficient choices. since fact(1) and fact(0) are the same.
      :feedback_b: A good choice, but what happens if you call fact(0)?
      :feedback_c: This base case would be true for all numbers greater than zero so fact of any positive number would be 1.
      :feedback_d: Good, this is the most efficient, and even keeps your program from crashing if you try to compute the factorial of a negative number.

      Suppose you are going to write a recursive function to calculate the factorial of a number.  fact(n) returns n * n-1 * n-2 * ... Where the factorial of zero is defined to be 1.  What would be the most appropriate base case?
