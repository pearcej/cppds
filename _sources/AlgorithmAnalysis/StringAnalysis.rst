..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Analysis of String Operators
----------------------------

Prior to C++11 the string class was not required to store its
character elements contiguously. Now string acts much like the vector class, except
for some string optimizations and other minor differences.

Since C++11 strings use contiguous storage locations
in an underlying (typically larger) array just like vectors do.
The character elements in strings can be accessed and
traversed with the help of iterators, and they
can also be accessed randomly using indexes.

Like vectors, strings have a dynamic size meaning that whenever
a new characters is inserted or deleted,
their size changes automatically.
Just like vectors, new element can be inserted into or deleted from any part of a string,
and automatic reallocation for other existing items in the string is applied.

Indexing and assigning a new character to an index position
that already exists both take :math:`O(1)`, the same amount of time no matter how
large the string is.

Now that we have seen how performance can be measured concretely you can
look at :ref:`Table 3 <tbl_strbigocpp>` to see the Big-O efficiency of all the
basic string operations and you will see a striking resemblance to vectors because
the implementations are so similar.

.. _tbl_strbigocpp:

.. table:: **Table 3: Big-O Efficiency of C++ Sting Operations**

    ===================== ==================
                Operation   Big-O Efficiency
    ===================== ==================
                 index []               O(1)
       index assignment =               O(1)
              push_back()     typically O(1)
               pop_back()               O(1)
                 erase(i)               O(n)
          insert(i, item)               O(n)
     find(srt, stp, item)   O(log n) or O(n)
                reserve()               O(1)
                  begin()               O(1)
                    end()               O(1)
                   size()               O(1)
    ========================================


Just like vectors, the `push_back()` operation is :math:`O(1)` unless there is inadequate capacity,
in which case the entire
string is moved to a larger contiguous underlying array, which
is :math:`O(n)`.

.. dragndrop:: matching_StringBO
    :feedback: Review operations and thier Big(O)
    :match_1: reserve(), begin(), end(), index [], index assignment = ,push_back(), pop_back()||| O(1) 
    :match_2: erase(i), insert(i, item),find(srt, stp, item)|||O(n)
    :match_3: find(srt, stp, item)|||O(log n)
   
    Drag the operation(s) on the left to their corresponding Big(O) (Notice the similarities to the Vectors Big(O))