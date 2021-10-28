#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

// general functions
// TODO: use template instead of char**, make it generic
void print2DArrayChar(char** array, int height, int width) {
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cerr << array[i][j];
        }
        cerr << endl;
    }
}

// GameOfLife
class GameOfLife {
    private:
        int state;
        int height;
        int width;
        char** grid;
        char** lastGrid;
        string aliveRules;
        string deadRules;

        int getNumberOfLivingNeighbours(int height, int width);

    public:
        const int INIT_STATE = 0;

        GameOfLife(
            int height, 
            int width, 
            char** grid, 
            string aliveRules, 
            string deadRules
        ): 
            height(height),
            width(width),
            grid(grid),
            aliveRules(aliveRules),
            deadRules(deadRules)
        {
            this->state = INIT_STATE;
            this->lastGrid = copyGrid();
        };

        ~GameOfLife() {
            for(int i = 0; i < height; i++) {
                delete[] grid[i];
            }
            delete[] grid;
        };

        char** copyGrid();
        void printGrid();
        int getState();
        char at(int height, int width);
        void run();
};

char** GameOfLife::copyGrid() {
    char** gridCopy = new char*[height];
    for(int i = 0; i < height; i++) {
        gridCopy[i] = new char[width];
    }

    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            gridCopy[i][j] = grid[i][j];
        }
    }

    return gridCopy;
}

int GameOfLife::getNumberOfLivingNeighbours(int h, int w) {
    // WARN: beware the difference between w(coordinate) and width (array size)
    int nbOfLivingNeighbours = 0;
    for(int i = 0; i < 3; i++) {
        int currentHeight = h - 1 + i;
        // check height bounds
        if(currentHeight >= 0 && currentHeight < height) {
            for(int j = 0; j < 3; j++) {
                int currentWidth = w - 1 + j;
                // in case it is the cell to consider
                if(!(currentHeight == h && currentWidth == w)) { 
                    // check width bounds
                    if(currentWidth >= 0 && currentWidth < width) { 
                        // check the considered neighbour cell is living
                        cerr << "---> [" << currentHeight << "][" << currentWidth << "]" << grid[currentHeight][currentWidth] << endl;
                        if(lastGrid[currentHeight][currentWidth] == 'O') {
                            nbOfLivingNeighbours++;
                        }
                    }
                } 
            }
        } 
    }
    return nbOfLivingNeighbours;
}

void GameOfLife::printGrid() {
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int GameOfLife::getState() {
    return state;
}

char GameOfLife::at(int height, int width) {
    return grid[height][width];
}

void GameOfLife::run() {
    // ERR: Need to have 2 grids, one with the previous state, and one
    // with the new one being computed. Don't update the same grid!!!
    // create a copy of the grid representing last state
    lastGrid = copyGrid();
    print2DArrayChar(lastGrid, height, width);
    print2DArrayChar(grid, height, width);

    // for each cell of the grid, apply the rules corresponding to its state
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int nbLivingNeighbours = getNumberOfLivingNeighbours(i, j);
            cerr << "[" << i << ", " << j << "] nbNeighours = " << nbLivingNeighbours << endl;
            if(lastGrid[i][j] == 'O') {
                // case living cell, apply aliveRules
                bool keepAlive = false;
                for(int k = 0; k < aliveRules.size(); k++) {
                    if(aliveRules.at(k) == '1') {
                        if(nbLivingNeighbours == k) {
                            keepAlive = true;
                            break;
                        }
                    }
                }
                if(!keepAlive) {
                    grid[i][j] = '.';
                    cerr << "[" << i << ", " << j << "] alive = " << '.' << endl;
                } else {
                    grid[i][j] = 'O';
                    cerr << "[" << i << ", " << j << "] alive = " << 'O' << endl;
                }
            } else {
                // case dead cell, apply deadRules
                bool setAlive = false;
                for(int k = 0; k < aliveRules.size(); k++) {
                    if(deadRules.at(k) == '1') {
                        if(nbLivingNeighbours == k) {
                            cerr << "[" << i << ", " << j << "]"
                            <<  " k = " << k << ", nbLivingNeighbours = "
                            << nbLivingNeighbours << endl;
                            setAlive = true;
                            break;
                        }
                    }
                }
                if(setAlive) {
                    cerr << "[" << i << ", " << j << "] dead = " << 'O' << endl;
                    grid[i][j] = 'O';
                } else {
                    grid[i][j] = '.';
                    cerr << "[" << i << ", " << j << "] dead = " << '.' << endl;
                }
            }
            print2DArrayChar(grid, height, width);
        }
    }

    state++;
}

int main()
{
    int h;
    int w;
    int n;
    cin >> h >> w >> n; cin.ignore();

    string alive;
    getline(cin, alive);
    string dead;
    getline(cin, dead);

    // init grid
    // init 2D array: https://www.tutorialspoint.com/Passing-two-dimensional-array-to-a-Cplusplus-function
    char** grid = new char*[h];
    for(int i = 0; i < h; i++) {
        grid[i] = new char[w];
    }

    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        for(int j = 0; j < w; j++) {
            
            grid[i][j] = line[j];
        }
    }
    
    // create GameOfLife
    // The new operator returns a pointer to the object it creates
    GameOfLife* game = new GameOfLife(h, w, grid, alive, dead);

    while(n > game->getState()) {
        game->run();
    }
    game->printGrid();

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}