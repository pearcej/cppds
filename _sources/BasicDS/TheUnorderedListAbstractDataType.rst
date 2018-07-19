..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Unordered Array Abstract Data Type
--------------------------------------

The structure of an unordered array, as described above, is a collection
of items where each item holds a relative position with respect to the
others. Some possible unordered array operations are given below.

-  ``int list[100]`` creates a new list that is a size of 100, and stores elements of integer data.

-  ``front()`` accesses first element. Returns a reference to the first element in the array container.

-  ``back()`` accesses last element. Returns a reference to the last element in the array container.

-  ``empty()`` Test whether array is empty, and returns a boolean value showing whether the array is empty or not.

-  ``size()`` returns size (the number of elements) in the array.

-  ``fill(val)`` Sets *val* as the value for all the elements in the array object.


Vectors
-------

Vectors are more similar to lists in Python than arrays, in way that they have dynamic
size. Some operations with vectors are given below:
-   ``#include <vector>;`` imports the vector to be used

-   ``vector<int> integerList;`` declares integerList as a vector, and its elements to be a type of int.

-   ``vector<string> stringList;`` declares stringList as a vector, and its elements to be a type of string.

-   ``clear()`` deletes all the items in the vector.

-   ``erase(pos)`` deletes the item at a defined position.

-   ``insert(pos, elem)`` inserts the copy of *elem* into a *pos* position in the vector.

-   ``size()`` returns the size (the number of items) of the vector.

More found<a href="http://www.cplusplus.com/reference/vector/vector/" target="_blank"> here.</a>
