#include <iostream>
using namespace std;

// GitHub : https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_Tetris.cpp 
// YT video : https://youtu.be/8OK8_tHeCIA 

wstring tetromino[7];
int gameFieldWidth = 12;    // from gameBoy
int gameFieldHeight = 18;   // from gameBoy
unsigned char *pField = nullptr; // array (buffer) for play field 

int Rotate(int px, int py, int r) {
	int pi = 0; // index
	switch (r % 4)  {
        case 0: // 0 degrees			// 0  1  2  3
            pi = py * 4 + px;			// 4  5  6  7
            break;						// 8  9 10 11
                                        //12 13 14 15

        case 1: // 90 degrees			//12  8  4  0
            pi = 12 + py - (px * 4);	//13  9  5  1
            break;						//14 10  6  2
                                        //15 11  7  3

        case 2: // 180 degrees			//15 14 13 12
            pi = 15 - (py * 4) - px;	//11 10  9  8
            break;						// 7  6  5  4
                                        // 3  2  1  0

        case 3: // 270 degrees			// 3  7 11 15
            pi = 3 - py + (px * 4);		// 2  6 10 14
            break;						// 1  5  9 13
    }								    // 0  4  8 12

	return pi;
}

int main() {
    // assets
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    pField = new unsigned char[gameFieldWidth*gameFieldHeight]; // Create play field buffer
	for (int x = 0; x < gameFieldWidth; x++) // Board Boundary
		for (int y = 0; y < gameFieldHeight; y++)
			pField[y*gameFieldWidth + x] = (x == 0 
            || x == gameFieldWidth - 1 
            || y == gameFieldHeight - 1) ? 9 : 0;


}
