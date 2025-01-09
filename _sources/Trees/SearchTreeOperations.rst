..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Search Tree Operations
----------------------

efore we look at the implementation, let's discuss the operations that
will be provided by the ``BinarySearchTree``. You should notice that
this interface is very
similar to the C++ Hash Table developed earlier.
While the operations provided by ``BinarySearchTree`` are the same
as the Hash Table, we will see that how items are stored and accessed
is very different.

-  ``BinarySearchTree()`` Create a new, empty tree.

-  ``put(key,val)`` Add a new key-value pair to the tree. If the key is
   already in the tree then replace the old value with the new value.

-  ``get(key)`` Given a key, return the value stored in the tree or
   ``NULL`` otherwise.

-  ``del(key)`` Delete the key-value pair from the tree.

-  ``length()`` Return the number of key-value pairs stored in the map.
