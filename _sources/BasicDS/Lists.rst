..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Array
-----

Throughout the discussion of basic data structures, we have used C++
arrays to implement the abstract data types presented. The array is a
powerful, yet simple, collection mechanism that provides the programmer
with a wide variety of operations.

An **array** is a collection of items where each item holds a relative
position with respect to the others. More specifically, we will refer to
this type of array as an unordered array. We can consider the array as
having a first item, a second item, a third item, and so on. We can also
refer to the beginning of the array (the first item) or the end of the
array (the last item). For simplicity we will assume that arrays cannot
contain duplicate items.

For example, the collection of integers 54, 26, 93, 17, 77, and 31 might
represent a simple unordered array of exam scores. Note that we have
written them as comma-delimited values, a common way of showing the array
structure. Of course, C++ would show this array as
:math:`{54,26,93,17,77,31}`.

Vector
------

Vectors are similar to arrays in a way that they use contiguous storage locations,
which means that their elements can be accessed and traversed with the help of iterators, and they
can also be accessed randomly using indexes.

However, vectors have a dynamic size meaning that whenever a new element is inserted or deleted,
their size changes automatically. A new element can be inserted into or deleted from any part of a vector,
and automatic reallocation for other existing items in the vector is applied. Nevertheless, computing time for
insertion and deletion might differ depending on the location of the item, and how many items need to be
reallocated. For example, the last item in a vector is removed at a constant time, because no resizing of
the vector is needed for this operation, while an item is removed or inserted into the beginning or the
middle of a vector at a linear time.
