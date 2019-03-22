..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Bubble Sort
~~~~~~~~~~~~~~~

The **bubble sort** makes multiple passes through an array. It compares
adjacent items and exchanges those that are out of order. Each pass
through the array places the next largest value in its proper place. In
essence, each item “bubbles” up to the location where it belongs.

:ref:`Figure 1 <fig_bubblepass>` shows the first pass of a bubble sort. The shaded
items are being compared to see if they are out of order. If there are
*n* items in the array, then there are :math:`n-1` pairs of items that
need to be compared on the first pass. It is important to note that once
the largest value in the array is part of a pair, it will continually be
moved along until the pass is complete.

.. _fig_bubblepass:

.. figure:: Figures/bubblepass.png
   :align: center

   Figure 1: ``bubbleSort``: The First Pass


At the start of the second pass, the largest value is now in place.
There are :math:`n-1` items left to sort, meaning that there will be
:math:`n-2` pairs. Since each pass places the next largest value in
place, the total number of passes necessary will be :math:`n-1`. After
completing the :math:`n-1` passes, the smallest item must be in the
correct position with no further processing required. :ref:`ActiveCode 1 <lst_bubble_cpp>`
shows the complete ``bubbleSort`` function. It takes the array as a
parameter, and modifies it by swapping items as necessary.

Typically, swapping two elements in an array requires a temporary storage location (an
additional memory location). A code fragment such as

::

    temp = alist[i];
    alist[i] = alist[j];
    alist[j] = temp;

will exchange the `ith` and `jth` items in the array. Without the
temporary storage, one of the values would be overwritten.

Lines 5-7 in :ref:`ActiveCode 1 <lst_bubble_cpp>` perform the exchange of the :math:`i` and
:math:`(i+1)th` items using the three–step procedure described
earlier. Note that we could also have used the simultaneous assignment
to swap the items.

.. _fig_pythonswap:

.. figure:: Figures/swap.png
   :align: center

   Figure 2: Exchanging Two Values in Python

The following activecode example shows the complete ``bubbleSort`` function working on the array
shown above.

.. tabbed:: lst_bubble_sort

  .. tab:: C++

    .. activecode:: lst_bubble_cpp
      :caption: The Bubble Sort
      :language: cpp

      #include <iostream>
      #include <vector>
      using namespace std;

      vector<int> bubbleSort(vector<int> avector) {
        for (int passnum = avector.size()-1; passnum > 0; passnum -= 1) {
            for (int i = 0; i < passnum; i++) {
                if (avector[i] > avector[i+1]) {
                    int temp = avector[i];
                    avector[i] = avector[i+1];
                    avector[i+1] = temp;
                }
            }
        }
        return avector;
      }

      int main() {
          // Vector initialized using a static array
          static const int arr[] = {54,26,93,17,77,31,44,55,20};
          vector<int> avector (arr, arr + sizeof(arr) / sizeof(arr[0]) );

          vector<int> bvector = bubbleSort(avector);
          for (unsigned int i = 0; i < bvector.size(); i++) {
              cout<<bvector[i]<< " ";
          }
          return 0;
      }


  .. tab:: Python

    .. activecode:: lst_bubble_py
       :caption: The Bubble Sort

       def bubbleSort(alist):
           for passnum in range(len(alist)-1,0,-1):
               for i in range(passnum):
                   if alist[i]>alist[i+1]:
                       temp = alist[i]
                       alist[i] = alist[i+1]
                       alist[i+1] = temp

       def main():
           alist = [54,26,93,17,77,31,44,55,20]
           bubbleSort(alist)
           print(alist)

       main()




The following animation shows ``bubbleSort`` in action.

.. animation:: bubble_anim
   :modelfile: sortmodels.js
   :viewerfile: sortviewers.js
   :model: BubbleSortModel
   :viewer: BarViewer

.. For more detail, CodeLens 1 allows you to step through the algorithm.
..
.. .. codelens:: bubbletrace
..     :caption: Tracing the Bubble Sort
..
..     def bubbleSort(alist):
..         for passnum in range(len(alist)-1,0,-1):
..             for i in range(passnum):
..                 if alist[i]>alist[i+1]:
..                     temp = alist[i]
..                     alist[i] = alist[i+1]
..                     alist[i+1] = temp
..
..     alist = [54,26,93,17,77,31,44,55,20]
..     bubbleSort(alist)
..     print(alist)


To analyze the bubble sort, we should note that regardless of how the
items are arranged in the initial array, :math:`n-1` passes will be
made to sort a array of size *n*. :ref:`Table 1 <tbl_bubbleanalysis>` shows the number
of comparisons for each pass. The total number of comparisons is the sum
of the first :math:`n-1` integers. Recall that the sum of the first
*n* integers is :math:`\frac{1}{2}n^{2} + \frac{1}{2}n`. The sum of
the first :math:`n-1` integers is
:math:`\frac{1}{2}n^{2} + \frac{1}{2}n - n`, which is
:math:`\frac{1}{2}n^{2} - \frac{1}{2}n`. This is still
:math:`O(n^{2})` comparisons. In the best case, if the array is already
ordered, no exchanges will be made. However, in the worst case, every
comparison will cause an exchange. On average, we exchange half of the
time.

.. _tbl_bubbleanalysis:

.. table:: **Table 1: Comparisons for Each Pass of Bubble Sort**

    ================= ==================
    **Pass**          **Comparisons**
    ================= ==================
             1         :math:`n-1`
             2         :math:`n-2`
             3         :math:`n-3`
             ...       ...
       :math:`n-1`     :math:`1`
    ================= ==================


A bubble sort is often considered the most inefficient sorting method
since it must exchange items before the final location is known. These
“wasted” exchange operations are very costly. However, because the
bubble sort makes passes through the entire unsorted portion of the
array, it has the capability to do something most sorting algorithms
cannot. In particular, if during a pass there are no exchanges, then we
know that the array must be sorted. A bubble sort can be modified to stop
early if it finds that the array has become sorted. This means that for
arrays that require just a few passes, a bubble sort may have an
advantage in that it will recognize the sorted array and stop.
:ref:`ActiveCode 2 <lst_shortbubbles_cpp>` shows this modification, which is often referred
to as the **short bubble**.

.. tabbed:: lst_shortbubble

  .. tab:: C++

    .. activecode:: lst_shortbubbles_cpp
      :caption: The Short Bubble Sort in C++
      :language: cpp

      #include <iostream>
      #include <vector>

      using namespace std;

      vector<int> shortBubbleSort(vector<int> avector){
          bool exchanges = true;
          int passnum = avector.size();

          while (passnum > 0 && exchanges) {
              exchanges = false;

              for(int i = 0; i < passnum; i++){
                  if(avector[i] > avector[i+1]){
                      exchanges = true;
                      int temp = avector[i];
                      avector[i] = avector[i+1];
                      avector[i+1] = temp;
                  }
              }
              passnum = passnum - 1;
          }
          return avector;
      }

      int main() {
          // Vector initialized using a static array
          static const int arr[] = {20,30,40,90,50,60,70,80,110,100};
          vector<int> avector (arr, arr+ sizeof(arr)/sizeof(arr[0]));

          vector<int> bvector = shortBubbleSort(avector);

          for(unsigned int i = 0; i < bvector.size(); i++){
            cout<< bvector[i] << " ";
          }
          return 0;
      }



  .. tab:: Python

    .. activecode:: lst_shortbubble_py
       :caption: The Short Bubble Sort in Python

       def shortBubbleSort(alist):
           exchanges = True
           passnum = len(alist)-1
           while passnum > 0 and exchanges:
              exchanges = False
              for i in range(passnum):
                  if alist[i]>alist[i+1]:
                      exchanges = True
                      temp = alist[i]
                      alist[i] = alist[i+1]
                      alist[i+1] = temp
              passnum = passnum-1

       alist=[20,30,40,90,50,60,70,80,100,110]
       shortBubbleSort(alist)
       print(alist)


.. Finally, here is ``shortBubbleSort`` in CodeLens (CodeLens 2)..
..
.. .. codelens:: shortbubbletrace
..     :caption: Tracing the Short Bubble Sort
..
..     def shortBubbleSort(alist):
..         exchanges = True
..         passnum = len(alist)-1
..         while passnum > 0 and exchanges:
..            exchanges = False
..            for i in range(passnum):
..                if alist[i]>alist[i+1]:
..                    exchanges = True
..                    temp = alist[i]
..                    alist[i] = alist[i+1]
..                    alist[i+1] = temp
..            passnum = passnum-1
..
..     alist=[20,30,40,90,50,60,70,80,100,110]
..     shortBubbleSort(alist)
..     print(alist)

.. admonition:: Self Check

   .. mchoice:: question_sort_1
       :correct: b
       :answer_a: [1, 9, 19, 7, 3, 10, 13, 15, 8, 12]
       :answer_b: [1, 3, 7, 9, 10, 8, 12, 13, 15, 19]
       :answer_c: [1, 7, 3, 9, 10, 13, 8, 12, 15, 19]
       :answer_d: [1, 9, 19, 7, 3, 10, 13, 15, 8, 12]
       :feedback_a:  This answer represents three swaps.  A pass means that you continue swapping all the way to the end of the list.
       :feedback_b:  Very Good
       :feedback_c: A bubble sort contines to swap numbers up to index position passnum.  But remember that passnum starts at the length of the list - 1.
       :feedback_d: You have been doing an insertion sort, not a bubble sort.

       Suppose you have the following array of numbers to sort:
       [19, 1, 9, 7, 3, 10, 13, 15, 8, 12] which array represents the partially sorted list after three complete passes of bubble sort?
