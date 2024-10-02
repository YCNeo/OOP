#include "Grass.h"

Grass::Grass(int LT) : Creature(LT) {
    isMoved = true;
}

void Grass::initStuation() {
    setLT(0);
    isMoved = true;
    is_childBirth = false;
    is_Dead = false;
}
