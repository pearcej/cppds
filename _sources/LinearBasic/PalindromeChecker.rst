..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Palindrome-Checker
~~~~~~~~~~~~~~~~~~

An interesting problem that can be easily solved using the deque data
structure is the classic palindrome problem. A **palindrome** is a
string that reads the same forward and backward, for example, *radar*,
*toot*, and *madam*. We would like to construct an algorithm to input a
string of characters and check whether it is a palindrome.

The solution to this problem will use a deque to store the characters of
the string. We will process the string from left to right and add each
character to the rear of the deque. At this point, the deque will be
acting very much like an ordinary queue. However, we can now make use of
the dual functionality of the deque. The front of the deque will hold
the first character of the string and the rear of the deque will hold
the last character (see :ref:`Figure 2 <fig_palindrome>`).

.. _fig_palindrome:

.. figure:: Figures/palindromesetup.png
   :align: center

   Figure 2: A Deque


Since we can remove both of them directly, we can compare them and
continue only if they match. If we can keep matching first and the last
items, we will eventually either run out of characters or be left with a
deque of size 1 depending on whether the length of the original string
was even or odd. In either case, the string must be a palindrome. The
complete function for palindrome-checking appears in
:ref:`ActiveCode 1 <palinedrome_cpp>`.

.. _lst_josephussim:

.. tabbed:: pd1

  .. tab:: C++

    .. activecode:: palinedrome_cpp
      :caption: Using a Deque to check palindromes
      :language: cpp

      #include <deque>
      #include <iostream>
      #include <string>

      using namespace std;

      bool palchecker(string aString) {
          deque<char> chardeque;
          int strLen = aString.length();
          for (int i = 0; i < strLen; i++) {
              chardeque.push_back(aString[i]);
          }

          bool stillEqual = true;

          while (chardeque.size() > 1 && stillEqual) {
              char first = chardeque.front();
              chardeque.pop_front();
              char last = chardeque.back();
              chardeque.pop_back();
              if (first != last) {
                  stillEqual = false;
              }

              return stillEqual;
          }

          return true;
      }

      int main() {
          cout << palchecker("lsdkjfskf") << endl;
          cout << palchecker("radar") << endl;
      }


  .. tab:: Python

    .. activecode:: palchecker
       :caption: A Palindrome Checker Using Deque

       from pythonds.basic.deque import Deque

       def palchecker(aString):
           chardeque = Deque()

           for ch in aString:
               chardeque.addRear(ch)

           stillEqual = True

           while chardeque.size() > 1 and stillEqual:
               first = chardeque.removeFront()
               last = chardeque.removeRear()
               if first != last:
                   stillEqual = False

           return stillEqual

       def main():
           print(palchecker("lsdkjfskf"))
           print(palchecker("radar"))
       main()


Self Check
----------


.. dragndrop:: orderingPrinciples
   :feedback: This is feedback.
   :match_1: Stack|||last-in first-out
   :match_2: Deque|||mixed depending upon input order
   :match_3: Queue|||first-in first-out

   Drag each data structure to its corresponding ordering principle


.. clickablearea:: Remembertypes
 :question: Click on the cause of a syntax error in the following code.
 :iscode:
 :feedback: Remember how we declare variables

 :click-correct:deque&lt;int&gt; d;:endclick:
 :click-incorrect:d.push_back("Zebra");:endclick:
 :click-incorrect:d.push_front("Turtle");:endclick:
 :click-incorrect:d.push_front("Panda");:endclick:
 :click-incorrect:d.push_back("Catfish");:endclick:
 :click-incorrect:d.push_back("Giraffe");:endclick:
