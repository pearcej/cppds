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

.. dragndrop:: matching_recur
    :feedback: incorrect 
    :match_1: base case|||branch of the conditional statement in a recursive function that does not give rise to further recursive calls.
    :match_2: data structure|||An organization of data for the purpose of making it easier to use.
    :match_3: dynamic programming|||To solve complex problems by breaking them up, solving the smaller portions, and storing the results to avoid re-calculating them.
    :match_4: exception|||An error that occurs at runtime.
    :match_5: handle an exception|||To prevent an exception from terminating a program by wrapping the block of code in a try / except construct.
    :match_6: immutable data type|||A data type which cannot be modified.
    :match_7: infinite recursion|||Function that calls itself recursively without ever reaching the base case, and will cause a runtime error. 
    :match_8: mutable data type|||A data type which can be modified.
    :match_9: raise|||To cause an exception by using the raise statement.
    :match_10: recursion|||The process of calling the function that is already executing.
    :match_11: recursive call|||The statement that calls an already executing function.
    :match_12: recursive definition|||A definition which defines something in terms of itself.
    :match_13: stack frame|||A stack that contains a group of data.
    :match_14: tuple|||Data type that contains a sequence of elements of any type, like alist, but is immutable.
    :match_15: tuple assignment|||An assignment to all of the elements in a tuple using a single assignment statement.  
    

    Drag the word on the left to its corresponding definition