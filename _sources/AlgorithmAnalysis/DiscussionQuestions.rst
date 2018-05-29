..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Discussion Questions
--------------------

#. Give the Big-O performance of the following code fragment:

::

    for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           k = 2 + 2;
       }
    }

#. Give the Big-O performance of the following code fragment:

::

    for (int i = 0; i < n; i++){
       k = 2 + 2;
    }

#. Give the Big-O performance of the following code fragment:

::

    int i = n;
    while (i > 0){
       k = 2 + 2
       i = i // 2
    }

#. Give the Big-O performance of the following code fragment:

::

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                k = 2 + 2;
            }
        }
    }


#. Give the Big-O performance of the following code fragment:

::

    for (int i = 0; i < n; i++){
        k = 2 + 2;
    }
    for (int j = 0; j < n; j++){
        k = 2 + 2;
    }
    for (int k = 0; k < n; k++){
        k = 2 + 2;
    }
