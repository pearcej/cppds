//DFSGraph class originates from DFS page of cppds
//Visualization code authored by Jesse Walker-Schadler

#include <utility>      //std::tuple
#include <list>         //std::list
#include <algorithm>    //std::find
#include <map>          //std::map

#define HEADLESS

#ifdef HEADLESS

#define CTURTLE_HEADLESS
#define CTURTLE_HEADLESS_WIDTH 400
#define CTURTLE_HEADLESS_HEIGHT 400
#define CTURTLE_HEADLESS_NO_HTML

#endif
#include "lib/CTurtle.hpp"

namespace ct = cturtle;

class DFSGraph{
    typedef std::tuple<int, std::list<int>, ct::Turtle*> vertex_t;
    typedef std::map<int, vertex_t> graph_t;
public:
    const bool directional;
    DFSGraph(bool directional) : directional(directional){}

    bool containsVertex(int id){
        return vertices.count(id);
    }

    std::list<int>& getVertexConnections(int id){
        return std::get<1>(vertices[id]);
    }

    void addVertex(int id, ct::Turtle* turtle){
        if(containsVertex(id)){
            std::get<1>(vertices[id]).clear();
        }else{
            vertices[id] = std::make_tuple(id, std::list<int>(), turtle);
        }
    }

    vertex_t& getVertex(int id){
        return vertices[id];
    }

    void addEdge(int fromID, int toID){
        //Removed this capability because each node needs it's own turtle pointer.
        //Simply adding a vertex when it doesn't exist won't do.
//        if(!containsVertex(fromID))
//            addVertex(fromID);
//
//        if(!containsVertex(toID))
//            addVertex(toID);

        getVertexConnections(fromID).push_back(toID);
        if(!directional)
            getVertexConnections(toID).push_back(fromID);
    }

    void dfs(){
        std::list<int> visitedList;

        for(auto& cur : vertices){
            if(std::find(visitedList.begin(), visitedList.end(), cur.first) == visitedList.end()){
                dfsvisit(visitedList, cur.second);
            }
        }
    }

    void dfsvisit(std::list<int>& visitedList, vertex_t& vertex){
        visitedList.push_back(std::get<0>(vertex));
        std::get<2>(vertex)->fillcolor({"grey"});

        int visits = 0;
        
        for(int neighborID : std::get<1>(vertex)){
            if(std::find(visitedList.begin(), visitedList.end(), neighborID) == visitedList.end()){
                dfsvisit(visitedList, getVertex(neighborID));
                visits++;
            }
        }

        std::get<2>(vertex)->fillcolor({"black"});
    }
    
    void drawConnections(ct::Turtle& turtle){
        for(auto& cur : vertices){
            //id neighbors turtles
            // 0         1       2
            auto& vertex = cur.second;
            
            const ct::Point vertexPos = std::get<2>(cur.second)->penstate().transform.getTranslation();
            
            //For every neighbor, draw a line between each node.
            for(int neighborID : std::get<1>(vertex)){
                auto& neighborVertex = vertices[neighborID];
                ct::Turtle& neighborTurtle = *std::get<2>(neighborVertex);
                const ct::Point neighborPos = neighborTurtle.penstate().transform.getTranslation();
                
                turtle.penup();
                turtle.goTo(vertexPos);
                turtle.pencolor({"orange"});
                turtle.width(5);
                
                turtle.pendown();
                
                turtle.goTo(ct::middle(neighborPos, vertexPos));
                
                turtle.width(2);
                turtle.pencolor({"brown"});
                turtle.goTo(neighborPos);
                turtle.penup();
            }
        }
    }
private:
    graph_t vertices;
};

int main(int argc, char**argv){
#ifdef HEADLESS
    ct::TurtleScreen screen;
#else
    ct::TurtleScreen screen(400, 400);   
#endif
    screen.tracer(0, 0);

    //we have 6 total nodes in the graph. We need to pre-instantiate them all.
    ct::Turtle node_turtles[] = {
            {screen},
            {screen},
            {screen},
            {screen},
            {screen},
            {screen},
    };
    
    //We also need a turtle that can draw the lines between nodes
    ct::Turtle lineTurtle {screen};

    DFSGraph graph(true);
    
    const int node_radius = 30;
    const ct::Circle shape = {30, 50, {"white"}};
    
    const int padding = 125;
    
    const std::string node_labels[] = {
        "A", "B", "C", "D", "E", "F"
    };
    
    //We need to prepare each turtle and node in the graph.
    for(int y = 0; y < 2; y++){
        for(int x = 0; x < 3; x++){
            const int id = (y * 3) + x;
            
            ct::Turtle& turtle = node_turtles[id];
            graph.addVertex(id, &turtle);
            
            turtle.shape(shape);
            turtle.penup();
            
            //move the turtle to the correct spot while also centering it on the screen.
            turtle.goTo((x * padding) - padding, (y * -padding) + (padding/2));
            
            //turn it left to make label writing easier
            turtle.left(90);
            
            const int labelOffset = node_radius * 2 * (y > 0 ? -1 : 1);//top half goes up, bottom half goes down
            
            turtle.forward(labelOffset);
            turtle.write(node_labels[id]);
            turtle.backward(labelOffset);
            turtle.fillcolor({"white"});
        }
    }

    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5,2);
    
    graph.drawConnections(lineTurtle);
    lineTurtle.hideturtle();
    
    screen.tracer(1, 1000);
    
    graph.dfs();
    
#ifdef HEADLESS
    screen.bye();
#else
    screen.exitonclick();
#endif
    return 0;
}
