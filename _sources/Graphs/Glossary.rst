.. .  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Glossary 
--------

.. glossary::

    acyclic graph
        A graph with no cycles is called an **acyclic graph**

    adjacency list
        A list implementation where we keep a master list of all the vertices in the Graph object and then each vertex object in the graph maintains a list of the other vertices that it is connected to 

    adjacency matrix
        A matrix implementation where each of the rows and columns represent a vertex in the graph, and where if two vertices are connected by an edge, they are considered adjacent.

    adjacent -  When two vertices are connected by an edge.
    
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
        a graph in which all the edges are one-way.
    
    edge cost                           
        the weight associated with an arc in a graph.
    edge   
        An edge (also called an “arc”) connects two vertices to show that there is a relationship between them. Edges may be one-way or two-way.
    
    parenthesis property                  
    
    path
        A path in a graph is a sequence of vertices that are connected by edges.                         
    
    shortest path
        the most succinct passage from one edge to another.
    
    spanning tree                         
    
    strongly connected components (SCC) topological sort & uncontrolled flooding
        the largest subset of vertices C⊂V such that for every pair of vertices v,w∈C we have a path from v to w and a path from w to v.
    
    topological sorting
        A topological sort takes a directed acyclic graph and produces a linear ordering of all its vertices such that if the graph G contains an edge (v,w) then the vertex v comes before the vertex w in the ordering.
   
    vertex
        A vertex (also called a “node”) is a fundamental part of a graph. It can have a name, which we will call the “key.” A vertex may also have additional information. We will call this additional information the “payload.”                          
    
    weight
        Edges may be weighted to show that there is a cost to go from one vertex to another. For example in a graph of roads that connect one city to another, the weight on the edge might represent the distance between the two cities.
