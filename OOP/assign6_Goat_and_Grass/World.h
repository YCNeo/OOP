#include <unistd.h>
#include <iostream>
#include <vector>

#include "AnsiPrint.h"
#include "Goat.h"
#include "Grass.h"
#include "RandomNum.h"

using namespace std;

static const int dx[4] = {0, 1, 0, -1};
static const int dy[4] = {1, 0, -1, 0};

static const int scaleX = 20;
static const int scaleY = 35;
static const int initFoodPoint = 20;
static const int GoatLifeLimt = 70;
static const int GrassLifeLimt = 6;
static const int _SLEEP = 50000;
static const int NEW_SLEEP = 3000000;

class World : public RandomNum {
    public:
        World(int, int);
        ~World() {}

        void mainLoop(int);
        void worldInit(void);
        void start(void);
        void generateGoat(int, int);
        void generateGrass(int, int);
        void GoatOneTurn(int, int, int);
        void GrassOneTurn(int, int, int);
        void move(int, int, int, int);
        void is_Dead_Goat(int, int);
        void is_Dead_Grass(int, int);
        void print(int);

        bool is_valid(int, int);

    private:
        int worldTable[scaleX][scaleY] = {};
        // Goat GoatTable[scaleX][scaleY];
        // Grass GrassTable[scaleX][scaleY];

        vector<vector<Goat>> GoatTable;
        vector<vector<Grass>> GrassTable;

        int numPass;
        int countPass = 0;
};