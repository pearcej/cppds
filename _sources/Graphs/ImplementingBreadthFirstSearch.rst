..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Implementing Breadth First Search
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

With the graph constructed we can now turn our attention to the
algorithm we will use to find the shortest solution to the word ladder
problem. The graph algorithm we are going to use is called the “breadth
first search” algorithm. **Breadth first search** (**BFS**) is one of
the easiest algorithms for searching a graph. It also serves as a
prototype for several other important graph algorithms that we will
study later.

Given a graph :math:`G` and a starting vertex :math:`s`, a breadth
first search proceeds by exploring edges in the graph to find all the
vertices in :math:`G` for which there is a path from :math:`s`. The
remarkable thing about a breadth first search is that it finds *all* the
vertices that are a distance :math:`k` from :math:`s` before it
finds *any* vertices that are a distance :math:`k+1`. One good way to
visualize what the breadth first search algorithm does is to imagine
that it is building a tree, one level of the tree at a time. A breadth
first search adds all children of the starting vertex before it begins
to discover any of the grandchildren.

To keep track of its progress, BFS colors each of the vertices white,
gray, or black. All the vertices are initialized to white when they are
constructed. A white vertex is an undiscovered vertex. When a vertex is
initially discovered it is colored gray, and when BFS has completely
explored a vertex it is colored black. This means that once a vertex is
colored black, it has no white vertices adjacent to it. A gray node, on
the other hand, may have some white vertices adjacent to it, indicating
that there are still additional vertices to explore.

The breadth first search algorithm shown in :ref:`Listing 2 <lst_wordbucket2>` below uses the
adjacency list graph representation we developed earlier. In addition it uses a ``Queue``,
a crucial point as we will see, to decide which vertex to explore next.

In addition the BFS algorithm uses an extended version of the ``Vertex``
class. This new vertex class adds three new instance variables:
distance, predecessor, and color.

BFS begins at the starting vertex ``s`` and colors ``start`` gray to
show that it is currently being explored. Two other values, the distance
and the predecessor, are initialized to 0 and ``NULL`` respectively for
the starting vertex. Finally, ``start`` is placed on a ``Queue``. The
next step is to begin to systematically explore vertices at the front of
the queue. We explore each new node at the front of the queue by
iterating over its adjacency list. As each node on the adjacency list is
examined its color is checked. If it is white, the vertex is unexplored,
and four things happen:

#. The new, unexplored vertex ``nbr``, is colored gray.

#. The predecessor of ``nbr`` is set to the current node ``currentVert``

#. The distance to ``nbr`` is set to the distance to ``currentVert + 1``

#. ``nbr`` is added to the end of a queue. Adding ``nbr`` to the end of
   the queue effectively schedules this node for further exploration,
   but not until all the other vertices on the adjacency list of
   ``currentVert`` have been explored.


.. _lst_wordbucket2:

**Listing 2**

.. tabbed:: bfs_impl1

    .. tab:: C++

        ::
        
            Graph bfs(Graph g, Vertex *start) {
                start->dist = 0;
                start->pred = NULL;
                queue<Vertex *> vertQueue;
                vertQueue.push(start);
                while (vertQueue.size() > 0) {
                    Vertex *currentVert = vertQueue.front();
                    vertQueue.pop();
                // For each neighbor of the current vertex
                    for (unsigned int nbr = 0; nbr < currentVert->getConnections().size(); nbr++) {
                        if (g.vertList[currentVert->getConnections()[nbr]].color == 'w') {
                            g.vertList[currentVert->getConnections()[nbr]].color = 'g';
                            g.vertList[currentVert->getConnections()[nbr]].dist = currentVert->dist + 1;
                            g.vertList[currentVert->getConnections()[nbr]].pred = currentVert;
                            vertQueue.push(&g.vertList[currentVert->getConnections()[nbr]]);
                        }
                    }
                    currentVert->color = 'b';
                }
                return g;
            }

    .. tab:: Python

        ::

            from pythonds.graphs import Graph, Vertex
            from pythonds.basic import Queue

            def bfs(g,start):
                start.setDistance(0)
                start.setPred(None)
                vertQueue = Queue()
                vertQueue.enqueue(start)
                while (vertQueue.size() > 0):
                    currentVert = vertQueue.dequeue()
                    for nbr in currentVert.getConnections():
                        if (nbr.getColor() == 'white'):
                            nbr.setColor('gray')
                            nbr.setDistance(currentVert.getDistance() + 1)
                            nbr.setPred(currentVert)
                            vertQueue.enqueue(nbr)
                    currentVert.setColor('black')

Let’s look at how the ``bfs`` function would construct the breadth first
tree corresponding to the graph in :ref:`Figure 1 <fig_wordladder>`. Starting
from fool we take all nodes that are adjacent to fool and add them to
the tree. The adjacent nodes include pool, foil, foul, and cool. Each of
these nodes are added to the queue of new nodes to expand.
:ref:`Figure 3 <fig_bfs1>` shows the state of the in-progress tree along with the
queue after this step.

.. _fig_bfs1:

.. figure:: Figures/bfs1.png
   :align: center

   Figure 3: The First Step in the Breadth First Search

In the next step ``bfs`` removes the next node (pool) from the front of
the queue and repeats the process for all of its adjacent nodes.
However, when ``bfs`` examines the node cool, it finds that the color of
cool has already been changed to gray. This indicates that there is a
shorter path to cool and that cool is already on the queue for further
expansion. The only new node added to the queue while examining pool is
poll. The new state of the tree and queue is shown in :ref:`Figure 4 <fig_bfs2>`.

.. _fig_bfs2:

.. figure:: Figures/bfs2.png
   :align: center

   Figure 4: The Second Step in the Breadth First Search



The next vertex on the queue is foil. The only new node that foil can
add to the tree is fail. As ``bfs`` continues to process the queue,
neither of the next two nodes add anything new to the queue or the tree.
:ref:`Figure 5 <fig_bfs3>` shows the tree and the queue after expanding all the
vertices on the second level of the tree.


.. _fig_bfs3:

.. figure:: Figures/bfs3.png
   :align: center

   Figure 5: Breadth First Search Tree After Completing One Level


.. _fig_bfsDone:

.. figure:: Figures/bfsDone.png
   :align: center

   FIgure 6: Final Breadth First Search Tree


You should continue to work through the algorithm on your own so that
you are comfortable with how it works. :ref:`Figure 6 <fig_bfsDone>` shows the
final breadth first search tree after all the vertices in
:ref:`Figure 3 <fig_wordladder>` have been expanded. The amazing thing about the
breadth first search solution is that we have not only solved the
FOOL–SAGE problem we started out with, but we have solved many other
problems along the way. We can start at any vertex in the breadth first
search tree and follow the predecessor arrows back to the root to find
the shortest word ladder from any word back to fool. The function below (:ref:`Listing 3 <lst_wordbucket3>`) shows how to follow the predecessor links to
print out the word ladder.

.. _lst_wordbucket3:

**Listing 3**


.. tabbed:: traverse_impl1

    .. tab:: C++

        ::

            void traverse(Vertex *y) {
                Vertex *x = y;

                while (x->pred) {
                    cout << x->id << endl;
                    x = x->pred;
                }
                cout << x->id << endl;
            }

            //traverse(g.getVertex("sage"))

    .. tab:: Python

        ::
            
            def traverse(vertex):
                cur = vertex

                while cur.getPred():
                    print(cur.getId())
                    cur = cur.getPred()
                print(cur.getId())

            traverse(g.getVertex('sage'))

Because of syntactic changes to C++ between C++98 and C++11, the following code
will not run in your ActiveCode window and must be copied and pasted into a compiler using C++11 to run.

Below is a completed implementation of both the Vertex and Graph classes, along
with an implementation for the breadth-first search shown above.

::

    #include <fstream>
    #include <iostream>
    #include <map>
    #include <queue>
    #include <string>
    #include <vector>
    using namespace std;

    class Vertex {
    public:
        string id;
        map<string, float> connectedTo;
        // Added for Breadth-First Algorithm
        char color;
        float dist;
        Vertex *pred;

        Vertex() {
            // w for white, g for grey, b for black
            color = 'w';
            dist = 0;
            pred = NULL;
        }

        Vertex(string key) {
            id = key;
            color = 'w';
            dist = 0;
            pred = NULL;
        }

        void addNeighbor(string nbr, float weight = 1) {
            connectedTo[nbr] = weight;
        }

        vector<string> getConnections() {
            vector<string> keys;
            // Use of iterator to find all keys
            for (map<string, float>::iterator it = connectedTo.begin();
                 it != connectedTo.end();
                 ++it) {
                keys.push_back(it->first);
            }
            return keys;
        }

        string getId() {
            return id;
        }

        float getWeight(string nbr) {
            return connectedTo[nbr];
        }

        friend ostream &operator<<(ostream &, Vertex &);
    };

    ostream &operator<<(ostream &stream, Vertex &vert) {
        vector<string> connects = vert.getConnections();
        stream << vert.id << " -> ";
        for (unsigned int i = 0; i < connects.size(); i++) {
            stream << connects[i] << endl << "\t";
        }

        return stream;
    }

    class Graph {
        public:
            map<string, Vertex> vertList;
            int numVertices;
            bool directional;

            Graph(bool directed = true) {
                directional = directed;
                numVertices = 0;
            }

            Vertex addVertex(string key) {
                numVertices++;
                Vertex newVertex = Vertex(key);
                this->vertList[key] = newVertex;
                return newVertex;
            }

            Vertex *getVertex(string n) {
                return &vertList[n];
            }

            bool contains(string n) {
                for (map<string, Vertex>::iterator it = vertList.begin();
                     it != vertList.end();
                     ++it) {
                    if (it->first == n) {
                        return true;
                    }
                }
                return false;
            }

            void addEdge(string f, string t, float cost = 1) {
                if (!this->contains(f)) {
                    this->addVertex(f);
                }
                if (!this->contains(t)) {
                    this->addVertex(t);
                }
                vertList[f].addNeighbor(t, cost);

                if (!directional) {
                    vertList[t].addNeighbor(f, cost);
                }
            }

            vector<string> getVertices() {
                vector<string> verts;

                for (map<string, Vertex>::iterator it = vertList.begin();
                     it != vertList.end();
                     ++it) {
                    verts.push_back(it->first);
                }
                return verts;
            }

            friend ostream &operator<<(ostream &, Graph &);
    };

    ostream &operator<<(ostream &stream, Graph &grph) {
        for (map<string, Vertex>::iterator it = grph.vertList.begin();
             it != grph.vertList.end();
             ++it) {
            stream << grph.vertList[it->first];
            cout << endl;
        }

        return stream;
    }

    string getBlank(string str, int index) {
        string blank = str;
        blank[index] = '_';
        return blank;
    }

    Graph buildGraph(vector<string> words) {
        Graph g(false);

        map<string, vector<string> > d;

        // Go through the words
        for (unsigned int i = 0; i < words.size(); i++) {
            // Go through each letter, making it blank
            for (unsigned int j = 0; j < words[i].length(); j++) {
                string bucket = getBlank(words[i], j);
                // Add the word to the map at the location of the blank
                d[bucket].push_back(words[i]);
            }
        }

        for (map<string, vector<string> >::iterator iter = d.begin();
             iter != d.end();
             ++iter) {
            for (unsigned int i = 0; i < iter->second.size(); i++) {
                for (unsigned int j = 0; j < iter->second.size(); j++) {
                    if (iter->second[i] != iter->second[j]) {
                        g.addEdge(iter->second[i], iter->second[j]);
                    }
                }
            }
        }

        return g;
    }

    Graph bfs(Graph g, Vertex *start) {
        start->dist = 0;
        start->pred = NULL;
        queue<Vertex *> vertQueue;
        vertQueue.push(start);
        while (vertQueue.size() > 0) {
            Vertex *currentVert = vertQueue.front();
            vertQueue.pop();
            for (unsigned int nbr = 0; nbr < currentVert->getConnections().size(); nbr++) {
                if (g.vertList[currentVert->getConnections()[nbr]].color == 'w') {
                    g.vertList[currentVert->getConnections()[nbr]].color = 'g';

                    g.vertList[currentVert->getConnections()[nbr]].dist =
                        currentVert->dist + 1;
                    g.vertList[currentVert->getConnections()[nbr]].pred =
                        currentVert;
                    vertQueue.push(&g.vertList[currentVert->getConnections()[nbr]]);
                }
            }
            currentVert->color = 'b';
        }

        return g;
    }

    void traverse(Vertex *y) {
        Vertex *x = y;

        while (x->pred) {
            cout << x->id << endl;
            x = x->pred;
        }
        cout << x->id << endl;
    }

    int main() {
        // Vector Initialized with an array
        string arr[] = {"fool",
                        "cool",
                        "pool",
                        "poll",
                        "pole",
                        "pall",
                        "fall",
                        "fail",
                        "foil",
                        "foul",
                        "pope",
                        "pale",
                        "sale",
                        "sage",
                        "page"};

        vector<string> words(arr, arr + (sizeof(arr) / sizeof(arr[0])));

        // Graph g = buildGraph(words);
        Graph g(false);

        g = buildGraph(words);

        g = bfs(g, g.getVertex("fool"));

        traverse(g.getVertex("pall"));

        return 0;
    }
