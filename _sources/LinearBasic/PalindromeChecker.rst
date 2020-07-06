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

      //program that detects palindromes.

      #include <deque>
      #include <iostream>
      #include <string>

      using namespace std;

      bool palchecker(string aString) {
          deque<char> chardeque;
          int strLen = aString.length();
          for (int i = 0; i < strLen; i++) {
	      //pushes each char in the string to the deque.
              chardeque.push_back(aString[i]);
          }

          bool stillEqual = true;

          while (chardeque.size() > 1 && stillEqual) {
              char first = chardeque.front();
              chardeque.pop_front();
              char last = chardeque.back();
              chardeque.pop_back();
              if (first != last) { //if the two opposite positions of the
				   //word is not the same, then it is not
				   //a palindrome.
                  stillEqual = false;
              }
          }
          return stillEqual;
      }

      int main() {
          cout << palchecker("lsdkjfskf") << endl;
          cout << palchecker("radar") << endl;
      }


  .. tab:: Python

    .. activecode:: palchecker
       :caption: A Palindrome Checker Using Deque
       :optional:

       #Program that detects palindromes.

       from pythonds.basic.deque import Deque

       def palchecker(aString):
           chardeque = Deque()

           for ch in aString:
	       #pushes each char in the string to the deque.
               chardeque.addRear(ch)

           stillEqual = True

           while chardeque.size() > 1 and stillEqual:
               first = chardeque.removeFront()
               last = chardeque.removeRear()
               if first != last: #if the two opposite positions of the
				 #word is not the same, then it is not
				 #a palindrome.
                   stillEqual = False

           return stillEqual

       def main():
           print(palchecker("lsdkjfskf"))
           print(palchecker("radar"))
       main()



Below we can see an upgraded code for checking palindromes, which
is able to handle strings with capital letters, spaces, and special
characters.

:ref:`ActiveCode 2 <advanced_palinedrome_cpp>`.

.. _lst_andrejsind:

  .. tabbed:: pd1

    .. tab:: C++

      .. activecode:: advanced_palinedrome_cpp
        :caption: A palindrome checker that handles complicated text
        :language: cpp

        //program that detects palindromes.

        /*
        The Advanced Palindrome Checker
        By: David Reynoso and David Andrejšín
        */

        using namespace std;
        #include <deque>
        #include <fstream> // for file handling
        #include <iostream>
        #include <string>
        #include "stdlib.h" // for the system command
        #include <algorithm> // provides an algorithm for easier removal of characters from a string

        string processor(string aString) {
	    // goes through string and finds uppercase letters and converts
            // them to lower case, also finds special characters and gets rid of them
	    // ultimately, prepares a string for a correct palindrome evaluation
	    int strLen = aString.length();
	    string str = "";
	    for (int i = 0; i < strLen; i++) {
                str += tolower(aString[i]);
	    }
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
	    str.erase(remove(str.begin(), str.end(), '.'), str.end());
	    str.erase(remove(str.begin(), str.end(), '?'), str.end());
	    str.erase(remove(str.begin(), str.end(), '!'), str.end());
            str.erase(remove(str.begin(), str.end(), ','), str.end());
            str.erase(remove(str.begin(), str.end(), ';'), str.end());
            str.erase(remove(str.begin(), str.end(), ':'), str.end());
            str.erase(remove(str.begin(), str.end(), '#'), str.end());
            str.erase(remove(str.begin(), str.end(), '"'), str.end());
            str.erase(remove(str.begin(), str.end(), '\''), str.end());
            // we had to use a backslash to espace the function of '
            str.erase(remove(str.begin(), str.end(), '’'), str.end());
            str.erase(remove(str.begin(), str.end(), '“'), str.end());
            str.erase(remove(str.begin(), str.end(), '”'), str.end());
            str.erase(remove(str.begin(), str.end(), '-'), str.end());
            str.erase(remove(str.begin(), str.end(), '('), str.end());
            str.erase(remove(str.begin(), str.end(), ')'), str.end());

            return str;
        }

        bool palchecker(string aString) {
            // an algorithm that checks whether a string is a palindrome
            aString = processor(aString); // calls a function that prepares the string for a proper evaluation of the palindrome

            deque<char> chardeque;
            int strLen = aString.length();
            for (int i = 0; i < strLen; i++) {
            //pushes each char in the string to the deque.
                chardeque.push_back(aString[i]);
            }

            bool stillEqual = true;

            while (chardeque.size() > 1 && stillEqual) {
                char first = chardeque.front();
                chardeque.pop_front();
                char last = chardeque.back();
                chardeque.pop_back();
                if (first != last) { //if the two opposite positions of the
                     //word is not the same, then it is not
                     //a palindrome.
                    stillEqual = false;
                }
            }
            return stillEqual;
        }

        int main() {
            cout << palchecker("Do geese, see God?!") << endl;
            cout << palchecker("Radar") << endl;
            cout << palchecker("Are we not pure? “No sir!” Panama’s moody Noriega brags. “It is garbage!” Irony dooms a man; a prisoner up to new era.") << endl;
            cout << palchecker("Barge in! Relate mere war of 1991 for a were-metal Ernie grab!") << endl;
            cout << palchecker("not a palindrome") << endl;
        }


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

.. mchoice:: structureefficiency
   :answer_a: Deque
   :answer_b: Stack
   :answer_c: Queue
   :answer_d: Both B & C
   :answer_e: Both A & C
   :correct: e
   :feedback_a: Yes, but it is not the only option.
   :feedback_b: No, a stack would pop from the top, thus having more entries in the way before it gets to rutabega.
   :feedback_c: Yes, but it is not the only option.
   :feedback_d: One of these two would be correct, but the other would not.
   :feedback_e: Correct!

   If you add five items to your code in this order “potato”, “rutabaga”, “avocado”, “squash”, “eggplant” which structure would take the least steps to retrieve “rutabaga”?
