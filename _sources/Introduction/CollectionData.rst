..  Copyright (C)  Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
    To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Collections
~~~~~~~~~~~

In addition to the numeric, Boolean, and character types,
C++ also offers built-in collection types.
A **collection** data type is a grouping of some number of other data items
(possibly only zero or one) that have some shared significance
or need to be operated upon together.

Arrays, vectors, strings, sets, and hash tables are among these useful
C++ collection types.

Arrays
------

**What is an Array?**
An array is a data structure consisting of an ordered collection of data elements,
of identical type in which each element can be identified by an array index.
More technically, an array data structure is an ordered arrangement of values
located at equally spaced addresses in contiguous computer memory.

NOTE: A C++ **array** is always stored in contiguous memory. C++ arrays can be allocated in two different ways:

    1) *statically allocated* in which the array size is fixed at compile-time and cannot change
    2) *dynamically allocated* in which pointers are used in the allocation process so the size can change at run-time

In modern C++, the statically allocated array is typically used
in situations when speed is essential or where hardware constraints exist, and a data structure
called a vector is typically used when more flexibility is required.


Because C++ stores variables
directly, each element of a C++ array must be of identical data type.
The indices for arrays start counting with 0.

The use of arrays permits us to utilize an ordered set
of memory locations that we can then manipulate as a single
entity, and that at the same time gives us direct access to each
individual component.

**Why use an Array?**

C++ is a language often used for real-time or low-level processing
where speed is essential and/or there is only a fixed amount of space
available.

The fact that array elements are stored in memory in contiguous
memory locations making look-up via index very, very fast.
In computing, a **word** is the unit of data used by a particular processor design,
such as 32 or 64 bits. For example, an array of 100 integer variables, with indices 0 through 99,
might be stored as 100 words at memory addresses 20000, 20004, 20008, ... 20396.
The element with index i would be located at the address 20000 + 4 × i.

Statically allocated C++ arrays must be declared with both a type and a size at compile-time.

::

    double darray[4];
    int iarray[10];
    char arr2[3000];


It is also possible to initialize statically allocated arrays at compile time,
in which case the number of items determines the array's size.

::

    int arr[] = {1, 2, 3, 4};  // This is size 4.
    char arr2[] = {'a', 'b', 'c'}; // This is size 3.
    string arr3[] = {"this", "is", "an", "array"}; // This is size 4.


Note that an array with a single element is not the same type as the **atomic** type,
so the following are not the same.

::

    double darray[] = {1.2};  // must use index to access value
    double ddouble = 1.2;     // can't use index to access value


**Be Cautious with Arrays**

The speed and low-level control that arrays offer us
as programmers is powerful... and dangerous.
C++ is designed for speed, and using a C++ array will
help you better understand the trade-offs inherent in this.

Here are examples of iteration.

.. tabbed:: list-array

  .. tab:: C++

    .. activecode:: listarray_cpp
        :caption: Iterating an array in C++
        :language: cpp

        //showcases an iteration through an array in C++
        #include <iostream>
        using namespace std;

        int main(){
            int myarray[] = {2,4,6,8};
            for (int i=0; i<4; i++){
                cout << myarray[i] << endl;
            }
            return 0;
        }

  .. tab:: Python

    .. activecode:: listarray_py
        :caption: Iterating a list in Python
        :optional:

        #showcases an iteration through an array in Python
        def main():
            mylist = [2, 4, 6, 8]
            for i in range(4):
                print(mylist[i])

        main()


C++ is designed for speed.
C++ will not only let you iterate beyond either
end of an array, but it will let you change the values
beyond either end of the array with sometimes catastrophic
results.

The phrase, "be careful what you wish for" is a great one
to remember when programming in C++. Because C++ will
generally try to do everything you ask for.

.. tabbed:: array_error

  .. tab:: C++

    .. activecode:: array_error_cpp
        :caption: Iterating an array in C++
        :language: cpp

        //outputs the result of trying to access a value outside of an array
        #include <iostream>
        using namespace std;

        int main(){
            int myarray[] = {2,4,6,8};
            for (int i=0; i<=8; i++){
                cout << myarray[i] << endl;
                cout << "id: " << &myarray[i] << endl;
            }
            return 0;
        }

  .. tab:: Python

    .. activecode:: array_error_py
        :caption: Iterating a list in Python
        :optional:

        #outputs the result of trying to access a value outside of an array
        def main():
            mylist = [2,4,6,8]
            print(mylist)
            for i in range(5):
                print(mylist[i])
                print("id: "+str(id(mylist[i])))

        main()

The speed of C++ comes at the cost of minimal to no error checking.
Sometimes this can have perplexing results such as in the next example.

You should use an array when you have a need for speed
or you need to work with hardware constraints.
Otherwise, you may want to consider using another collection data type,
the *vector*.

.. tabbed:: array_werror

  .. tab:: C++

    .. activecode:: array_werror_cpp
        :caption: Array write error in C++
        :language: cpp

        /*shows how C++ allows you to easily overwrite values in memory even when
        you don't mean to. */
        #include <iostream>
        using namespace std;

        int main(){
            int myarray[] = {2, 4};
            int otherdata[]={777, 777};
            for (int i=0; i<4; i++){
                myarray[i]=0;
                cout <<"myarray[" << i << "]=";
                cout << myarray[i] << endl;
                cout << "add:" << &myarray[i] << endl;
            }

            for (int i=0; i<2; i++){
                cout << "otherdata[" << i << "]=";
                cout << otherdata[i] << endl;
                cout << "add:" << &otherdata[i] << endl;
            }

            return 0;
        }

  .. tab:: Python

    .. activecode:: array_werror_py
        :caption: Write error in Python
        :optional:

        """shows how C++ allows you to easily
        overwrite values in memory even when
        you dont mean to."""
        def main():
            mylist = [2, 4]
            otherdata = [777, 777]
            for i in range(4):
                print(mylist[i])
                print("id: "+str(id(mylist[i])))

            for j in range(2):
                  print(otherdata[i])
                  print("id: "+str(id(otherdata[i])))

        main()



.. mchoice:: mc_werror
   :answer_a: Nothing. Everything is fine.
   :answer_b: All data was automatically reinitialized.
   :answer_c: I have no idea. Please give me a hint.
   :answer_d: The first loop went out of bounds and wrote over the values in otherdata.
   :answer_e: none of the above
   :correct: d
   :feedback_a: Actually, there is a problem. Look carefully.
   :feedback_b: No. C++ just does what you tell it to do.
   :feedback_c: Try again. One of these is indeed correct. Look at the memory addresses.
   :feedback_d: Right!
   :feedback_e: One of the above is indeed correct.

   In the above example, what happened to otherdata[ ] in C++?

.. mchoice:: mc_array
    :answer_a: int myarray(5);
    :answer_b: myarray[5];
    :answer_c: int myarray[5];
    :answer_d: None of the above.
    :correct: c
    :feedback_a: Check the characters at the end of the array! Right now that is a function!
    :feedback_b: You are forgetting something important!
    :feedback_c: Good work!
    :feedback_d: Check the characters at the end of the array!

    What is the correct way to declare an array in C++?

Vectors
-------

**Vectors** use a dynamically allocated array to store their elements,
so they can change size, and they have other friendly features as well.
Because they use a dynamically allocated array, they use contiguous storage locations
which means that their elements can be accessed and traversed, and they
can also be accessed randomly using indexes.
However, vectors are dynamically sized, so their size can change automatically.
A new element can be inserted into or deleted from any part of a vector,
and automatic reallocation for other existing items in the vector will be applied.
Vectors are homogeneous, so every element in the vector must be of the same type.

Vectors are a class that is available through a library called the Standard Template Library (STL), and one uses a ``< >``
notation to indicate the data type of the elements. In order to use vectors, One
needs to include the vector library.

::

   #include <vector>


.. _tbl_vectorbasics:

.. table:: **Common C++ Vector Operators**


   ===================== ============================= ====================================================
    **Vector Operation**                       **Use**                                      **Explanation**
   ===================== ============================= ====================================================
                 ``[ ]``               ``myvector[i]``                   access value of element at index i
                   ``=``         ``myvector[i]=value``                   assign value to element at index i
           ``push_back``    ``myvect.push_back(item)``            Appends item to the far end of the vector
            ``pop_back``         ``myvect.pop_back()``      Deletes last item (from  far end) of the vector
              ``insert``    ``myvect.insert(i, item)``                           Inserts an item at index i
               ``erase``           ``myvect.erase(i)``                       Erases an element from index i
                ``size``             ``myvect.size()``             Returns the actual size used by elements
            ``capacity``         ``myvect.capacity()``       Returns the size of allocated storage capacity
             ``reserve``    ``myvect.reserve(amount)``               Request a change in capacity to amount
   ===================== ============================= ====================================================


A very common programming task is to grow a vector using the ``push_back()`` method to append to the vector
as we see in the next example.
Because vectors can change size, vectors typically allocate some extra storage to accommodate for possible growth.
Thus the vector typically has an actual *capacity* greater than the storage *size* strictly needed to contain its elements.


Matching
^^^^^^^^
.. dragndrop:: matching_vectors
   :feedback: Feedback shows incorrect matches.
   :match_1: [ ]|||Accesses value of an element.
   :match_2: =||| Assigns value to an element.
   :match_3: push_back|||Appends item to the end of the vector.
   :match_4: pop_back||| Deletes last item of the vector.
   :match_5: insert|||Injects an item into the vector.
   :match_6: erase|||Deletes an element from the choosen index.
   :match_7: size|||Returns the actual capacity used by elements.
   :match_8: capacity|||Returns the ammount of allocated storage space.
   :match_9: reserve||| Request a change in space to amount

    Match the Vector operations with their corresponding explanation.

.. tabbed:: intro_vector

 .. tab:: C++

   .. activecode:: introvector_cpp
       :caption: Using a vector in C++
       :language: cpp

       /*shows the use of the reserve member, and how it
       can be effective in saving time with a growing vector.*/
       #include <iostream>
       #include <vector>
       using namespace std;

       int main(){

           vector<int> intvector;
           intvector.reserve(50);

           for (int i=0; i<50; i++){
               intvector.push_back(i*i);
               cout << intvector[i] << endl;
           }
           return 0;
       }

 .. tab:: Python

   .. activecode:: introvector_py
       :caption: Using a Python list
       :optional:

       #Python doesn't have vectors, simply stating the limit is enough
       def main():
           intlist=[]
           for i in range(50):
               intlist.append(i*i)
               print(intlist[i])

       main()


In the above example, the use of ``reserve`` was optional. However, it is a good
idea to use it before growing a vector in this way because it will save time.
Because vectors are stored in underlying arrays which require contiguous memory,
every time the vector's size gets too large for the capacity, the entire vector must
be moved to a larger location in memory, and all that copying takes time.
In a typical implementation, the capacity is doubled each time. as in the
example that follows.


.. activecode:: vector_no_reserve_cpp
   :caption: With use of ``reserve``
   :language: cpp

   //code from above but without the reserve
   #include <iostream>
   #include <vector>
   using namespace std;

   int main(){

       vector<int> intvector;
       // without intvector.reserve(50);

       for (int i=0; i<50; i++){
           intvector.push_back(i*i);
           cout << intvector[i] << endl;
           cout << "capacity: " << intvector.capacity() << endl;
       }
       return 0;
   }


Remembering that C++ is designed for speed, not protection,
we will likely not be surprised by the following:

.. tabbed:: vector_errors

 .. tab:: C++

   .. activecode:: vector_errors_cpp
       :caption: Vectors out of bounds
       :language: cpp

       //shows errors when a vector goes out of bounds
       #include <iostream>
       #include <vector>
       using namespace std;

       int main(){

           vector<int> intvector;
           intvector.reserve(10);

           for (int i=0; i<10; i++){
               intvector.push_back(i);
           }

           for (int i=0; i<=10; i++){
               cout << "intvector[" << i << "]="<<intvector[i] << endl;
           }

           return 0;
       }

 .. tab:: Python

   .. activecode:: vector_errors_py
       :caption: Python list out of bounds
       :optional:

       #shows errors when a vector goes out of bounds
       def main():
           intlist=[]
           for i in range(10):
               intlist.append(i)

           for i in range(11):
               print("intlist[" + str(i) + "]=" + str(intlist[i]))

       main()



.. mchoice:: mc_array_vector
  :answer_a: Vectors can change size.
  :answer_b: Vectors offer many more features and protections than arrays.
  :answer_c: Vectors don't use contiguous memory, so elements can be inserted.
  :answer_d: more than one of the above
  :answer_e: none of the above
  :correct: d
  :feedback_a: Yes, however, there are more benefits to using vectors.
  :feedback_b: Not all of the protections of arrays are offered by vectors; one can still iterate off of either end.
  :feedback_c: No. Although elements can be inserted in vectors, they do require contiguous memory.
  :feedback_d:  Right! Good job!
  :feedback_e: One of the above is indeed correct.

  Which of the following is the biggest difference between a C++ array and a C++ vector?


.. mchoice:: mc_vector1
  :answer_a: Nothing. It is completely optional.
  :answer_b: Using it will save time if you know the maximum size needed.
  :answer_c: It is required so memory can be allocated.
  :answer_d: none of the above
  :correct: b
  :feedback_a: It is optional but it does serve a purpose. Try again.
  :feedback_b: Right!
  :feedback_c: It is not required.
  :feedback_d: One of the above is indeed correct.

  What good is the ``reserve`` method in a vector?


Strings
-------

**Strings** are sequential collections of zero or more characters such as letters, numbers
and other symbols. There are actually two types of strings in C++ . The *C++ string* or just *string* from the
``<string>`` library is the more modern type.
The old style *C-string* which is essentially
an array of ``char`` type. The char type itself is actually distinct from both types of strings.

::

    char cppchar = 'a';   // char values use single quotes
    string cppstring = "Hello World!";  // C++ strings use double quotes
    char cstring[] = {"Hello World!"};    // C-string or char array uses double quotes


In older versions of C++, you must use a ``char`` array to work with filenames. In modern
C++ (from C++11 onward), however, you can use a C++ string for everything.
Since C++ strings are so much nicer, I would not recommend using C-strings unless you have a reason.

Because strings are sequences, all of the typical sequence operations work as you would expect.
In addition, the string library offers a huge number of
methods, some of the most useful of which are shown in :ref:`Table 4<tab_stringmethods>`.

.. mchoice:: cstringquestion1_1
    :answer_a: An array of characters that ends with a terminating null character. i.e. \0
    :answer_b: A sequential data structure consisting of zero or more characters
    :answer_c: A data structure consisting of an ordered collection of data elements of identical type in which each element can be identified by an array index.
    :answer_d: sequence container storing data of a single type that is stored in a dynamically allocated array which can change in size.
    :correct: a
    :feedback_a: Correct! a c-string is different from a string
    :feedback_b: Close, but that is the definition of a string, not a c-string
    :feedback_c: Sorry, thats not a string or a c-string
    :feedback_d: No, that's a vector

    What is the correct definition of c-strings?

.. _tab_stringmethods:

.. table:: **Table 4: String Methods Provided in C++**

    ===================  ==============================  =========================================================
        **Method Name**                         **Use**                                            **Explanation**
    ===================  ==============================  =========================================================
                ``[ ]``                  ``astring[i]``                       access value of character at index i
                  ``=``            ``astring[i]=value``                       change value of character at index i
                  ``+``          ``string1 + astring2``                                        concatenate strings
             ``append``      ``astring.append(string)``                     Append to string the end of the string
          ``push_back``     ``astring.push_back(char)``               Appends a character to the end of the string
           ``pop_back``          ``astring.pop_back()``      Deletes the last character from the end of the string
             ``insert``   ``astring.insert(i, string)``                       Inserts a string at a specific index
              ``erase``         ``astring.erase(i, j)``                Erases an element from one index to another
               ``find``          ``astring.find(item)``          Returns the index of the first occurrence of item
               ``size``              ``astring.size()``                             Returns the size of the string
    ===================  ==============================  =========================================================


Matching
^^^^^^^^
.. dragndrop:: matching_strings
   :feedback: Feedback shows incorrect matches.
   :match_1: [ ]|||Accesses value of an element.
   :match_2: =||| Assigns value to an element.
   :match_3: push_back|||Adjoins a character to the end of the string.
   :match_4: pop_back|||Removes the last character from the end of the string.
   :match_5: insert|||Injects a string at a specific index.
   :match_6: erase|||Deletes an element from one index to another.
   :match_7: size|||Returns the capacity of the string.
   :match_8: +|||connects strings.
   :match_9: append|||Adjoins a string to the end of the string.
   :match_10: find||| Returns the index of the first occurrence of item.

    Match the String operations with their corresponding explanation.

.. tabbed:: intro_string

  .. tab:: C++

    .. activecode:: introstring_cpp
        :caption: Strings in C++
        :language: cpp

        //shows basic string usage in C++
        #include <iostream>
        #include <string>
        using namespace std;

        int main(){

            string mystring1 = "Hello";
            string mystring2 = "World!";
            string mystring3;

            mystring3 = mystring1 + " " + mystring2;
            cout << mystring3 << endl;

            cout << mystring2 << " begins at ";
            cout << mystring3.find(mystring2) << endl;

            return 0;
        }

  .. tab:: Python

    .. activecode:: introstring_py
        :caption: Python strings
        :optional:

        #shows basic string usage in Python
        def main():
            mystring1 = "Hello"
            mystring2 = "World!"

            mystring3 = mystring1 + " " + mystring2
            print(mystring3)

            print(mystring2, end=" ")
            print("begins at", end=" ")
            print(str(mystring3.find(mystring2)))

        main()


Check your understanding by completing the following question.


.. dragndrop:: string_types
   :feedback: Feedback shows incorrect matches.
   :match_1: char|||'a'
   :match_2: char array|||{'a'}
   :match_3: string|||"a"


   Drag each data type to its' corresponding C++ initialization syntax.


Hash Tables
-----------

A **hash table** is a collection of associated pairs of
items where each pair consists of a *key* and a *value*.
Hash tables are often called the more general term *map*
because the associated hash function "maps" the key to the value.
Nevertheless, it is better to use the more precise term, *hash table*
because other kinds of maps are sometimes implemented with a different underlying data structure.

Each hash table has a *hash function* which
given the key as input to the hash function
returns the location of the associated value as the output.
This makes look up fast.

In C++, the *unordered_map* implements the hash table, and the ``<unordered_map>``
library must be included as follows:

::

 #include <unordered_map>

The syntax for hash table access is much like we might expect
except that instead of using the index of the item for look-up, we
use the key. Hash tables can be initialized with key-value pairs and
key-value pairs can also be added later as we see in the following example.
In C++, the keyword ``first`` is used for the key, and ``second`` is used for the
associated value.

.. tabbed:: hashtable1

   .. tab:: C++

       .. activecode:: hashtable1_cpp
           :caption: Using a Hash Table C++
           :language: cpp

           //shows how hash tables can be used in C++
           #include <iostream>
           #include <unordered_map>
           #include <string>
           using namespace std;

           int main() {
               unordered_map<string, string> spnumbers;

               spnumbers = { {"one", "uno"}, {"two", "dos"} };

               spnumbers["three"] = "tres";
               spnumbers["four"] = "cuatro";

               cout << "one is ";
               cout << spnumbers["one"] << endl;

               cout << spnumbers.size() << endl;

               return 0;
           }

   .. tab:: Python

       .. activecode:: hashtable1_py
           :caption: Using a Dictionary
           :optional:

           #shows how hash tables can be used in python
           def main():
               spnumbers = {"one":"uno","two":"dos"}

               spnumbers["four"]="cuatro"
               spnumbers["three"]="tres"

               print("one is", end=" ")
               print(spnumbers["one"])

               print(len(spnumbers))
           main()


It is important to note that hash tables are organized by the location given
by the hash function rather than being in any
particular order with respect to the keys. This makes look-up extremely fast.
Hence, although it is possible to iterate through a hash table,
it is an odd thing to do
because the data is not typically stored sequentially.
Iterators of an ``unordered_map`` are
implemented using pointers to point to elements of the value type as we see in
the following example.

.. tabbed:: hashtable2

   .. tab:: C++

       .. activecode:: hashtable2_cpp
           :caption: Iterating a Hash Table C++
           :language: cpp

           //shows how to iterate through a hash table in C++
           #include <iostream>
           #include <unordered_map>
           #include <string>
           using namespace std;

           int main() {
               unordered_map<string, string> spnumbers;

               spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

               for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ ){
                   cout << i->first << ":";
                   cout << i->second << endl;
               }

               return 0;
           }

   .. tab:: Python

       .. activecode:: hashtable2_py
           :caption: Iterating a Dictionary
           :optional:

           #shows how to iterate through a hash table in python
           def main():
               spnumbers = {"one":"uno","two":"dos","three":"tres","four":"cuatro","five":"cinco" }

               for key in spnumbers:
                   print(key, end=":")
                   print(spnumbers[key])

           main()


Hash Tables have both methods and operators. :ref:`Table 7 <tab_hashopers>`
describes them, and the session shows them in action.

.. _tab_hashopers:

.. table:: **Table 7: Important Hash Table Operators Provided in C++**

   ===================== ========================= ==================================================================================================================
            **Operator**                   **Use**                                                  **Explanation**
   ===================== ========================= ==================================================================================================================
                 ``[ ]``              ``mymap[k]``  Returns the value associated with ``k``; if there is no entry for ``k``, one will be created with a default value
                  ``at``         ``mymap.at(key)``                                                    Returns the value associated with ``k``, otherwise throws error
               ``count``      ``mymap.count(key)``                                                       Returns ``true`` if key is in ``mymap``, ``false`` otherwise
               ``erase``      ``mymap.erase(key)``                                                                                   Removes the entry from ``mymap``
               ``begin``         ``mymap.begin()``                                                                      An iterator to the first element in ``mymap``
                 ``end``        ``mymap.end(key)``                                                           n iterator pointing to past-the-end element of ``mymap``
   ===================== ========================= ==================================================================================================================


Matching
^^^^^^^^
.. dragndrop:: matching_HT
   :feedback: Feedback shows incorrect matches.
   :match_1: [ ]|||Returns the value associated with the key, creating a default entry if necessary.
   :match_2: at|||Returns the value associated with the key, otherwise throws error.
   :match_3: erase|||Deletes the entry from the hash table.
   :match_4: count|||Returns true if key is in the hash table, and false otherwise.
   :match_5: begin|||An iterator to the first element in the hash table.
   :match_6: end|||An iterator pointing to past-the-end element of the hash table.

    Match the Hash Table operations with their corresponding explanation.

Unordered Sets
--------------

An **unordered_set** is an unordered collection of zero or more unique C++ data values
of a particular type.
To use unordered_sets, you import ``unordered_set`` from the Standard template library with
``#include <unorderd_set>``.

Unordered_sets allow for fast retrieval of individual elements based on their value.
In an unordered_set, the value of an element is at the same time its key, that identifies it uniquely.
``Keys`` are **immutable**, therefore, the elements in an ``unordered_set`` cannot be modified once in the container -
However, they can be inserted and removed.


Unordered sets do not allow duplicates and are initialized using comma-delimited
values enclosed in curly braces. The collection can be assigned to
a variable as shown below.


::

   set<int> mySet = {3, 6, 4, 78, 10}


Unordered sets support a number of methods that should be familiar to those who
have worked with sets in a mathematics setting. :ref:`Table 6 <tab_setmethods>`
provides a summary. Examples of their use follow.

.. _tab_setmethods:

.. table:: **Table 6: Methods Provided by Sets in C++**

   ======================== ================================= ================================================================
            **Method Name**                           **Use**                                                  **Explanation**
   ======================== ================================= ================================================================
                  ``union``                   ``set_union()``               Returns a new set with all elements from both sets
           ``intersection``            ``set_intersection()``   Returns a new set with only those elements common to both sets
             ``difference``              ``set_difference()``    Returns a new set with all items from first set not in second
                    ``add``             ``aset.insert(item)``                                             Adds item to the set
                 ``remove``              ``aset.erase(item)``                                        Removes item from the set
                  ``clear``                  ``aset.clear()``                                Removes all elements from the set
   ======================== ================================= ================================================================

The code below is an example of a program that can detect if a specific char is in an unordered set.

.. activecode:: UnorderedSetExample
    :language: cpp

    //code detects if a specific char is in an unordered set.
    #include <iostream>
    #include <unordered_set>
    using namespace std;

    void checker(unordered_set<char> set, char letter){
        if(set.find(letter) == set.end()){
            cout << "letter " << letter << " is not in the set." << endl;
        }
        else{
            cout << "letter " << letter << " is in the set." << endl;
        }
    }

    int main(){
        unordered_set<char> charSet = {'d', 'c', 'b', 'a'};

        char letter = 'e';
        checker(charSet, letter);
        charSet.insert('e');
        checker(charSet, letter);
        return 0;
    }

the ``find`` method used for a conditional in ``Checker`` compares each item in the set
with the given parameter until there is a match. the ``set.find(letter) == set.end()``
section means that if ``find`` cannot find the letter before reaching the end of the
set, then ``letter`` is not contained in the set.

Matching
^^^^^^^^
.. dragndrop:: matching_us
   :feedback: Feedback shows incorrect matches.
   :match_1: union|||Returns a new set with all elements from both sets.
   :match_2: intersection|||Returns a new set with only those elements common to both sets.
   :match_3: difference||| Returns a new set with all items from first set not in second.
   :match_4: add|||Adds item to the set.
   :match_5: remove|||erases item from the set.
   :match_6: clear|||Removes all elements from the set.

    Match the Unordered Sets operations with their corresponding explanation.


.. mchoice:: mc_fixed
  :answer_a: array
  :answer_b: hash table
  :answer_c: string
  :answer_d: vector
  :answer_e: more than one of the above
  :correct: a
  :feedback_a: Correct!
  :feedback_b: No. hash tables are not ordered.
  :feedback_c: A string would only work for character data. Try again.
  :feedback_d: There is a better choice given that the group is fixed length
  :feedback_e: Only of the above is best.

  Which C++ structure is the best choice for a group of ordered data of a fixed length?



.. dragndrop:: collect_data_types
  :feedback: Feedback shows incorrect matches.
  :match_1: Array|||{“What”, “am”, “I”, "am"}
  :match_2: Set|||{“What”, “am”, “I”}
  :match_3: String|||“What am I”
  :match_4: Hash Table|||{ {“What”, “am I”} }

  Drag each data type to its' corresponding C++ initialization syntax.
