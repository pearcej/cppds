..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Discussion Questions
--------------------

#. Convert the following values to binary using “divide by 2.” Show the
   stack of remainders.

   -  17

   -  45

   -  96

#. Convert the following infix expressions to prefix (use full
   parentheses):

   -  (A+B)\*(C+D)\*(E+F)

   -  A+((B+C)\*(D+E))

   -  A\*B\*C\*D+E+F

#. Convert the above infix expressions to postfix (use full
   parentheses).

#. Convert the above infix expressions to postfix using the direct
   conversion algorithm. Show the stack as the conversion takes place.

#. Evaluate the following postfix expressions. Show the stack as each
   operand and operator is processed.

   -  2 3 \* 4 +

   -  1 2 + 3 + 4 + 5 +

   -  1 2 3 4 5 \* + \* +

#. The alternative implementation of the ``Queue`` ADT is to use a vector
   such that the rear of the queue is at the end of the vector. What would
   this mean for Big-O performance?
