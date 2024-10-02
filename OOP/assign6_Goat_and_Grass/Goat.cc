#include "Goat.h"

Goat::Goat(int FP, int LT) : Creature(LT), FoodPoint(FP) {
    isMoved = true;
    is_childBirth = false;
    is_Dead = true;
}

void Goat::initStuation(){
    FoodPoint = 20;
    setLT(0);
    isMoved = true;
    is_childBirth = false;
    is_Dead = false;
}

void Goat::eat() {
    FoodPoint += 20;
}

void Goat::hunger() {
    --FoodPoint;
}

void Goat::setFP(int FP) {
    FoodPoint = FP;
}

int Goat::getFP() {
    return FoodPoint;
}