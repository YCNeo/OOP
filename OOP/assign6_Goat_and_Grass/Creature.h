#include <iostream>

using namespace std;

#ifndef CREATURE
#define CREATURE

class Creature {
    public:
        Creature(int);
        ~Creature() {}

        void increaseLT(void);
        void setLT(int);

        int getLT(void);

        bool isMoved;
        bool is_childBirth;
        bool is_Dead;

    private:
        int LifeTime;
};

#endif