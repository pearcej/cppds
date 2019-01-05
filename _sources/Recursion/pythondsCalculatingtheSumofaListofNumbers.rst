..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Calculating the Sum of a Vector of Numbers
------------------------------------------

We will begin our investigation with a simple problem that you already
know how to solve without using recursion. Suppose that you want to
calculate the sum of a vector of numbers such as:
:math:`[1, 3, 5, 7, 9]`. An iterative function that computes the sum
is shown in :ref:`ActiveCode 1 <lst_itsumcpp>`. The function uses an accumulator variable
(``theSum``) to compute a running total of all the numbers in the vector
by starting with :math:`0` and adding each number in the vector.

.. tabbed:: change_this

  .. tab:: C++

    .. activecode:: lst_itsumcpp
        :caption: Iterative Summation C++
        :language: cpp

        #include <iostream>
        using namespace std;

        int vectsum(int numVect[]){
            int theSum = 0;
            for (int i = 0; i < 5; i++){
                theSum += numVect[i];
            }
            return theSum;
        }

        int main() {
            int numVect[5] = {1,3,5,7,9};
            cout << vectsum(numVect) << endl;

            return 0;
        }

  .. tab:: Python

    .. activecode:: lst_itsumpy
       :caption: Iterative Summation Python

       def listsum(numList):
           theSum = 0
           for i in numList:
               theSum = theSum + i
           return theSum

       def main():
           print(listsum([1,3,5,7,9]))

       main()

Pretend for a minute that you do not have ``while`` loops or ``for``
loops. How would you compute the sum of a vector of numbers? If you were a
mathematician you might start by recalling that addition is a function
that is defined for two parameters, a pair of numbers. To redefine the
problem from adding a vector to adding pairs of numbers, we could rewrite
the vector as a fully parenthesized expression. Such an expression looks
like this:

.. math::

    ((((1 + 3) + 5) + 7) + 9)

We can also parenthesize
the expression the other way around,

.. math::

     (1 + (3 + (5 + (7 + 9))))

Notice that the innermost set of
parentheses, :math:`(7 + 9)`, is a problem that we can solve without a
loop or any special constructs. In fact, we can use the following
sequence of simplifications to compute a final sum.

.. math::

    total = \  (1 + (3 + (5 + (7 + 9)))) \\
    total = \  (1 + (3 + (5 + 16))) \\
    total = \  (1 + (3 + 21)) \\
    total = \  (1 + 24) \\
    total = \  25


How can we take this idea and turn it into a C++ program? First,
let’s restate the sum problem in terms of C++ arrays. We might say the
the sum of the vector ``numVect`` is the sum of the first element of the
vector (``numVect[0]``), and the sum of the numbers in the rest of the array (``numVect.erase(numVect.begin()+0)``).


In this equation :math:`first(numVect)` returns the first element of
the array and :math:`rest(numVect)` returns an array of everything but
the first element. This is easily expressed in C++ as shown in
:ref:`ActiveCode 2 <lst_recsumcpp>`.

.. tabbed:: recsumcode

  .. tab:: C++

    .. activecode:: lst_recsumcpp
      :caption: Recursion Summation C++
      :language: cpp

      #include <iostream>
      #include <vector>
      using namespace std;

      int vectsum(vector<int> numVect){
          if (numVect.size() <= 1){
              return numVect[0];
          }
          else {
              vector<int> slice(numVect.begin()+1, numVect.begin()+numVect.size());
              return numVect[0] + vectsum(slice);
          }
      }

      int main() {
          int arr2[] = {1, 3, 5, 7, 9};
          vector<int> numVect(arr2,arr2+(sizeof(arr2)/ sizeof(arr2[0])));  //Initializing vector
          cout << vectsum(numVect) << endl;

          return 0;
      }

  .. tab:: Python

    .. activecode:: lst_recsumpy
       :caption: Recursion Summation Python

       def listsum(numList):
           if len(numList) == 1:
               return numList[0]
           else:
               return numList[0] + listsum(numList[1:])

       def main():
           print(listsum([1,3,5,7,9]))

       main()

There are a few key ideas while using vector to look at. First, on line 6 we are checking to see if the vector is one element long. This
check is crucial and is our escape clause from the function. The sum of
a vector of length 1 is trivial; it is just the number in the vector.
Second, on line 11 our function calls itself! This is the
reason that we call the ``vectsum`` algorithm recursive. A recursive
function is a function that calls itself.

:ref:`Figure 1 <fig_recsumin>` shows the series of **recursive calls** that are
needed to sum the vector :math:`[1, 3, 5, 7, 9]`. You should think of
this series of calls as a series of simplifications. Each time we make a
recursive call we are solving a smaller problem, until we reach the
point where the problem cannot get any smaller.

.. _fig_recsumin:

.. figure:: Figures/sumlistIn.png
   :align: center
   :alt: image


   Figure 1: Series of Recursive Calls Adding a List of Numbers

When we reach the point where the problem is as simple as it can get, we
begin to piece together the solutions of each of the small problems
until the initial problem is solved. :ref:`Figure 2 <fig_recsumout>` shows the
additions that are performed as ``vectsum`` works its way backward
through the series of calls. When ``vectsum`` returns from the topmost
problem, we have the solution to the whole problem.

.. _fig_recsumout:

.. figure:: Figures/sumlistOut.png
   :align: center
   :alt: image

   Figure2: Series of Recursive Returns from Adding a List of Numbers
