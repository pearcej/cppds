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

In C++, the standard library provides, the ``find`` function
which works on several C++ data types (e.g. arrays, vector, etc.
The example below shows how ``find`` can be used
to search an array or a ``vector``. The first argument to
``find`` is the base object to search, the second argument
is the element past the end (this is how find knows where to
stop), and the third argument value to ``find`` is the item
to locate. If the item is not found, the second argument
is returned. If it is found, an iterator is returned.

::

    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;

    int main() {
        int myints[] = {3, 5, 2, 4, 1};
        cout << (find(myints, myints + 5, 15) != myints + 5) << endl;
        cout << (find(myints, myints + 5, 2) != myints + 5) << endl;

        vector<int> myvec = {3, 5, 2, 4, 1};
        cout << (find(myvec.begin(), myvec.end(), 15) != myvec.end()) << endl;
        cout << (find(myvec.begin(), myvec.end(), 2) != myvec.end()) << endl;
        return 0;
    }


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
