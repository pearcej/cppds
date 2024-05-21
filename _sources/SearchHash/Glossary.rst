.. .  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Glossary
--------

.. glossary::

    binary search
        search method in which one repeatedly divides a sorted data structure in
        half and determines if the item is in one half of it until the item is
        found or deemed not in the data.

    chaining
        a method of collision resolution in which each slot in a hash table holds
        a reference to a collection of items

    collision
        a conflict of having two or more items sharing the same slot in a hash
        table

    collision resolution
        a systematic method for resolving hash table collisions

    clustering
        items being mapped in a hash table near each other because of collisions
        and linear probing resulting in items with collisions being put together

    folding method
        a method for constructing a hash function by dividing the item into
        equally sized pieces and then adding the pieces together to get a hash
        value. The value is then divided by the size of the hash table and the
        remainder becomes the slot for that item.

    hashing
        generating a value given an input that can be used to find the input
        by searching for the value.

    hash function
        the mapping between an item and its slot in a hash table

    hash table
        a collection of items which are stored in such a away as to make it easy
        to find them

    linear probing
        an open addressing technique in which each slot is visited one at a time
        systematically

    load factor
        Represents how full a hash table is. Its the number of items in a hash
        table divided by the size of the table.

    map
        an associate data type that stores key-data pairs

    mid-square method
          a method for constructing a hash function by squaring the item and
          then using some portion of the result.

    open addressing
        a collision resolution that tries to find the next open slot/address in
        the hash table

    perfect hash function
        a hash function that maps each item to a unique hash slot

    quadratic probing
        a variation of linear probing in which rehashing is done using successive
        squared values

    rehashing
        putting an item into a hash table after a collision

    searching
        the algorithmic process of finding a particular item in a
        collection of items

    sequential search
        search method in which one follows the underlying ordering of items in a
        collection of data to find a specific item

    slot
        a position in a hash table
