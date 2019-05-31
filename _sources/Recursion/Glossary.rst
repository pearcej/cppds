..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Glossary
--------

.. glossary::

    base case
        A branch of the conditional statement in a recursive function that does
        not give rise to further recursive calls.

    data structure
        An organization of data for the purpose of making it easier to use.

    dynamic programming
        a way to solve complex problems by breaking it up, solving the smaller
        portions, and storing the results to avoid re-calculating them.

    exception
        An error that occurs at runtime.

    handle an exception
        To prevent an exception from terminating a program by wrapping
        the block of code in a ``try`` / ``except`` construct.

    immutable data type
        A data type which cannot be modified.  Assignments to elements or
        slices of immutable types cause a runtime error.

    infinite recursion
        A function that calls itself recursively without ever reaching the base
        case. Eventually, an infinite recursion causes a runtime error.

    mutable data type
        A data type which can be modified. All mutable types are compound
        types.  Lists and dictionaries (see next chapter) are mutable data
        types; strings and tuples are not.

    raise
        To cause an exception by using the ``raise`` statement.

    recursion
        The process of calling the function that is already executing.

    recursive call
        The statement that calls an already executing function.  Recursion can
        even be indirect --- function `f` can call `g` which calls `h`,
        and `h` could make a call back to `f`.

    recursive definition
        A definition which defines something in terms of itself. To be useful
        it must include *base cases* which are not recursive. In this way it
        differs from a *circular definition*.  Recursive definitions often
        provide an elegant way to express complex data structures.

    stack frame
        a stack that contains a "frame" or group of data. For a call stack, this
        would be a function and its arguments.

    tuple
        A data type that contains a sequence of elements of any type, like a
        list, but is immutable. Tuples can be used wherever an immutable type
        is required, such as a key in a dictionary (see next chapter).

    tuple assignment
        An assignment to all of the elements in a tuple using a single
        assignment statement. Tuple assignment occurs in parallel rather than
        in sequence, making it useful for swapping values.

Matching
--------


.. dragndrop:: Match_chap3
    :feedback: Incorrect
    :match_1: base case|||branch of the conditional statement in a recursive function that does not give rise to further recursive calls.
    :match_2: data structure|||An organization of data for the purpose of making it easier to use.
    :match_3: deque|||Ordered collection of items with two ends and the items remain positioned in the collection. New items can be added at either the front or the rear
    :match_4: first-in first-out (FIFO)|||First item added is also the first removed
    :match_5: linear data structure|||Data structure with elements that have positions relative to each other
    :match_6: palindrome|||String that reads the same forward and backward
    :match_7: postfix|||Expression notation in which all operators come after the two operands that they work on
    :match_8: precedence|||Hierarchy on the order things occur
    :match_9: prefix|||Expression notation in which all operators precede the two operands that they work on
    :match_10: queue|||Ordered collection of items where the addition of new items happens at one end and the removal of existing items occurs at the other end
    :match_11: last-in first-out (LIFO)|||Last item added is also the first removed
    :match_12: simulation|||Replica of a process or operations
    :match_13: stack|||Ordered collection of items where the addition of new items and the removal of existing items always takes place at the same end
    :match_14: fully parenthesized|||Usage of one pair of parentheses for each operator
    :match_15: infix|||Expression notation in which the operator is in between the two operands that it is working on

    Match the term with their corresponding definition 