..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


An Adjacency Matrix
~~~~~~~~~~~~~~~~~~~

One of the easiest ways to implement a graph is to use a two-dimensional
matrix. In this matrix implementation, each of the rows and columns
represent a vertex in the graph. The value that is stored in the cell at
the intersection of row :math:`v` and column :math:`w` indicates if
there is an edge from vertex :math:`v` to vertex :math:`w`. When two
vertices are connected by an edge, we say that they are **adjacent**.
:ref:`Figure 3 <fig_adjmat>` illustrates the adjacency matrix for the graph in
:ref:`Figure 2 <fig_dgsimple>`. A value in a cell represents the weight of the
edge from vertex :math:`v` to vertex :math:`w`.

.. _fig_adjmat:

.. figure:: Figures/adjMat.png
   :align: center

   Figure 3: An Adjacency Matrix Representation for a Graph

The advantage of the adjacency matrix is that it is simple, and for
small graphs it is easy to see which nodes are connected to other nodes.
However, notice that most of the cells in the matrix are empty. Because
most of the cells are empty we say that this matrix is “sparse.” A
matrix is not a very efficient way to store sparse data. In fact, in
C++ you must go out of your way to even create a matrix structure
like the one in :ref:`Figure 3 <fig_adjmat>`.

The adjacency matrix is a good implementation for a graph when the
number of edges is large. But what do we mean by large? How many edges
would be needed to fill the matrix? Since there is one row and one
column for every vertex in the graph, the number of edges required to
fill the matrix is :math:`|V|^2`. A matrix is full when every vertex
is connected to every other vertex. There are few real problems that
approach this sort of connectivity. The problems we will look at in this
chapter all involve graphs that are sparsely connected.

.. admonition:: Self Check

    .. mchoice:: adjmatrix_1
        :answer_a: The summation of all surrounding vertices.
        :answer_b: The total number of vertices in the matrix' graph.
        :answer_c: An intersection between a column and a row.
        :answer_d: A single column in the matrix.
        :correct: c
        :feedback_a: Not quite, the value of a vertex doesn't have to be related to its neighbors.
        :feedback_b: No, an elements' value is not always indicative of the graph as a whole.
        :feedback_c: You are correct!
        :feedback_d: No, there are two dimensions by which the vertices can be represented in.

        A vertex in an adjacency matrix represents ____?

    .. mchoice:: adjmatrix_2
        :answer_a: Tiny
        :answer_b: Broken
        :answer_c: Null
        :answer_d: Sparse
        :correct: d
        :feedback_a: Not quite, the graph remains the same size regardless of empty values.
        :feedback_b: No, the graph still works with empty values.
        :feedback_c: No, the graph object's value is not Null.
        :feedback_d: You are correct!

        What may an adjacency matrix graph be called if it is not completely full?