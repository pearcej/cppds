..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Searching
---------

In the next two chapters we will turn our attention to some of the
most common problems that arise in computing: searching and sorting.
In this chapter we will study searching and return to sorting
in the next chapter.

**Searching** is the algorithmic process of finding a particular item in a
collection of items. A search typically answers either ``True`` or
``False`` as to whether the item is present. On occasion it may be
modified to return where the item is found. For our purposes here, we
will simply concern ourselves with the question of membership.

In many languages, libraries provide very easy ways to ask
whether an item is in a container
of items. In Python one uses the ``in`` operator on a list:

::

    >>> 15 in [3,5,2,4,1]
    False
    >>> 3 in [3,5,2,4,1]
    True
    >>>

In C++, the STD vector library provides the ``find`` command
which works on vectors and even on arrays (although much more
awkwardly.) Here is an example using a vector:

::

    >>> #include <vector>
    >>> int myints<int> = {3, 5, 2, 4, 1};
    >>> cout << find(myints.begin(), myints.end(), 15);
    false
    >>> cout << find(myints.begin(), myints.end(), 3);
    true


How does this work? Even though this is easy to write, an underlying process
must be carried out to do the search. 

A function can be created for C++ arrays
by passing in the array, the
size of the array, and the value to search for as arguments.

::

    bool isIn(int alist[], int size, int value) {
        for (unsigned i=0; i<size; i++) {
            if (alist[i] == value) {
                return true;
            }
        }
        return false;
    }

    int main() {
        int myarr[] = {3, 5, 2, 4, 1};

        cout<<isIn(myarr, 5, 15)<<endl;
        cout<<isIn(myarr, 5, 3)<<endl;

        return 0;
    }


This works, but it is not the only way to search!
It turns out that there are multiple different
ways to search for the item. What we are interested in here is how these
algorithms work and how they compare to one another.
