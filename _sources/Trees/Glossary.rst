.. .  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Glossary
--------

.. glossary::

    AVL tree
        a binary search tree that automatically makes sure the tree remains
        balanced at all times

    balance factor
        the difference between the height of the left and right subtrees of
        a node

    binary heap
        a complete binary tree that follows heap ordering rules

    binary search tree
        a binary tree in which each node has no more than 2 children; node values
        in the left sub-tree are less than the parent while node values in the
        right sub-tree are

    binary tree
        a tree with a maximum of two children for each node

    bst propery
        property of a binary search key in which the keys that are less than
        the parent are found in the left subtree and keys that are greater
        than the parent are found in the right subtree

    children
        the nodes that one node leads to

    complete binary tree
        a tree in which each level has all of its nodes, with the exception of
        the bottom level

    edge
        connects two nodes in a tree; has only one incoming edge

    heap order property
        property of the heap based on min heap or max heap (i.e. in a min heap,
        every node x with a parent p, the key in p is smaller than or equal to
        the key in x)

    height
        the maximum level of any node in the tree

    inorder
        recursive tree traversal in which the left subtree is visited, then the
        root node, followed by the right subtree

    leaf node
        a node that has no children

    level
        the number of edges on the path from the root to the current node

    max heap
        a binary heap in which the largest key is always at the front

    min heap
        a binary heap in which the smallest key is always at the front

    node
        part of the tree that holds information

    parent
        a node that leads to other nodes

    path
        an ordered list of nodes connected by edges

    postorder
        recursive tree traversal in which the left subtree is visited, then the
        right, followed by the root node

    preorder
        recursive tree traversal in which the root node is visited, then the
        left, followed by the right subtree

    priority queue
        a queue whose elements have a priority that determines their order

    root
        the starting point of the tree; has no incoming edges

    rotation
        rotating the parent and children nodes in a subtree to reorganize
        their hierarchy
        
    sibling
        children of the same parent node

    subtree
        a section of a tree

    successor
        a node that can replace another node while preserving the binary search
        tree relationships; the next-largest key in the tree

    tree
        a hierarchal data structure with a root, branches, and leaves.
Matching
--------


.. dragndrop:: matching_sort
    :feedback: Review classes and their properties
    :match_1: tree|||a hierarchal data structure with a root, branches, and leaves.
    :match_2: AVL tree|||Binary search tree that automatically makes sure the tree remains balanced at all times
    :match_3: binary search tree|||a binary tree in which each node has no more than 2 children.
    :match_4: bst propery|||node values in the left sub-tree are less than the parent while node values in the right sub-tree are
    :match_5: tree|||Hierarchal data structure with a root, branches, and leaves.
    :match_6: root|||the starting point of the tree; has no incoming edges
    :match_7: path|||an ordered list of nodes connected by edges 
    :match_8: parent|||a node that leads to other nodes
    :match_9: sibling|||children of the same parent node
    :match_10: short bubble|||Stops if there are no exchanges to do
    :match_11: shell sort|||Divides the collection into subsets, sorts the subsets individually using insertion sort, then also sorts the combination of the sorted subsets using insertion sort
    :match_12: sorting|||Process of placing elements from a collection in some kind of order
    :match_13: split point|||Position of the pivot value in the sorted collection; used to divide the collection for subsequent calls to quick sort
    :match_14: quick sort|||Uses recursion to split a collection in half and places elements on the proper side of the split point
   

    Drag the word on the left to its corresponding definition (Note not all words in the glossary are here)