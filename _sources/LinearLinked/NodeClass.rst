The ``Node`` Class
------------------

The basic building block for the linked list implementation is the
**node**. Each node object must hold at least two pieces of information.
First, the node must contain the list item itself. We will call this the
**data field** of the node. In addition, each node must hold a reference
to the next node. :ref:`Listing 1 <lst_nodeclass>` shows the C++
implementation. To construct a node, you need to supply the initial data
value for the node. Evaluating the assignment statement below will yield
a node object containing the value 93 (see :ref:`Figure 3 <fig_node>`). You
should note that we will typically represent a node object as shown in
:ref:`Figure 4 <fig_node2>`. The ``Node`` class also includes the usual methods
to access and modify the data and the next reference.

.. _lst_nodeclass:

**Listing 1**

.. sourcecode:: cpp

    #include <iostream>
    using namespace std;

    class Node {
        private:
        	int data; //data in the beginning node 
        	Node *next; //pointer to the next node

        public:
        	Node(int initdata) {
        		data = initdata; //the initialized data is set as the head
        		next = NULL; //the next node is set as NULL, as there is no next node yet.
        	}

        	int getData() { //function that return data of a given node. 
        		return data; 
        	}

        	Node *getNext() { 
        		return next;
        	}

        	void setData(int newData) {
        		data = newData;
        	}

        	void setNext(Node *newnext) {
        		next = newnext;
        	}
    };

::

        >>> temp = Node(93) //sets the nodes data to the integer 93
        >>> temp.getData() // calls the getData() function.
        93

The special C++ reference value ``NULL`` will play an important role
in the ``Node`` class and later in the linked list itself. A reference
to ``NULL`` will denote the fact that there is no next node. 

Note:

    in the constructor that a node is initially created with ``next`` and a pointer to
    ``NULL``. Since this is sometimes referred to as “grounding the node,”
    we will use the standard ground symbol to denote a reference that is
    referring to ``NULL``.


.. _fig_node:

.. figure:: Figures/node.png
   :align: center

   Figure 3: A Node Object Contains the Item and a Reference to the Next Node

.. _fig_node2:

.. figure:: Figures/node2.png
   :align: center

   Figure 4: A Typical Representation for a Node
