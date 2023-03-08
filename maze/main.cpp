#include <iostream>
#include <vector>
//#include <fstream>
//#include <sstream>

//Defines dimensions of the maze grid
#define SIZE 5

/*std::string getMaze(std::string fileName) {
    std::ifstream in;
    std::string line;
    std::stringstream ss;

    in.open(fileName);
    if(in.fail()) {
        return "0";
    }
    if(in.is_open()) {
        while(in.good()) {
            getline(in, line);
            ss << line;
        }
    }
    std::string mazeString = ss.str();

    return mazeString;
}*/

//Prints the maze grid
void printMaze(int maze[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}

//Searches the maze through recursion to find a path through
bool pathFinder(int x, int y, int maze[SIZE][SIZE]) {

    //Eliminates negative coordinate values
    if(x < 0 || y < 0) {
        return false;
    }

    //Eliminates coordinate values higher than maze dimensions
    if(x > SIZE - 1 || y > SIZE - 1) {
        return false;
    }

    //Eliminates values of '0' and '2' as valid paths
    if(maze[x][y] == 0) {
        return false;
    }

    //Marks cells that the algorithm crosses twice as '3'
    if(maze[x][y] == 2) {
        maze[x][y] = 3;
        return false;
    }

    //This is the goal coordinate. If the function executes this statement, the maze is solved
    if(x == SIZE - 1 && y == SIZE - 1) {
        maze[x][y] = 2;
        return true;
    }

    //Marks visited coordinates with '2'
    maze[x][y] = 2;

    //Recursively searches coordinate values below, above, to the left, and to the right of current coordinate
    if(pathFinder(x+1, y, maze) || pathFinder(x-1, y, maze) || pathFinder(x, y+1, maze) || pathFinder(x, y-1, maze)) {
        return true;
    } else {
        return false;
    }
}



int main() {
   int maze[SIZE][SIZE] =  {{1,1,1,1,1},
                            {0,1,0,1,0},
                            {0,1,0,1,1},
                            {0,1,0,0,1},
                            {0,0,0,0,1}};
    bool path = pathFinder(0,0,maze);
    if(!path) {
        std::cout << "Unsolvable" << std::endl;
    }
    printMaze(maze);
    return 0;
}