..  Copyright (C)  Brad Miller, David Ranum
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Building the Word Ladder Graph
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Our first problem is to figure out how to turn a large collection of
words into a graph. What we would like is to have an edge from one word
to another if the two words are only different by a single letter. If we
can create such a graph, then any path from one word to another is a
solution to the word ladder puzzle. :ref:`Figure 1 <fig_wordladder>` shows a
small graph of some words that solve the FOOL to SAGE word ladder
problem. Notice that the graph is an undirected graph and that the edges
are unweighted.

.. _fig_wordladder:

.. figure:: Figures/wordgraph.png
   :align: center

   Figure 1: A Small Word Ladder Graph

We could use several different approaches to create the graph we need to
solve this problem. Let’s start with the assumption that we have a list
of words that are all the same length. As a starting point, we can
create a vertex in the graph for every word in the list. To figure out
how to connect the words, we could compare each word in the list with
every other. When we compare we are looking to see how many letters are
different. If the two words in question are different by only one
letter, we can create an edge between them in the graph. For a small set
of words that approach would work fine; however let’s suppose we have a
list of 5,110 words. Roughly speaking, comparing one word to every other
word on the list is an :math:`O(n^2)` algorithm. For 5,110 words,
:math:`n^2` is more than 26 million comparisons.

We can do much better by using the following approach. Suppose that we
have a huge number of buckets, each of them with a four-letter word on
the outside, except that one of the letters in the label has been
replaced by an underscore. For example, consider
:ref:`Figure 2 <fig_wordbucket>`, we might have a bucket labeled “pop\_.” As we
process each word in our list we compare the word with each bucket,
using the ‘\_’ as a wildcard, so both “pope” and “pops” would match
“pop\_.” Every time we find a matching bucket, we put our word in that
bucket. Once we have all the words in the appropriate buckets we know
that all the words in the bucket must be connected.

.. _fig_wordbucket:

.. figure:: Figures/wordbuckets.png
   :align: center

   Figure 2: Word Buckets for Words That are Different by One Letter


In C++, we can implement the scheme we have just described by using a
map. The labels on the buckets we have just described are the
keys of our map. The values stored for those keys are a vector of
words. Once we have the map built we can create the graph. We
start our graph by creating a vertex for each word in the graph. Then we
create edges between all the vertices we find for words found under the
same key in the map. :ref:`ActiveCode 1 <wordbucket_cpp>` shows the C++
code required to build the graph.

.. activecode:: wordbucket_cpp
  :caption: Word Bucket C++ Implementation
  :language: cpp

  #include <fstream>
  #include <iostream>
  #include <map>
  #include <string>
  #include <vector>
  using namespace std;

  class Vertex {
  public:
  	string id;
  	map<string, float> connectedTo;

  	Vertex() {
  	}

  	Vertex(string key) {
  		id = key;
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
  		for (map<string, Vertex>::iterator it = vertList.begin();
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
          cout<<endl;
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

  	for (map<string, vector<string> >::iterator iter = d.begin(); iter != d.end(); ++iter) {
  		for(unsigned int i=0; i<iter->second.size();i++) {
              for (unsigned int j=0; j<iter->second.size();j++) {
                  if (iter->second[i]!=iter->second[j]) {
                      g.addEdge(iter->second[i],iter->second[j]);
                  }
              }
          }
  	}

      return g;
  }

  int main() {
      // Vector Initialized with an array
      string arr[] = {"fool","cool","pool","poll","pole","pall","fall","fail","foil","foul","pope","pale","sale","sage","page"};
      vector<string> words(arr,arr+(sizeof(arr)/sizeof(arr[0])));

  	Graph g = buildGraph(words);

  	cout << g << endl;

  	return 0;
  }

Since this is our first real-world graph problem, you might be wondering
how sparse is the graph? The list of four-letter words we have for this
problem is 5,110 words long. If we were to use an adjacency matrix, the
matrix would have 5,110 \* 5,110 = 26,112,100 cells. The graph
constructed by the ``buildGraph`` function has exactly 53,286 edges, so
the matrix would have only 0.20% of the cells filled! That is a very
sparse matrix indeed.
