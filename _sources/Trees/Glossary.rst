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


.. dragndrop:: matching_trees
    :feedback: Look at your glossary
    :match_1: tree|||Hierarchal data structure with a root, branches, and leaves.
    :match_2: AVL tree|||Binary search tree that automatically makes sure the tree remains balanced at all times
    :match_3: binary search tree|||Binary tree in which each node has no more than 2 children.
    :match_4: bst propery|||Node values in the left sub-tree are less than the parent while node values in the right sub-tree are are greater than the parent
    :match_5: Leaf node|||Node that has no children
    :match_6: root|||Starting point of the tree
    :match_7: path|||Ordered list of nodes connected by edges 
    :match_8: parent|||Node that leads to other nodes
    :match_9: max heap|||Largest key is always at the front
    :match_10: rotation|||Pivoting the parent and children nodes in a subtree to reorganize their hierarchy
    :match_11: preorder|||Recursive tree traversal in which the root node is visited, then the left, followed by the right subtree
    :match_12: postorder|||Recursive tree traversal in which the left subtree is visited, then the right, followed by the root node
    :match_13: inorder|||Recursive tree traversal in which the left subtree is visited, then the root node, followed by the right subtree
    :match_14: successor|||Replaces another node while preserving the binary search tree relationships; the next-largest key in the tree
    :match_15: subtree|||Section of a tree
    :match_16: complete binary tree|||Tree in which each level has all of its nodes, with the exception of the bottom level
    :match_17: path|||Ordered list of nodes connected by edges
    :match_18: level|||Number of edges on the path from the root to the current node
    :match_19: height|||Maximum level of any node in the tree


    Drag the word on the left to its corresponding definition (Note not all words in the glossary are here)