..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Ordered List Abstract Data Type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

We will now consider a type of list known as an ordered list. For
example, if the list of integers shown above were an ordered list
(ascending order), then it could be written as 17, 26, 31, 54, 77, and
93. Since 17 is the smallest item, it occupies the first position in the
list. Likewise, since 93 is the largest, it occupies the last position.

The structure of an ordered list is a collection of items where each
item holds a relative position that is based upon some underlying
characteristic of the item. The ordering is typically either ascending
or descending and we assume that list items have a meaningful comparison
operation that is already defined. Many of the ordered list operations
are the same as those of the unordered list.

-  ``OrderedList()`` creates a new ordered list that is empty. It needs
   no parameters and returns an empty list.

-  ``add(item)`` adds a new item to the list making sure that the order
   is preserved. It needs the item and returns nothing. Assume the item
   is not already in the list.

-  ``remove(item)`` removes the item from the list. It needs the item
   and modifies the list. Assume the item is present in the list.

-  ``search(item)`` searches for the item in the list. It needs the item
   and returns a boolean value.

-  ``isEmpty()`` tests to see whether the list is empty. It needs no
   parameters and returns a boolean value.

-  ``size()`` returns the number of items in the list. It needs no
   parameters and returns an integer.

-  ``index(item)`` returns the position of item in the list. It needs
   the item and returns the index. Assume the item is in the list.

-  ``pop()`` removes and returns the last item in the list. It needs
   nothing and returns an item. Assume the list has at least one item.

-  ``pop(pos)`` removes and returns the item at position pos. It needs
   the position and returns the item. Assume the item is in the list.

Forward lists
^^^^^^^^^^^^^

Forward lists are sequence containers in the STL that allow you to do constant time insert and delete operations.

These containers are implemented as singly-linked lists. Singly linked lists are able to store each list element in different storage locations as opposed to regular arrays which each element has to be stored next to each other. Each element holds a link to the next element in the sequence as well as the value.

The STL also has a list container which is different from the forward list container in that while a forward list holds a link to the next element in the sequence, a list holds a link to the previous element and the next element. This allows the list to have efficient iteration in both directions. However because of the additional storage space required to store the link to the previous element and the time it takes to insert and remove an element, a forward list is more efficient than a list.

For more information about lists please visit this webpage: http://www.cplusplus.com/reference/list/list/

Because of the unique property of forward lists that allows them to insert and delete elements at any position in the list in constant time, they perform better than other sequence containers like arrays and vectors when it comes to algorithms that use a lot of insertion, like sorting algorithms.

Unlike sequence containers like arrays and vectors where each element in the list is right next to each other, forward lists use links that connect one element to another. For this reason you cannot directly access an element in a forward list without iterating through each element that comes before that element.
