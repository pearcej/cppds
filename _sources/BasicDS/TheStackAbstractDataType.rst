..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


The Stack Abstract Data Type
----------------------------


The stack abstract data type is defined by the following structure and
operations. A stack is structured, as described above, as an ordered
collection of items where items are added to and removed from the end
called the “top.” Stacks are ordered LIFO. The stack operations are
given below.

-  ``stack<datatype>`` creates a new stack that is empty. It needs no parameters
   and returns an empty stack. It can only contain a certain type of data. e.g. `int`, `string` etc.

-  ``push(item)`` adds a new item to the top of the stack. It needs the
   item and returns nothing.

-  ``pop()`` removes the top item from the stack. It needs no parameters
   and returns nothing. The stack is modified.

-  ``top()`` returns the top item from the stack but does not remove
   it. It needs no parameters. The stack is not modified.

-  ``empty()`` tests to see whether the stack is empty. It needs no
   parameters and returns a Boolean value.

-  ``size()`` returns the number of items on the stack. It needs no
   parameters and returns an integer.

For example, if ``s`` is a stack that has been created and starts out
empty, then :ref:`Table 1 <tbl_stackops>` shows the results of a sequence of
stack operations. Under stack contents, the top item is listed at the
far right.

.. _tbl_stackops:

.. table:: **Table 1: Sample Stack Operations**

    ============================ ================================== ==================
             **Stack Operation**                 **Stack Contents**   **Return Value**
    ============================ ================================== ==================
                   ``s.empty()``                             ``[]``              ``1``
             ``s.push('horse')``                      ``['horse']``
               ``s.push('dog')``                ``['horse','dog']``
                     ``s.top()``                ``['horse','dog']``          ``'dog'``
               ``s.push('cat')``          ``['horse','dog','cat']``
                    ``s.size()``          ``['horse','dog','cat']``              ``3``
                   ``s.empty()``          ``['horse','dog','cat']``              ``0``
            ``s.push('turtle')`` ``['horse','dog','cat','turtle']``
                     ``s.pop()``          ``['horse','dog','cat']``
                     ``s.pop()``                ``['horse','dog']``
                    ``s.size()``                ``['horse','dog']``              ``2``
    ============================ ================================== ==================
