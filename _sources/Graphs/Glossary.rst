.. .  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Glossary 
--------

.. glossary::

    acyclic graph
        A graph with no cycles

    adjacency list
        A list implementation where we keep a master list of all the vertices in the Graph object and then each vertex object in the graph maintains a list of the other vertices that it is connected to 

    adjacency matrix
        A matrix implementation where each of the rows and columns represent a vertex in the graph, and where if two vertices are connected by an edge, they are considered adjacent.

    adjacent 
        When two vertices are connected by an edge.
    
    breadth first search (BFS)
        A search that proceeds to look through the edges in a graph to find all the vertices in that graph for which there is a path from the starting point. 
    
    cycle
        A cycle in a directed graph is a path that starts and ends at the same vertex.

    cyclic graph
        A graph with at least one cycle in it.

    depth first forest
        The result of the groups of trees produced by a depth first search algorithm.
    
    depth first search (DFS) 
        A search type where the goal is to create the deepest depth first tree, without any branches.
    
    digraph
        see directed graph                         
    
    directed acyclic graph (DAG)
        A directed acyclic graph, which is a directed graph with no cycles.  

    directed graph
        A graph in which all the edges are one-way.

    edge cost                           
        The weight associated with an arc in a graph.

    edge   
        An edge (also called an “arc”) connects two vertices to show that there is a relationship between them. Edges may be one-way or two-way.
    
    parenthesis property
        All the children of a particular node in the depth first tree have a later discovery time and an earlier finish time than their parent.
    
    path
        A path in a graph is a sequence of vertices that are connected by edges.  

    shortest path
        The most succinct passage from one edge to another.

    spanning tree
        An acyclic subset of edges that connects all the vertices.

    strongly connected components (SCC) 
        The largest subset of vertices C⊂V such that for every pair of vertices v,w∈C we have a path from v to w and a path from w to v.
    
    topological sorting
        A topological sort takes a directed acyclic graph and produces a linear ordering of all its vertices such that if the graph G contains an edge (v,w) then the vertex v comes before the vertex w in the ordering.
    
    uncontrolled flooding
         Each message starts with a time to live (``ttl``) value set to some number greater than or equal to the number of edges between the broadcast host and its most distant listener. Each router gets a copy of the message and passes the message on to *all* of its neighboring routers. When the message is passed on the ``ttl`` is decreased. Each router continues to send copies of the message to all its neighbors until the ``ttl`` value reaches 0.

    vertex
        A vertex (also called a “node”) is a fundamental part of a graph. It can have a name (also called a "Key").  A vertex may also have additional information also called a (“payload").
    
    weight
        Shows that there is a cost to go from one vertex to another

Matching
--------


.. dragndrop:: matching_graphs
    :feedback: Look at your glossary
    :match_1: weight|||Shows that there is a cost to go from one vertex to another
    :match_2: vertex|||Also called a “node” this is a fundamental part of a graph. It can have a  “key.” This may also have additional information. We will call this additional information the “payload.”
    :match_3: spanning tree|||An acyclic subset of edges that connects all the vertices.
    :match_4: path|||A sequence of vertices that are connected by edges.
    :match_5: parenthesis property|||All the children of a particular node in the depth first tree have a later discovery time and an earlier finish time than their parent.
    :match_6: edge cost|||The weight associated with an arc in a graph.
    :match_7: edge|||An  “arc” connects two vertices to show that there is a relationship between them and it  may be one-way or two-way.
    :match_8: directed graph|||A graph in which all the edges are one-way.
    :match_9:  adjacency list||| A list implementation where we keep a master list of all the vertices in the Graph object and then each vertex object in the graph maintains a list of the other vertices that it is connected to.
    :match_10: breadth first search (BFS)||| A search that proceeds to look through the edges in a graph to find all the vertices in that graph for which there is a path from the starting point.
    :match_11: cycle|||In a directed graph, a path that starts and ends at the same vertex.
    :match_12: depth first search (DFS)|||A search type where the goal is to create the deepest tree first, without any branches.
    :match_13: adjacency matrix||| A matrix implementation where each of the rows and columns represent a vertex in the graph, and where if two vertices are connected by an edge, they are considered adjacent.


    Drag the word on the left to its corresponding definition (Note not all words in the glossary are here)