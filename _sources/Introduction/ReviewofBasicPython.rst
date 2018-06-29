..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Review of Basic C++
----------------------

In this section, we will review the programming language C++ and also
provide some more detailed examples of the ideas from the previous
section. If you are new to C++ or find that you need more information
about any of the topics presented, we recommend that you consult a resource such as
the `C++ Reference <http://www.cplusplus.com/reference/>`_
or a `C++ Tutorial <http://www.cplusplus.com/doc/tutorial/>`_.
Our goal
here is to reacquaint you with the language and also reinforce some of
the concepts that will be central to later chapters.

C++ is an object-oriented programming language.
It has a powerful set of built-in data types and control
constructs. Since C++ is a compiled language, all the codes written in this language,
when run, are translated to machine code by a program called compiler. Following is
one example of C++ code that writes to console:

.. activecode:: cpp
  :caption: Title for the C++ Window
  :language: cpp

  #include <iostream>
  using namespace std;

  int main() {
      cout << "Algorithms and Data Structures!";
  }
