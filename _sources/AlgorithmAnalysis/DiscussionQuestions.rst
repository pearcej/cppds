..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Discussion Questions
--------------------

1. Give the Big-O performance of the following code fragment:

::
  
    int count = 0;
    for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           count = count +1;
       }
    }

2. Give the Big-O performance of the following code fragment:

::

    int count = 0;
    for (int i = 0; i < n; i++){
       count = count + 1;
    }

3. Give the Big-O performance of the following code fragment:

::

    int i = n;
    int count = 0;
    while (i > 0){
        count = count + 1;
        i = i / 2; //Note: integer division
    }

4. Give the Big-O performance of the following code fragment:

::

    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                count = count +1;
            }
        }
    }


5. Give the Big-O performance of the following code fragment:

::

    int count = 0;
    for (int i = 0; i < n; i++){
        count = count + 1;
    }
    for (int j = 0; j < n; j++){
        count = count + 1;
    }
    for (int k = 0; k < n; k++){
        count = count + 1;
    }
