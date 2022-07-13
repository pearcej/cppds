..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Programming Exercises
---------------------

#. Modify the infix-to-postfix algorithm so that it can handle errors.

#. Modify the postfix evaluation algorithm so that it can handle errors.

#. Implement a direct infix evaluator that combines the functionality of
   infix-to-postfix conversion and the postfix evaluation algorithm.
   Your evaluator should process infix tokens from left to right and use
   two stacks, one for operators and one for operands, to perform the
   evaluation.

#. Turn your direct infix evaluator from the previous problem into a
   calculator.

#. Implement the ``Queue`` ADT, using a vector such that the rear of the
   queue is at the end of the vector.

#. Design and implement an experiment to do benchmark comparisons of the
   two queue implementations. What can you learn from such an
   experiment?

#. It is possible to implement a queue such that both enqueue and
   dequeue have :math:`O(1)` performance *on average*. In this case it
   means that most of the time enqueue and dequeue will be
   :math:`O(1)` except in one particular circumstance where dequeue
   will be :math:`O(n)`.

#. Consider a real life situation. Formulate a question and then design
   a simulation that can help to answer it. Possible situations include:

   -  Cars lined up at a car wash

   -  Customers at a grocery store check-out

   -  Airplanes taking off and landing on a runway

   -  A bank teller

   Be sure to state any assumptions that you make and provide any
   probabilistic data that must be considered as part of the scenario.

#. Modify the Hot Potato simulation to allow for a randomly chosen
   counting value so that each pass is not predictable from the previous
   one.

#. Implement a radix sorting machine. A radix sort for base 10 integers
   is a mechanical sorting technique that utilizes a collection of bins,
   one main bin and 10 digit bins. Each bin acts like a queue and
   maintains its values in the order that they arrive. The algorithm
   begins by placing each number in the main bin. Then it considers each
   value digit by digit. The first value is removed and placed in a
   digit bin corresponding to the digit being considered. For example,
   if the ones digit is being considered, 534 is placed in digit bin 4
   and 667 is placed in digit bin 7. Once all the values are placed in
   the corresponding digit bins, the values are collected from bin 0 to
   bin 9 and placed back in the main bin. The process continues with the
   tens digit, the hundreds, and so on. After the last digit is
   processed, the main bin contains the values in order.

#. Another example of the parentheses matching problem comes from
   hypertext markup language (HTML). In HTML, tags exist in both opening
   and closing forms and must be balanced to properly describe a web
   document. This very simple HTML document:

   ::

       <html>
          <head>
             <title>
                Example
             </title>
          </head>

          <body>
             <h1>Hello, world</h1>
          </body>
       </html>

   is intended only to show the matching and nesting structure for tags
   in the language. Write a program that can check an HTML document for
   proper opening and closing tags.

#. Extend the program from Listing 2.15 to handle palindromes with
   spaces. For example, I PREFER PI is a palindrome that reads the same
   forward and backward if you ignore the blank characters.
