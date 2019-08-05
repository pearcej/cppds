..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Binary Search
~~~~~~~~~~~~~~~~~

It is possible to take greater advantage of the ordered vector if we are
clever with our comparisons. In the sequential search, when we compare
against the first item, there are at most :math:`n-1` more items to
look through if the first item is not what we are looking for. Instead
of searching the vector in sequence, a **binary search** will start by
examining the middle item. If that item is the one we are searching for,
we are done. If it is not the correct item, we can use the ordered
nature of the vector to eliminate half of the remaining items. If the item
we are searching for is greater than the middle item, we know that the
entire lower half of the vector as well as the middle item can be
eliminated from further consideration. The item, if it is in the vector,
must be in the upper half.

We can then repeat the process with the upper half. Start at the middle
item and compare it against what we are looking for. Again, we either
find it or split the vector in half, therefore eliminating another large
part of our possible search space. :ref:`Figure 3 <fig_binsearch>` shows how this
algorithm can quickly find the value 54. The complete function is shown
in :ref:`CodeLens 3 <lst_binarysearchpy>`.


.. _fig_binsearch:

.. figure:: Figures/binsearch.png
   :align: center

   Figure 3: Binary Search of an Ordered vector of Integers


.. _lst_binarysearchpy:

.. codelens:: search3
    :caption: Binary Search of an Ordered List
    
    # Checks to see if item is in a list  
    # retruns true or false 
    # using binary Search
    def binarySearch(alist, item):
        first = 0
        last = len(alist)-1
        found = False

        while first<=last and not found:
            midpoint = (first + last)//2
            if alist[midpoint] == item:
                found = True
            else:
                if item < alist[midpoint]:
                    last = midpoint-1
                else:
                    first = midpoint+1

        return found

    def main():

        testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42,]
        print(binarySearch(testlist, 3))
        print(binarySearch(testlist, 13))

    main()

A similar implementation can be carried out using vectors in C++.

.. activecode:: binary_search_cpp
  :caption: Iterative Binary Search Implementation
  :language: cpp

  #include <iostream>
  #include <vector>
  using namespace std;

  // Checks to see if item is in a vector  
  // retruns true or false (1 or 0) 
  // using binary Search
  bool binarySearch(vector<int> avector, int item) {
      int first = 0;
      int last = avector.size() - 1;
      bool found = false;

      while (first <= last && !found) {
          int midpoint = (first + last) / 2;
          if (avector[midpoint] == item) {
              found = true;
          } else {
              if (item < avector[midpoint]) {
                  last = midpoint - 1;
              } else {
                  first = midpoint + 1;
              }
          }
      }
      return found;
  }

  int main() {
      // Using static array to initialize a vector
      static const int arr[] = {0, 1, 2, 8, 13, 17, 19, 32, 42};
      vector<int> avector(arr, arr + sizeof(arr) / sizeof(arr[0]));

      cout << binarySearch(avector, 3) << endl;
      cout << binarySearch(avector, 13) << endl;

      return 0;
  }

Before we move on to the analysis, we should note that this algorithm is
a great example of a divide and conquer strategy. Divide and conquer
means that we divide the problem into smaller pieces, solve the smaller
pieces in some way, and then reassemble the whole problem to get the
result. When we perform a binary search of a list, we first check the
middle item. If the item we are searching for is less than the middle
item, we can simply perform a binary search of the left half of the
original list. Likewise, if the item is greater, we can perform a binary
search of the right half. Either way, this is a recursive call to the
binary search function passing a smaller list. :ref:`CodeLens 4 <lst_recbinarysearch>`
shows this recursive version.

.. _lst_recbinarysearch:

.. codelens:: search4
    :caption: A Binary Search--Recursive Version

    # Checks to see if item is in a list  
    # retruns true or false 
    # using binary Search recursively 
    def binarySearch(alist, item):
        if len(alist) == 0:
            return False
        else:
            midpoint = len(alist)//2
            if alist[midpoint]==item:
              return True
            else:
              if item<alist[midpoint]:
                return binarySearch(alist[:midpoint],item)
              else:
                return binarySearch(alist[midpoint+1:],item)

    testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42,]
    print(binarySearch(testlist, 3))
    print(binarySearch(testlist, 13))

There is a vector initializer within C++ that can be used much like python slices,
however this can only be used when new vectors are created.

.. activecode:: binary_search_cpp_recursive
  :caption: A Recursive Binary Search
  :language: cpp

  #include <iostream>
  #include <vector>
  using namespace std;

   // Checks to see if item is in a vector
   // retruns true or false (1 or 0)
   // using binary Search and 
   // seperating the vector in halves

  bool binarySearch(vector<int> alist, int item) {
  	if (alist.size() == 0) {
  		return false;
  	} else {
  		int midpoint = alist.size() / 2;
  		if (alist[midpoint] == item) {
  			return true;
  		} else {
  			if (item < alist[midpoint]) {
  				vector<int> lefthalf(alist.begin(), alist.begin() + midpoint);
  				return binarySearch(lefthalf, item);
  			} else {
  				vector<int> righthalf(
  					alist.begin() + midpoint + 1, alist.end());
  				return binarySearch(righthalf, item);
  			}
  		}
  	}
  }

  int main() {
  	// Using static array to initialize a vector
  	static const int arr[] = {0, 1, 2, 8, 13, 17, 19, 32, 42};
  	vector<int> alist(arr, arr + sizeof(arr) / sizeof(arr[0]));

  	cout << binarySearch(alist, 3) << endl;
  	cout << binarySearch(alist, 13) << endl;

  	return 0;
  }



Analysis of Binary Search
^^^^^^^^^^^^^^^^^^^^^^^^^

To analyze the binary search algorithm, we need to recall that each
comparison eliminates about half of the remaining items from
consideration. What is the maximum number of comparisons this algorithm
will require to check the entire list? If we start with *n* items, about
:math:`\frac{n}{2}` items will be left after the first comparison.
After the second comparison, there will be about :math:`\frac{n}{4}`.
Then :math:`\frac{n}{8}`, :math:`\frac{n}{16}`, and so on. How many
times can we split the list? :ref:`Table 3 <tbl_binaryanalysis>` helps us to see the
answer.

.. _tbl_binaryanalysis:

.. table:: **Table 3: Tabular Analysis for a Binary Search**

    ======================== ======================================
             **Comparisons**   **Approximate Number of Items Left**
    ======================== ======================================
                           1                   :math:`\frac {n}{2}`
                           2                   :math:`\frac {n}{4}`
                           3                   :math:`\frac {n}{8}`
                         ...
                           i                 :math:`\frac {n}{2^i}`
    ======================== ======================================


When we split the list enough times, we end up with a list that has just
one item. Either that is the item we are looking for or it is not.
Either way, we are done. The number of comparisons necessary to get to
this point is *i* where :math:`\frac {n}{2^i} =1`. Solving for *i*
gives us :math:`i=\log n`. The maximum number of comparisons is
logarithmic with respect to the number of items in the list. Therefore,
the binary search is :math:`O(\log n)`.

One additional analysis issue needs to be addressed. In the recursive
solution shown above, the recursive call,

``binarySearch(alist[:midpoint],item)``

uses the slice operator to create the left half of the list that is then
passed to the next invocation (similarly for the right half as well).
The analysis that we did above assumed that the slice operator takes
constant time. This means that the binary search using slice will not
perform in strict logarithmic time. Luckily this can be remedied by
passing the list along with the starting and ending indices. The indices
can be calculated as we did in :ref:`Listing 3 <lst_binarysearchpy>`. This is especially relevant in C++, where we are initializing a new vector for each split of our list. To truly optimize this algorithm, we could use an array and manually keep track of start and end indices of our array. Below is an example of such an implementation.

.. tabbed:: binary_search

    .. tab:: C++

        .. activecode:: binary_search_cpp_array
            :caption: Optimized Binary Search
            :language: cpp

            #include <iostream>
            using namespace std;

            //Checks to see if item is in a vector
            //retruns true or false (1 or 0)
            //using binary Search and 
            //uses start and end indices
            bool binarySearch(int arr[], int item, int start, int end) {
                if (end >= start) {
                    int mid = start + (end - start) / 2;
                    if (arr[mid] == item)
                        return true;
                    if (arr[mid] > item)
                        return binarySearch(arr, item, start, mid - 1);
                    else {
                        return binarySearch(arr, item, mid + 1, end);
                    }
                }

                return false;
            }

            bool binarySearchHelper(int arr[], int size, int item) {
                return binarySearch(arr, item, 0, size);
            }

            int main(void) {
                int arr[] = {0, 1, 2, 8, 13, 17, 19, 32, 42};
                int arrLength = sizeof(arr) / sizeof(arr[0]);

                cout << binarySearchHelper(arr, arrLength, 3) << endl;
                cout << binarySearchHelper(arr, arrLength, 13) << endl;

                return 0;
            }

    .. tab:: Python

        .. activecode:: binary_search_python_array
            :caption: Optimized Binary Search

            '''Checks to see if item is in a list
            retruns true or false (1 or 0)
            using binary Search and 
            uses start and end indices'''
            
            def binarySearch(array, item, start, end):
                
                if end == start: 
                    return False
                if end >= start: 
                    mid = start + (end - start) // 2
                    if array[mid] == item:
                        return True
                    if array[mid] > item:
                        return binarySearch(array, item, start, mid - 1)
                    else:
                        return binarySearch(array, item, mid + 1, end)

                return False

            def main():
                array = [0, 1, 2, 8, 13, 17, 19, 32, 42]
                
                a = binarySearch(array, 17, 0 , len(array))
                print("answer is ", a)
                b = binarySearch(array, 99, 0, len(array))
                print("answer is", b) 
            main()
            

Even though a binary search is generally better than a sequential
search, it is important to note that for small values of *n*, the
additional cost of sorting is probably not worth it. In fact, we should
always consider whether it is cost effective to take on the extra work
of sorting to gain searching benefits. If we can sort once and then
search many times, the cost of the sort is not so significant. However,
for large lists, sorting even once can be so expensive that simply
performing a sequential search from the start may be the best choice.

.. admonition:: Self Check

   .. mchoice:: BSRCH_1
      :correct: b
      :answer_a: 11, 5, 8
      :answer_b: 12, 6, 8
      :answer_c: 3, 5, 8
      :answer_d: 18, 12, 8
      :feedback_a:  Looks like you might be guilty of an off-by-one error.  Remember the first position is index 0.
      :feedback_b:  Binary search starts at the midpoint and halves the list each time.
      :feedback_c: Binary search does not start at the beginning and search sequentially, its starts in the middle and halves the list after each compare.
      :feedback_d: It appears that you are starting from the end and halving the list each time.

      Suppose you have the following sorted list [3, 5, 6, 8, 11, 12, 14, 15, 17, 18] and are using the recursive binary search algorithm.  Which group of numbers correctly shows the sequence of comparisons used to find the key 8.

   .. mchoice:: BSRCH_2
      :correct: d
      :answer_a: 11, 14, 17, 15
      :answer_b: 18, 17, 14, 15
      :answer_c: 14, 12, 17, 15
      :answer_d: 12, 14, 17, 15
      :feedback_a:  Looks like you might be guilty of an off-by-one error.  Remember the first position is index 0.
      :feedback_b:  Remember binary search starts in the middle and halves the list.
      :feedback_c:  Looks like you might be off by one, be careful that you are calculating the midpont using integer arithmetic.
      :feedback_d: Binary search starts at the midpoint and halves the list each time. It is done when the list is empty.

      Suppose you have the following sorted list [3, 5, 6, 8, 11, 12, 14, 15, 17, 18] and are using the recursive binary search algorithm.  Which group of numbers correctly shows the sequence of comparisons used to search for the key 16?
