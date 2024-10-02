#include <iostream>

#include "Creature.h"

using namespace std;

#ifndef GRASS
#define GRASS

class Grass : public Creature {
    public:
        Grass(int);
        ~Grass() {}

        void initStuation(void);

    private:
};

#endif