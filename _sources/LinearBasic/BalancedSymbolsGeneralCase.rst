..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Balanced Symbols - A General Case
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The balanced parentheses problem shown above is a specific case of a
more general situation that arises in many programming languages. The
general problem of balancing and nesting different kinds of opening and
closing symbols occurs frequently. For example, in Python
square brackets, ``[`` and ``]``, are used for lists; curly braces, ``{`` and ``}``, are
used for dictionaries; and parentheses, ``(`` and ``)``, are used for tuples and
arithmetic expressions. .. include:: file C++, square brackets, ``[`` and ``]``, are used for arrays and vectors,
brackets ``{`` and ``}`` separate possibly nested blocks of code,
and operations are given inside of possibly nested parentheses ``(`` and ``)``.
It is possible to mix symbols as long as each
maintains its own open and close relationship. Strings of symbols such
as

::

    { { ( [ ] [ ] ) } ( ) }

    [ [ { { ( ( ) ) } } ] ]

    [ ] [ ] [ ] ( ) { }

are properly balanced in that not only does each opening symbol have a
corresponding closing symbol, but the types of symbols match as well.

Compare those with the following strings that are not balanced:

::

    ( [ ) ]

    ( ( ( ) ] ) )

    [ { ( ) ]

The simple parentheses checker from the previous section can easily be
extended to handle these new types of symbols. Recall that each opening
symbol is simply pushed on the stack to wait for the matching closing
symbol to appear later in the sequence. When a closing symbol does
appear, the only difference is that we must check to be sure that it
correctly matches the type of the opening symbol on top of the stack. If
the two symbols do not match, the string is not balanced. Once again, if
the entire string is processed and nothing is left on the stack, the
string is correctly balanced.

Implementations of this are shown in :ref:`ActiveCode 1 <lst_parcheck2>`.
The key C++ feature appears in line 16 where we call a helper function, ``matches``, to
assist with symbol-matching. Each symbol that is removed from the stack
must be checked to see that it matches the current closing symbol. If a
mismatch occurs, the Boolean variable ``balanced`` is set to ``false``.

.. _lst_parcheck2:

.. tabbed:: parcheck2

  .. tab:: C++

    .. activecode:: parcheck2_cpp
      :caption: Solving the General Balanced Symbol Problem
      :language: cpp

      //program that returns whether a string is balanced or not
        #include <iostream>
        #include <string>
        #include <stack>

        using namespace std;
        //checks if a symbol is in the string of "{[("
        bool inString(string symbol, string symbols){
            return symbols.find(symbol) != string::npos;
        }
        //function that returns a boolean value based on whether the strings match
        bool matches(string open, string close){
            string opens = "({[";
            string closers = ")]}";
            bool val = inString(open, opens) == inString(close, closers);
            return val;
        }

        bool parChecker(string symbolString){
            stack<string> s;
            bool balanced = true;
            int index = 0;  
            int symbolLength = symbolString.length();

            while(index < symbolLength && balanced){
                string symbol;
                symbol = symbolString[index];
                string opens = "([{";
                string closes = "}])";
                if (inString(symbol, opens)){
                    s.push(symbol);
                } else if(inString(symbol, closes)){
                    if (s.empty()){
                        balanced = false;
                    } else {
                        string top = s.top();
                        s.pop();
                        if (!matches(top, symbol)){
                            balanced = false;
                            break;
                        }
                    }
                }
                index = index + 1;
            }
            if(balanced && s.empty()){
                return true;
            } else {
                return false;
            }
        }

        int main() {
            cout << parChecker("{}") << endl;
            cout << parChecker("[{()}]") << endl;
            return 0;
        }



  .. tab:: Python

    .. activecode:: parcheck2_py
       :caption: Solving the General Balanced Symbol Problem

       #Program does the same as before, except with 2 extra symbols.

       from pythonds.basic.stack import Stack

       def parChecker(symbolString):
           s = Stack()
           balanced = True
           index = 0
           while index < len(symbolString) and balanced:
               symbol = symbolString[index]
               if symbol in "([{": #if the current symbol ==
				   #an open symbol.
                   s.push(symbol)
               else:
                   if s.isEmpty(): #if there is a closed symbol
				   #but no open symbol is pending.
                       balanced = False
                   else:
                       top = s.pop()
                       if not matches(top,symbol): #if the current closed symbol
						   #is a different type than the
   						   #pending open one.
                              balanced = False
               index = index + 1
           if balanced and s.isEmpty(): #if the string is completely analyzed with
				        #no remaining open symbols.
               return True
           else:
               return False

       def matches(open,close):
	   #Checks if the type of an open and closed symbol are the same.
           opens = "([{"
           closers = ")]}"
           return opens.index(open) == closers.index(close)

       def main():
           print(parChecker('{{([][])}()}'))
           print(parChecker('[{()]'))
       main()

.. clickablearea:: stackclick
    :question: Using the program above, click on the line of code that adds an open parentheses to the stack.
    :iscode:
    :feedback: Remember that the function to do this would be the push function.

    :click-incorrect:bool parChecker(string symbolString){:endclick:
          :click-incorrect:stack<string> s;:endclick:
          :click-incorrect:bool balanced = true;:endclick:
          :click-incorrect:int index = 0;:endclick:
          :click-incorrect:int symbolLength = symbolString.length();:endclick:

          while(index < symbolLength && balanced){
              :click-incorrect:string symbol;:endclick:
              :click-incorrect:symbol = symbolString[index];:endclick:
              :click-incorrect:string opens = "({[";:endclick:
              :click-incorrect:if (inString(symbol, opens)){:endclick:
                  :click-correct:s.push(symbol);:endclick:
              } else {
                  if (s.empty()){
                      :click-incorrect:balanced = false;:endclick:
                  } else {
                      :click-incorrect:string top = s.top();:endclick:
                      :click-incorrect:s.pop();:endclick:
                      :click-incorrect:if (!matches(top, symbol)){:endclick:
                          :click-incorrect:balanced = false;:endclick:
                      }
                  }
              }
              :click-incorrect:index = index + 1;:endclick:
          }
          :click-incorrect:if(balanced && s.empty()){:endclick:
              :click-incorrect:return true;:endclick:
          } else {
              :click-incorrect:return false;:endclick:
          }
    }


These two examples show that stacks are very important data structures
for the processing of language constructs in computer science. Almost
any notation you can think of has some type of nested symbols that must
be matched in a balanced order. A number of other important
uses for stacks exist in computer science. We will continue to explore them
in the next sections.
