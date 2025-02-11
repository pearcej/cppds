..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


An Anagram Detection Example
----------------------------

A good example problem for showing algorithms with different orders of
magnitude is the classic anagram detection problem for strings. One
string is an anagram of another if the second is simply a rearrangement
of the first. For example, ``"heart"`` and ``"earth"`` are anagrams. The
strings ``"python"`` and ``"typhon"`` are anagrams as well. For the sake
of simplicity, we will assume that the two strings in question are of
equal length and that they are made up of symbols from the set of 26
lowercase alphabetic characters. Our goal is to write a Boolean function
that will take two strings and return whether they are anagrams.

Solution 1: Checking Off
^^^^^^^^^^^^^^^^^^^^^^^^

Our first solution to the anagram problem will check the lengths of the
strings and then to see that each character in the first string actually
occurs in the second. If it is possible to “checkoff” each character, then
the two strings must be anagrams. Checking off a character will be
accomplished by replacing it with the special C++ character ``\0``.
The first step in the
process will be to convert the second string to a local second string
for checking off.
Each character
from the first string can be checked against the characters in the local second string
and if found, checked off by replacement. :ref:`ActiveCode 1 <lst_anagramSolution>` shows this function.

.. _lst_anagramSolution:

.. tabbed:: ec5

  .. tab:: C++

    .. activecode:: active0cpp
        :caption: Checking Off C++
        :language: cpp

        #include <iostream>
        #include <string>
        using namespace std;

        //checks to see if the anagrams have the same number of characters

        bool anagramsolution1(string s1, string s2){
            bool stillOK = true;
            if (s1.length() != s2.length()) {
                stillOK = false;
                return stillOK;
            }
            string locals2 = s2;
            int n = s1.length();
            unsigned int pos1 = 0;

            // checks to see if all of the letters are the same in both inputs 

            while (pos1 < s1.length() && stillOK){
                int pos2 = 0;
                bool found = false;
                while (pos2 < n && !found){
                    if (s1[pos1] == locals2[pos2]){
                        found = true;
                    } else{
                        pos2 = pos2 + 1;
                    }
                }
                if (found){
                    locals2[pos2] = '\0';
                }
                else{
                    stillOK = false;
                }
                pos1 = pos1 + 1;
            }
            return stillOK;
        }

        int main(){
            bool value = anagramsolution1("abcd", "dcab");
            cout << value << endl;
            return 0;
        }

  .. tab:: Python

    .. activecode:: active0py
        :caption: Checking Off Python
        :optional:

        #checks to see if the anagrams have the same number of characters

        def anagramSolution1(s1,s2):
            stillOK = True
            if len(s1) != len(s2):
                stillOK = False
                return stillOK

            lists2 = list(s2)
            pos1 = 0

            # checks to see if all of the letters are the same in both inputs 
            while pos1 < len(s1) and stillOK:
                pos2 = 0
                found = False
                while pos2 < len(lists2) and not found:
                    if s1[pos1] == lists2[pos2]:
                        found = True
                    else:
                        pos2 = pos2 + 1

                if found:
                    lists2[pos2] = None
                else:
                    stillOK = False

                pos1 = pos1 + 1

            return stillOK

        def main():
            print(anagramSolution1('abcd','dcba'))
        main()

To analyze this algorithm, we need to note that each of the *n*
characters in ``s1`` will cause an iteration through up to *n*
characters in the array from ``s2``. Each of the *n* positions in the
array will be visited once to match a character from ``s1``. The number
of visits then becomes the sum of the integers from 1 to *n*. We stated
earlier that this can be written as

.. math::

   \sum_{i=1}^{n} i &= \frac {n(n+1)}{2} \\
                    &= \frac {1}{2}n^{2} + \frac {1}{2}n

As :math:`n` gets large, the :math:`n^{2}` term will dominate the
:math:`n` term and the :math:`\frac {1}{2}` can be ignored.
Therefore, this solution is :math:`O(n^{2})`.

Solution 2: Sort and Compare
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Another solution to the anagram problem will make use of the fact that
even though ``s1`` and ``s2`` are different, they are anagrams only if
they consist of exactly the same characters. So, if we begin by sorting
each string alphabetically, from a to z, we will end up with the same
string if the original two strings are anagrams. :ref:`ActiveCode 2 <lst_ana2>` shows
this solution.

.. _lst_ana2:

.. tabbed:: ec6

  .. tab:: C++

    .. activecode:: active6cpp
        :caption: Sort and Compare C++
        :language: cpp

        #include <iostream>
        #include <string>
        #include <algorithm>
        using namespace std;

        // sorts anagrams in order from a-z, and then compares them 
        bool anagramsolution2(string s1, string s2){
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            unsigned int pos = 0;
            bool matches = true;

            while (pos < s1.length() && matches){
                if (s1[pos] == s2[pos]){
                    pos = pos + 1;
                } else{
                    matches = false;
                }
            }
            return matches;
        }

        int main(){
            bool value = anagramsolution2("abcde", "edcba");
            cout << value << endl;
            return 0;
        }

  .. tab:: Python

    .. activecode:: active6py
        :caption: Sort and Compare
        :optional:

        # sorts anagrams in order from a-z, and then compares them
        def anagramSolution2(s1,s2):
            alist1 = list(s1)
            alist2 = list(s2)

            alist1.sort()
            alist2.sort()

            pos = 0
            matches = True

            while pos < len(s1) and matches:
                if alist1[pos]==alist2[pos]:
                    pos = pos + 1
                else:
                    matches = False

            return matches

        def main():
            print(anagramSolution2('abcde','edcba'))
        main()

At first glance you may be tempted to think that this algorithm is
:math:`O(n)`, since there are three consecutive simple iterations:
the first two to convert strings to char arrays and the last
to compare the *n*
characters after the sorting process. However, the two calls to the
C++ ``sort`` function are not without their own cost. As we will see in
a later chapter, sorting is typically either :math:`O(n^{2})` or
:math:`O(n\log n)`, so the sorting operations dominate the iteration.
In the end, this algorithm will have the same order of magnitude as that
of the sorting process.

Solution 3: Brute Force
^^^^^^^^^^^^^^^^^^^^^^^

A **brute force** technique for solving a problem typically tries to
exhaust all possibilities. For the anagram detection problem, we can
simply generate an array of all possible strings using the characters from
``s1`` and then see if ``s2`` occurs. However, there is a difficulty
with this approach. When generating all possible strings from ``s1``,
there are *n* possible first characters, :math:`n-1` possible
characters for the second position, :math:`n-2` for the third, and so
on. The total number of candidate strings is
:math:`n*(n-1)*(n-2)*...*3*2*1`, which is :math:`n!`. Although some
of the strings may be duplicates, the program cannot know this ahead of
time and so it will still generate :math:`n!` different strings.

It turns out that :math:`n!` grows even faster than :math:`2^{n}` as
*n* gets large. In fact, if ``s1`` were 20 characters long, there would
be :math:`20!=2,432,902,008,176,640,000` possible candidate strings.
If we processed one possibility every second, it would take us
77,146,816,596 years to go through the entire array. This is probably not
going to be a good solution.

Solution 4: Count and Compare
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Our final solution to the anagram problem takes advantage of the fact
that any two anagrams will have the same number of a’s, the same number
of b’s, the same number of c’s, and so on. In order to decide whether
two strings are anagrams, we will first count the number of times each
character occurs. Since there are 26 possible characters, we can use an array
of 26 counters, one for each possible character. Each time we see a
particular character, we will increment the counter at that position. In
the end, if the two arrays of counters are identical, the strings must be
anagrams. :ref:`ActiveCode 3 <lst_ana4>` shows this solution.

.. _lst_ana4:

.. tabbed:: Count_and_Compare

  .. tab:: C++

    .. activecode:: active7cpp
        :caption: Count and Compare C++
        :language: cpp

        #include <iostream>
        #include <string>
        using namespace std;

        // uses an array to count the number of a ocurrences of the two inputs 
        // if the number of occurrences is the same then the input is an anagram

        bool anagramSolution4(string s1, string s2){
            int c1[26] = {0};
            int c2[26] = {0};

            for (unsigned int i = 0; i &lt; s1.length(); i++){
                int pos = s1[i] - 'a';
                c1[pos] += 1;
            }

            for (unsigned int i = 0; i &lt; s2.length(); i++){
                int pos = s2[i] - 'a';
                c2[pos] += 1;
            }

            for (unsigned int i = 0; i &lt; 26; i++) {
                if (c1[i] != c2[i]){
                    return false;
                }
            }

            return true;
        }

        int main(){
            bool value = anagramSolution4("apple", "pleap");
            cout << value << endl;
            return 0;
        }

  .. tab:: Python

    .. activecode:: active7py
        :caption: Count and Compare Python
        :optional:

        """ uses an array to count the number of a ocurrences of the two inputs 
        if the number of occurrences is the same then the input is an anagram """ 
        
        def anagramSolution4(s1,s2):
           c1 = [0]*26
           c2 = [0]*26

           for i in range(len(s1)):
               pos = ord(s1[i])-ord('a')
               c1[pos] += 1

           for i in range(len(s2)):
               pos = ord(s2[i])-ord('a')
               c2[pos] += 1

           for i in range(len(c1)):
               if c1[i] != c2[i]:
                   return False

           return True

        def main():
            print(anagramSolution4('apple','pleap'))
        main()

Again, the solution has a number of iterations. However, unlike the
first solution, none of them are nested. The first two iterations used
to count the characters are both based on *n*. The third iteration,
comparing the two arrays of counts, always takes 26 steps since there are
26 possible characters in the strings. Adding it all up gives us
:math:`T(n)=2n+26` steps. That is :math:`O(n)`. We have found a
linear order of magnitude algorithm for solving this problem.

Before leaving this example, we need to say something about space
requirements. Although the last solution was able to run in linear time,
it could only do so by using additional storage to keep the two arrays of
character counts. In other words, this algorithm sacrificed space in
order to gain time.

This is a common occurrence. On many occasions you will need to make
decisions between time and space trade-offs. In this case, the amount of
extra space is not significant. However, if the underlying alphabet had
millions of characters, there would be more concern. As a computer
scientist, when given a choice of algorithms, it will be up to you to
determine the best use of computing resources given a particular
problem.

.. admonition:: Self Check

   .. mchoice:: analysis_1
       :answer_a: O(n)
       :answer_b: O(n<sup>2</sup>)
       :answer_c: O(log n)
       :answer_d: O(n<sup>3</sup>)
       :correct: b
       :feedback_a: No. In an example like this you want to count the nested loops, especially the loops that are dependent on the same variable, in this case, n.
       :feedback_b: Right! A nested loop like this is O(n<sup>2</sup>).
       :feedback_c: No. log n typically is indicated when the problem is iteratively made smaller
       :feedback_d: No. In an example like this you want to count the nested loops. especially the loops that are dependent on the same variable, in this case, n.

       Given the following code fragment, what is its Big-O running time?

       .. code-block:: cpp

         int main(){
             int test = 0;
             for (int i = 0; i < n; i++){
                 for (int j = 0; j < n; j++){
                     test = test + i * j;
                 }
             }
             return 0;
         }

   .. mchoice:: analysis_2
       :answer_a: O(n)
       :answer_b: O(n<sup>2</sup>)
       :answer_c: O(log n)
       :answer_d: O(n<sup>3</sup>)
       :correct: a
       :feedback_a: Right! Even though there are two loops they are not nested.  You might think of this as O(2n) but we can ignore the constant 2.
       :feedback_b: No. Be careful, in counting loops you want to look carefully at whether or not the loops are nested.
       :feedback_c: No. log n typically is indicated when the problem is iteratively made smaller.
       :feedback_d: No. Be careful, in counting loops you want to look carefully at whether or not the loops are nested.

       Given the following code fragment what is its Big-O running time?

       .. code-block:: cpp

         int main(){
             int test = 0;
             for (int i = 0; i < n; i++){
                 test = test + 1;
             }
             for (int j = 0; j < n; j++){
                 test = test - 1;
             }
             return 0;
         }

   .. mchoice:: analysis_3
       :answer_a: O(n)
       :answer_b: O(n<sup>2</sup>)
       :answer_c: O(log n)
       :answer_d: O(n<sup>3</sup>)
       :correct: c
       :feedback_a: No. Look carefully at the loop variable i.  Notice that the value of i is cut in half each time through the loop.  This is a big hint that the performance is better than O(n)
       :feedback_b: No. Check again, is this a nested loop?
       :feedback_c: Right! The value of i is cut in half each time through the loop so it will only take log n iterations.
       :feedback_d: No. Check again, is this a nested loop?

       Given the following code fragment what is its Big-O running time?

       .. code-block:: cpp

         int main(){
             int i = n;
             int count = 0;
             while (i > 0){
                 count = count + 1;
                 i = i // 2;
             }
             return 0;
         }

   .. fillintheblank:: fill1512

       If an algorithm performing at :math:`O(n^{2})` has the integer 8 as input, what is the worst case scenario for the algorithm?

       - :64: Correct!
         :16: That would be 2n, which would be simplified as n.
         :8: That would be n.
         :.*: Wrong, Try again!

