.. .  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Glossary
--------

.. glossary::

    bubble sort
        sorting method that makes multiple passes through a collection, comparing
        adjacent items, and swaps items that are out of order

    gap
        an increment used to divide a collection into subsets without breaking
        apart the collection during a shell sort

    insertion sort
        sorting method that maintains a sorted and unsorted subset of a
        collection and inserts elements from the unsorted subset into the sorted
        subset

    median of three
        method of choosing the pivot value for a quick sort by taking the median
        of the first, middle, and last element of a collection

    merge
        part of merge sort that takes two smaller sorted subsets and combines
        them

    merge sort
        sorting method that uses recursion to split a collection in half until
        there is one item and then combines the smaller subsets back into larger
        sorted subsets

    partition
        process of quick sort that that finds the split point and moves items to
        the appropriate side of the collection, either less than or greater than
        the pivot value

    pivot value
        value selected in a collection during quick sort in order to split a
        collection

    selection sort
        sorting method that makes multiple passes through a collection, taking
        the largest (ascending) or smallest (descending) unsorted element and
        places it into its correct place by swapping places with the next largest
        or lowest element

    shell sort
        sorting method that divides the collection into subsets, sorts the subsets
        individually using insertion sort, then also sorts the combination of the
        sorted subsets using insertion sort

    short bubble
        a modified bubble sort that stops if there are no exchanges to do

    sorting
        the process of placing elements from a collection in some kind of order

    split point
        the position of the pivot value in the sorted collection; used to divide
        the collection for subsequent calls to quick sort

    quick sort
        sorting method that uses recursion to split a collection in half (without
        using extra space) and places elements on the proper side of the split
        point

Matching
--------


.. dragndrop:: matching_sort
    :feedback: Review classes and their properties
    :match_1: bubble sort|||Makes multiple passes through a collection, comparing adjacent items, and swaps items that are out of order
    :match_2: gap|||Used to divide a collection into subsets without breaking apart the collection during a shell sort
    :match_3: insertion sort|||Maintains a sorted and unsorted subset of a collection and inserts elements from the unsorted subset into the sorted subset
    :match_4: median of three|||Method of choosing the pivot value for a quick sort by taking the median of the first, middle, and last element of a collection
    :match_5: merge|||Takes two smaller sorted subsets and combines them
    :match_6: merge sort|||Uses recursion to split a collection in half until there is one item and then combines the smaller subsets back into larger sorted subsets
    :match_7: partition|||Finds the split point and moves items to the appropriate side of the collection, either less than or greater than the pivot value 
    :match_8: pivot value|||Value selected in a collection during quick sort in order to split a collection
    :match_9: selection sort|||Makes multiple passes through a collection, taking the largest or lowest unsorted element and places it into its correct place by swapping places with the next largest or lowest element
    :match_10: short bubble|||Stops if there are no exchanges to do
    :match_11: shell sort|||Divides the collection into subsets, sorts the subsets individually using insertion sort, then also sorts the combination of the sorted subsets using insertion sort
    :match_12: sorting|||Process of placing elements from a collection in some kind of order
    :match_13: split point|||Position of the pivot value in the sorted collection; used to divide the collection for subsequent calls to quick sort
    :match_14: quick sort|||Uses recursion to split a collection in half and places elements on the proper side of the split point
   

    Drag the word on the left to its corresponding definition