..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Implementation
~~~~~~~~~~~~~~

Using a map, or dictionaries in Python, it is easy to implement the adjacency list. In our implementation of the Graph abstract data type we will
create two classes (see :ref:`Listing 1 <lst_vertex>` and :ref:`Listing 2 <lst_graph>`), ``Graph``, which holds the master list of vertices,
and ``Vertex``, which will represent each vertex in the graph.

Each ``Vertex`` uses a map to keep track of the vertices to which
it is connected, and the weight of each edge. This map is called
``connectedTo``. The listing below shows the code for the ``Vertex``
class. The constructor simply initializes the ``id``,
which will be an integer, and the ``connectedTo`` map. The
``addNeighbor`` method is used add a connection from this vertex to
another. The ``getConnections`` method returns all of the vertices in
the adjacency list, as represented by the ``connectedTo`` instance
variable. The ``getWeight`` method returns the weight of the edge from
this vertex to the vertex passed as a parameter.

We use ``operator overloading`` so that when we print our Vertex using the ``cout <<`` function
we get a list of its connections, instead of an error. This function must be initialized
as a ``friend function`` within the class definition, but is required to be defined outside of the class. This is specific to ``operator overloading`` in C++.

.. _lst_vertex:

**Listing 1**

::

    class Vertex {
        public:
            int id;
            map<int, int> connectedTo;

            Vertex() {
            }

            Vertex(int key) {
                id = key;
            }

            void addNeighbor(int nbr, int weight = 0) {
                connectedTo[nbr] = weight;
            }

            vector<int> getConnections() {
                vector<int> keys;
                // Use of iterator to find all keys
                for (map<int, int>::iterator it = connectedTo.begin();
                    it != connectedTo.end();
                    ++it) {
                    keys.push_back(it->first);
                }
                return keys;
            }

            int getId() {
                return id;
            }

            int getWeight(int nbr) {
                return connectedTo[nbr];
            }

            friend ostream &operator<<(ostream &, Vertex &);
    };

    ostream &operator<<(ostream &stream, Vertex &vert) {
        vector<int> connects = vert.getConnections();
        for (unsigned int i = 0; i < connects.size(); i++) {
            stream << "( " << vert.id << " , " << connects[i] << " ) \n";
        }

        return stream;
    }


The ``Graph`` class, shown in the next listing, contains a map
that maps vertex names (int) to vertex objects (Vertex). In :ref:`Figure 4 <fig_adjlist>` this
map object is represented by the shaded gray box. ``Graph`` also
provides methods for adding vertices to a graph and connecting one
vertex to another. The ``getVertices`` method returns the names of all
of the vertices in the graph.

.. _lst_graph:

**Listing 2**

::

    class Graph {
        public:
            map<int, Vertex> vertList;
            int numVertices;

            Graph() {
                numVertices = 0;
            }

            Vertex addVertex(int key) {
                numVertices++;
                Vertex newVertex = Vertex(key);
                this->vertList[key] = newVertex;
                return newVertex;
            }

            Vertex *getVertex(int n) {
                for (map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
                    if (it->first == n) {
                        // Forced to use pntr due to possibility of returning NULL
                        Vertex *vpntr = &vertList[n];
                        return vpntr;
                    } else {
                        return NULL;
                    }
                }
            }

            bool contains(int n) {
                for (map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
                    if (it->first == n) {
                        return true;
                    }
                }
                return false;
            }

            void addEdge(int f, int t, int cost = 0) {
                if (!this->contains(f)) {
                    cout << f << " was not found, adding!" << endl;
                    this->addVertex(f);
                }
                if (!this->contains(t)) {
                    cout << t << " was not found, adding!" << endl;
                }
                vertList[f].addNeighbor(t, cost);
            }

            vector<int> getVertices() {
                vector<int> verts;

                for (map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end();  ++it) {
                    verts.push_back(it->first);
                }
                return verts;
            }

            friend ostream &operator<<(ostream &, Graph &);
    };

    ostream &operator<<(ostream &stream, Graph &grph) {
        for (unsigned int i = 0; i < grph.vertList.size(); i++) {
            stream << grph.vertList[i];
        }

        return stream;
    }

Using the ``Graph`` and ``Vertex`` classes just defined, the following
Python session creates the graph in :ref:`Figure 2 <fig_dgsimple>`. First we
create six vertices numbered 0 through 5. Then we display the vertex
dictionary. Notice that for each key 0 through 5 we have created an
instance of a ``Vertex``. Next, we add the edges that connect the
vertices together. Finally, a nested loop verifies that each edge in the
graph is properly stored. You should check the output of the edge list
at the end of this session against :ref:`Figure 2 <fig_dgsimple>`.

.. tabbed:: graph_adt

  .. tab:: C++

    .. activecode:: graph_implementation_cpp
      :caption: C++ Graph and Vertex implementation
      :language: cpp

      #include <iostream>
      #include <map>
      #include <vector>
      using namespace std;

      class Vertex {
      public:
      	int id;
      	map<int, int> connectedTo;

		//Empty constructor.
      	Vertex() {
      	}

		//Constructor that defines the key of the vertex.
      	Vertex(int key) {
      		id = key;
      	}

		//Adds a neighbor to this vertex with the specified ID and weight.
      	void addNeighbor(int nbr, int weight = 0) {
      		connectedTo[nbr] = weight;
      	}
		//Returns a vector (e.g, list) of vertices connected to this one.
      	vector<int> getConnections() {
      		vector<int> keys;
      		// Use of iterator to find all keys
      		for (map<int, int>::iterator it = connectedTo.begin();
      			 it != connectedTo.end();
      			 ++it) {
      			keys.push_back(it->first);
      		}
      		return keys;
      	}

		//Returns the ID of this vertex.
      	int getId() {
      		return id;
      	}

		//Returns the weight of the connection between this vertex and the specified neighbor.
      	int getWeight(int nbr) {
      		return connectedTo[nbr];
      	}

		//Output stream overload operator for printing to the screen.
      	friend ostream &operator<<(ostream &, Vertex &);
      };

      ostream &operator<<(ostream &stream, Vertex &vert) {
      	vector<int> connects = vert.getConnections();
      	for (unsigned int i = 0; i < connects.size(); i++) {
      		stream << "( " << vert.id << " , " << connects[i] << " ) \n";
      	}

      	return stream;
      }

      class Graph {
      public:
      	map<int, Vertex> vertList;
      	int numVertices;

		//Empty constructor.
      	Graph() {
      		numVertices = 0;
      	}

		//Adds the specified vertex and returns a copy of it.
      	Vertex addVertex(int key) {
      		numVertices++;
      		Vertex newVertex = Vertex(key);
      		this->vertList[key] = newVertex;
      		return newVertex;
      	}

		//Returns the vertex with the specified ID.
		//Will return NULl if the vertex doesn't exist.
      	Vertex *getVertex(int n) {
      		for (map<int, Vertex>::iterator it = vertList.begin();
      			 it != vertList.end();
      			 ++it) {
      			if (it->first == n) {
      				// Forced to use pntr due to possibility of returning NULL
      				Vertex *vpntr = &vertList[n];
      				return vpntr;
      			} else {
      				return NULL;
      			}
      		}
      	}
		//Returns a boolean indicating if an index with the specified ID exists.
      	bool contains(int n) {
      		for (map<int, Vertex>::iterator it = vertList.begin();
      			 it != vertList.end();
      			 ++it) {
      			if (it->first == n) {
      				return true;
      			}
      		}
      		return false;
      	}

		//Adds an edge between vertices F and T with a weight equivalent to cost.
      	void addEdge(int f, int t, int cost = 0) {
      		if (!this->contains(f)) {
      			cout << f << " was not found, adding!" << endl;
      			this->addVertex(f);
      		}
      		if (!this->contains(t)) {
      			cout << t << " was not found, adding!" << endl;
      		}
      		vertList[f].addNeighbor(t, cost);
      	}

		//Returns a vector (e.g, list) of all vertices in this graph.
      	vector<int> getVertices() {
      		vector<int> verts;

      		for (map<int, Vertex>::iterator it = vertList.begin();
      			 it != vertList.end();
      			 ++it) {
      			verts.push_back(it->first);
      		}
      		return verts;
      	}

		//Overloaded Output stream operator for printing to the screen
      	friend ostream &operator<<(ostream &, Graph &);
      };

      ostream &operator<<(ostream &stream, Graph &grph) {
      	for (unsigned int i = 0; i < grph.vertList.size(); i++) {
      		stream << grph.vertList[i];
      	}

      	return stream;
      }

      int main() {
      	Graph g;

      	for (int i = 0; i < 6; i++) {
      		g.addVertex(i);
      	}

      	g.addEdge(0, 1, 5);
      	g.addEdge(0, 5, 2);
      	g.addEdge(1, 2, 4);
      	g.addEdge(2, 3, 9);
      	g.addEdge(3, 4, 7);
      	g.addEdge(3, 5, 3);
      	g.addEdge(4, 0, 1);
      	g.addEdge(5, 4, 8);
      	g.addEdge(5, 2, 1);

      	cout << g << endl;

      	return 0;
      }


  .. tab:: Python

    .. activecode:: graph_implementation_py
      :caption: Graph and Vertex implementation
      :optional:

      class Vertex:
	    # Contructor that specifies the key of the vertex.
      	def __init__(self, key):
      		self.id = key
      		self.connectedTo = {}
		# Adds a neighbor with the specified weight.
      	def addNeighbor(self, nbr, weight=0):
      		self.connectedTo[nbr] = weight

		# Converts this vertex to a string representation.
      	def __str__(self):
      		return str(self.id) + ' connectedTo: ' + str(
      		    [x.id for x in self.connectedTo])

		# Returns the list of vertex IDs that are connected to this one.
      	def getConnections(self):
      		return self.connectedTo.keys()

		# Returns the ID of this vertex.
      	def getId(self):
      		return self.id

		# Returns the weight of this vertex in relation to the specified neighbor.
      	def getWeight(self, nbr):
      		return self.connectedTo[nbr]


      class Graph:
	  	# Empty constructor.
      	def __init__(self):
      		self.vertList = {}
      		self.numVertices = 0
		# Adds a vertex with the specified ID (key) and returns it.
      	def addVertex(self, key):
      		self.numVertices = self.numVertices + 1
      		newVertex = Vertex(key)
      		self.vertList[key] = newVertex
      		return newVertex
		# Returns the vertex (or None if nonexistant) with the specified ID n.
      	def getVertex(self, n):
      		if n in self.vertList:
      			return self.vertList[n]
      		else:
      			return None

		# Returns a boolean indicating if the specified vertex ID is in this graph.
      	def __contains__(self, n):
      		return n in self.vertList

		# Adds an edge between F and T with a weight of cost.
      	def addEdge(self, f, t, cost=0):
      		if f not in self.vertList:
      			self.addVertex(f)
      		if t not in self.vertList:
      			self.addVertex(t)
      		self.vertList[f].addNeighbor(self.vertList[t], cost)

		# Returns a list of all vertices in this graph.
      	def getVertices(self):
      		return self.vertList.keys()

		# Iteration overload (useful in python).
      	def __iter__(self):
      		return iter(self.vertList.values())


      def main():
      	g = Graph()
      	for i in range(6):
      		g.addVertex(i)

      	g.addEdge(0, 1, 5)
      	g.addEdge(0, 5, 2)
      	g.addEdge(1, 2, 4)
      	g.addEdge(2, 3, 9)
      	g.addEdge(3, 4, 7)
      	g.addEdge(3, 5, 3)
      	g.addEdge(4, 0, 1)
      	g.addEdge(5, 4, 8)
      	g.addEdge(5, 2, 1)

      	for v in g:
      		for w in v.getConnections():
      			print("( %s , %s )" % (v.getId(), w.getId()))


      main()
