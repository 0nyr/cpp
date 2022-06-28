#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordinate {
    int x;
    int y;
};

struct Square{
    Coordinate topLeft;
    Coordinate bottomRight;
};

enum Direction {
    U,
    UR,
    R,
    DR,
    D,
    DL,
    L,
    UL
};

class Solver {
    public:
        Coordinate position;
        Square building;
        Square possibleArea;

        Solver(Coordinate position, Square building) {
            this->position = position;
            this->building = building;
            this->possibleArea = building;
        }

        Coordinate determineNextJumpCoordinates(Direction direction);
};

Coordinate Solver::determineNextJumpCoordinates(Direction const direction) {
    // update possibleArea
    switch (direction) {
        case U:
            // next up position up to max top position
            possibleArea.topLeft.x = position.x;
            possibleArea.bottomRight.x = position.x;
            possibleArea.bottomRight.y = position.y - 1;
            break;
        case UR:
            possibleArea.topLeft.x = position.x + 1;
            possibleArea.bottomRight.y = position.y - 1;
            break;
        case R:
            // next right position up to max right position
            possibleArea.topLeft.x = position.x + 1;
            possibleArea.topLeft.y = position.y;
            possibleArea.bottomRight.y = position.y;
            break;
        case DR:
            possibleArea.topLeft.x = position.x + 1;
            possibleArea.topLeft.y = position.y + 1;
            break;
        case D:
            // next down position up to max bottom position
            possibleArea.topLeft.x = position.x;
            possibleArea.topLeft.y = position.y + 1;
            possibleArea.bottomRight.x = position.x;
            break;
        case DL:
            possibleArea.topLeft.y = position.y - 1;
            possibleArea.bottomRight.x = position.x - 1;
            break;
        case L:
            // next left position up to max left position
            possibleArea.topLeft.y = position.y;
            possibleArea.bottomRight.x = position.x - 1;
            possibleArea.bottomRight.y = position.y;
            break;
        case UL:
            possibleArea.bottomRight.x = position.x - 1;
            possibleArea.bottomRight.y = position.y - 1;
            break;
        default:
            break;
    }

    // cerr possibleArea
    cerr << "possibleArea: " 
        << "{" << possibleArea.topLeft.x << ", " << possibleArea.topLeft.y << "}, {" 
        << possibleArea.bottomRight.x << ", " << possibleArea.bottomRight.y << "}" << endl;

    // move to center posiiton of possibleArea
    Coordinate centerPosition = {
        ((possibleArea.bottomRight.x - possibleArea.topLeft.x) / 2) + possibleArea.topLeft.x,
        ((possibleArea.bottomRight.y - possibleArea.topLeft.y) / 2) + possibleArea.topLeft.y
    };
    return centerPosition;
}

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();

    Coordinate startPosition = Coordinate{x0, y0};
    Square building = Square{
        Coordinate{0, 0},
        Coordinate{w - 1, h - 1}
    };
    cerr << "startPosition: " 
        << "{" << startPosition.x << ", " << startPosition.y << "}" << endl;
    cerr << "building: " 
        << "{" << building.topLeft.x << ", " << building.topLeft.y << "}, {" 
        << building.bottomRight.x << ", " << building.bottomRight.y << "}" << endl;

    Solver * solver = new Solver(startPosition, building);

    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // convert bomb direction string to enum
        Direction direction = U;
        if (bomb_dir == "U") {
            direction = U;
        } else if (bomb_dir == "UR") {
            direction = UR;
        } else if (bomb_dir == "R") {
            direction = R;
        } else if (bomb_dir == "DR") {
            direction = DR;
        } else if (bomb_dir == "D") {
            direction = D;
        } else if (bomb_dir == "DL") {
            direction = DL;
        } else if (bomb_dir == "L") {
            direction = L;
        } else if (bomb_dir == "UL") {
            direction = UL;
        }
        cerr << "direction: " << direction << endl;

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        Coordinate nextJumpPosition = solver->determineNextJumpCoordinates(
            direction
        );

        // the location of the next window Batman should jump to.
        cout << nextJumpPosition.x << " " << nextJumpPosition.y << endl;

        // WARN: don't forget to update the solver's position
        solver->position = nextJumpPosition;
    }
}