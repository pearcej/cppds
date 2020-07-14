#define CTURTLE_HEADLESS
#define CTURTLE_HEADLESS_WIDTH 880
#define CTURTLE_HEADLESS_HEIGHT 440
#define CTURTLE_HEADLESS_NO_HTML

#include "CTurtle.hpp"
#include <fstream>
namespace ct = cturtle;

const char MAZE_OBSTACLE = '+';
const char MAZE_START = 'S';
const char MAZE_PATH = 'O';
const char MAZE_DEAD_END = '-';
const char MAZE_TRIED = '.';

const int SQUARE_SIZE = 40;

class maze{
public:
    maze(const std::string& filename){
        std::ifstream str(filename);
        
        std::string line;
        int row = 0;
        while(std::getline(str, line)){
            content.push_back(line);
            for(int column = 0; column < line.length(); column++){
                if(line[column] == MAZE_START){
                    startRow = row;
                    startColumn = column;
                }
            }
            row++;
        }
        
        totalRows = row;
        totalColumns = content[0].length();//assume all rows are the same length
    }
    
    void drawMaze(ct::Turtle& turtle){
        const int totalWidth = SQUARE_SIZE * totalColumns;
        const int totalHeight = SQUARE_SIZE * totalRows;
        
        turtle.penup();
        turtle.fillcolor({"orange"});
        for(int row = 0; row < totalRows; row++){
            turtle.goTo(-(totalWidth/2), (totalHeight/2) - (row * SQUARE_SIZE));
            
            for(int column = 0; column < totalColumns; column++){
                
                if(content[row][column] == MAZE_OBSTACLE){
                    turtle.begin_fill();
                    for(int i = 0; i < 4; i++){
                        turtle.forward(SQUARE_SIZE);
                        turtle.right(90);
                    }
                    turtle.end_fill();
                }
                
                turtle.forward(SQUARE_SIZE);
            }
        }
    }
    
    bool isOnEdge(int row, int column){
        return (row == 0 || column == 0) || 
                (row == totalRows - 1 || column == totalColumns - 1) ;
    }
    
    void moveToSpot(ct::Turtle& turtle, int row, int column){
        const int totalWidth = SQUARE_SIZE * totalColumns;
        const int totalHeight = SQUARE_SIZE * totalRows;
        
        turtle.goTo(-(totalWidth/2) + (column * SQUARE_SIZE) + (SQUARE_SIZE / 2), (totalHeight/2) - (row * SQUARE_SIZE) - (SQUARE_SIZE / 2));
    }
    
    void updatePosition(ct::Turtle& turtle, int row, int column, char value){
        moveToSpot(turtle, row, column);
        
        content[row][column] = value;
        
        switch(value){
            case MAZE_PATH:
                turtle.circle(10, 5, {"blue"});
                break;
            case MAZE_TRIED:
                turtle.circle(5, 3, {"black"});
                break;
            case MAZE_DEAD_END:
                turtle.circle(10, 4, {"brown"});
                break;
        }
    }
    
    std::string& operator[](int row){
        return content[row];
    }
    
    int totalRows, totalColumns;
    int startRow, startColumn;
    std::vector<std::string> content;
};

bool searchFrom(ct::Turtle& turtle, maze& maze, int startRow, int startColumn){
    if(maze[startRow][startColumn] == MAZE_OBSTACLE)
        return false;
    
    if(maze[startRow][startColumn] == MAZE_TRIED)
        return false;
    
    if(maze.isOnEdge(startRow, startColumn)){
        maze.updatePosition(turtle, startRow, startColumn, MAZE_PATH);
        return true;
    }
    
    maze.updatePosition(turtle, startRow, startColumn, MAZE_TRIED);
    
    bool found = searchFrom(turtle, maze, startRow - 1, startColumn) ||
            searchFrom(turtle, maze, startRow + 1, startColumn) ||
            searchFrom(turtle, maze, startRow, startColumn - 1) ||
            searchFrom(turtle, maze, startRow, startColumn + 1);
            
    maze.updatePosition(turtle, startRow, startColumn, found ? MAZE_PATH : MAZE_DEAD_END);
    
    return found;
}

int main(int argc, char** argv) {
    ct::TurtleScreen screen;
    screen.tracer(0);
    
    ct::Turtle turtle(screen);
    turtle.speed(ct::TS_FASTEST);

    //Uses "maze1.txt" from the page.
    maze m("./maze.txt");
    m.drawMaze(turtle);
    
    turtle.shape("square");
    turtle.fillcolor({"black"});

    m.moveToSpot(turtle, m.startRow, m.startColumn);
    screen.tracer(2, 250);
    turtle.speed(ct::TS_NORMAL);
    searchFrom(turtle, m, m.startRow, m.startColumn);
    
    screen.bye();
    return 0;
}
