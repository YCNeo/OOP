#include <iostream>

#include "Creature.h"

using namespace std;

Creature::Creature(int LifeTime) : LifeTime(LifeTime) {}

void Creature::increaseLT() {
    ++LifeTime;
}

void Creature::setLT(int LifeTimeI) {
    LifeTime = LifeTimeI;
}

int Creature::getLT() {
    return LifeTime;
}
