#include <iostream>

#include "Creature.h"

using namespace std;

#ifndef GOAT
#define GOAT

class Goat : public Creature {
    public:
        Goat(int, int);
        ~Goat() {}

        void initStuation(void);
        void eat(void);
        void hunger(void);
        void setFP(int);

        int getFP(void);

    private:
        int FoodPoint;
};

#endif