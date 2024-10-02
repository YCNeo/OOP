#include "World.h"

using namespace std;

World::World(int numPassI, int seed) : RandomNum(seed) {
    if (numPassI <= 0)
        numPassI = 1;
    numPass = numPassI;

    // fulfill the GoatTable and GrassTable with Dead elements
    for (int i = 0; i < scaleX; ++i) {
        vector<Goat> GaotTemp;
        vector<Grass> GrassTemp;
        for (int j = 0; j < scaleY; ++j) {
            Goat temp(initFoodPoint, 0);
            GaotTemp.push_back(temp);
            Grass temp2(0);
            GrassTemp.push_back(temp2);
        }
        GoatTable.push_back(GaotTemp);
        GrassTable.push_back(GrassTemp);
    }
    worldInit();
}

// main loop
void World::mainLoop(int displayInterval) {
    while (countPass < numPass) {
        start();
        for (int i = 0; i < scaleX; ++i) {
            for (int j = 0; j < scaleY; ++j) {
                if (worldTable[i][j] == 1 && !GoatTable[i][j].isMoved &&
                    !GoatTable[i][j].is_Dead)
                    GoatOneTurn(i, j, getRandomNum(0, 3));
                else if (worldTable[i][j] == 2 && !GrassTable[i][j].isMoved &&
                         !GrassTable[i][j].is_Dead)
                    GrassOneTurn(i, j, getRandomNum(0, 3));
            }
        }

        if (countPass % displayInterval == 0) {
            print(countPass);
            usleep(_SLEEP);
        }
        ++countPass;
    }
}

// produce 5 Goat and 10 Grass
void World::worldInit() {
    // choose 5 Goats and 10 Grass
    for (int i = 0; i < 15; ++i) {
        int x, y;

        do {        // get valid position
            x = getRandomNum(0, scaleX);
            y = getRandomNum(0, scaleY);
        } while (worldTable[x][y] != 0);

        if (i < 5)        // generate Goat and Grass
            generateGoat(x, y);
        else
            generateGrass(x, y);
    }
}

// all alive    Goat.isMoved = false
//              Goat.is_childBirth = false
//              Grass.isMoved = false
void World::start() {
    for (int i = 0; i < scaleX; ++i)
        for (int j = 0; j < scaleY; ++j) {
            if (worldTable[i][j] == 1) {
                GoatTable[i][j].isMoved = false;
                GoatTable[i][j].is_childBirth = false;
            } else if (worldTable[i][j] == 2) {
                GrassTable[i][j].isMoved = false;
                GrassTable[i][j].is_childBirth = false;
            }
        }
}

// generate new Goat
void World::generateGoat(int x, int y) {
    GoatTable[x][y].initStuation();
    worldTable[x][y] = 1;
}

// generate new Grass
void World::generateGrass(int x, int y) {
    GrassTable[x][y].initStuation();
    worldTable[x][y] = 2;
}

// action of one Goat:
// 1. determine direction
// 2. determine age to know can it generate child?
// 3. determine action and operate it
// 4. check if Goat dead
void World::GoatOneTurn(int x, int y, int dir) {
    int curX = x;
    int curY = y;
    int nextX = x + dx[dir];
    int nextY = y + dy[dir];

    if (is_valid(nextX, nextY) && worldTable[nextX][nextY] != 1) {
        // if curr Goat is in 50 ~ 55, is_childBirth = true
        if (GoatTable[x][y].getLT() >= 50 && GoatTable[x][y].getLT() <= 55)
            GoatTable[x][y].is_childBirth = true;

        // determine how to act
        if (worldTable[nextX][nextY] == 0) {        // (nextX, nextY) is empty
            if (GoatTable[x][y]
                    .is_childBirth) {        // curr Goat is in 50 ~ 55
                generateGoat(nextX, nextY);
                GoatTable[x][y].isMoved = true;
            } else {        // curr Goat move to (nextX, nextY)
                move(x, y, nextX, nextY);
                curX = nextX;
                curY = nextY;
            }
        } else {        // (nextX, nextY) is Grass
            // eat it amd move to (nextX, nextY)
            GoatTable[x][y].eat();
            GrassTable[nextX][nextY].is_Dead = true;
            move(x, y, nextX, nextY);
            curX = nextX;
            curY = nextY;
        }
    }

    // determine if Goat dead
    is_Dead_Goat(curX, curY);
}

// action of one Grass
// 1. determine direction
// 2. determine age to know can it generate child and operate it
// 3. check if Goat dead
void World::GrassOneTurn(int x, int y, int dir) {
    int nextX = x + dx[dir];
    int nextY = y + dy[dir];

    // if curr Grass is in 3 ~ 5, generate child
    if (is_valid(nextX, nextY) && worldTable[nextX][nextY] == 0 &&
        GrassTable[x][y].getLT() >= 3 && GrassTable[x][y].getLT() <= 5)
        generateGrass(nextX, nextY);

    GrassTable[x][y].isMoved = true;

    // determine if Grass dead
    is_Dead_Grass(x, y);
}

// use "curr" to find the Goat in the vecGoat
// mark on worldTable
// new position to (x, y)
void World::move(int x, int y, int nextX, int nextY) {
    GoatTable[x][y].isMoved = true;
    GoatTable[nextX][nextY] = GoatTable[x][y];
    GoatTable[x][y].is_Dead = true;
    worldTable[x][y] = 0;
    worldTable[nextX][nextY] = 1;
}

void World::is_Dead_Goat(int x, int y) {
    GoatTable[x][y].increaseLT();
    GoatTable[x][y].hunger();
    if (GoatTable[x][y].getFP() == 0 ||
        GoatTable[x][y].getLT() == GoatLifeLimt) {
        GoatTable[x][y].is_Dead = true;
        worldTable[x][y] = 0;
    }
}

void World::is_Dead_Grass(int x, int y) {
    GrassTable[x][y].increaseLT();
    if (GrassTable[x][y].getLT() == GrassLifeLimt) {
        GrassTable[x][y].is_Dead = true;
        worldTable[x][y] = 0;
    }
}

// print
void World::print(int num) {
    system("clear");        // Clear the terminal screen
    cout << "[       " << num << "]" << endl;
    for (int i = 0; i < scaleX + 2; ++i) {
        for (int j = 0; j < scaleY + 1; ++j) {
            if (i == 0) {
                if (j == 0)
                    cout << "  ";
                else
                    cout << (j - 1) % 10 << " ";
            } else if (i == 21)
                cout << "--";
            else {
                if (j == 0)
                    cout << (i - 1) % 10 << " ";
                else if (worldTable[i - 1][j - 1] == 0)
                    cout << "  ";
                else if (worldTable[i - 1][j - 1] == 1) {
                    char line[1] = {'X'};
                    AnsiPrint(line, red);
                    cout << " ";
                } else if (worldTable[i - 1][j - 1] == 2) {
                    char line[1] = {'I'};
                    AnsiPrint(line, green);
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

bool World::is_valid(int x, int y) {
    return x >= 0 && x < 20 && y >= 0 && y < 35;
}
