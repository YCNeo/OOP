#include <iostream>

using namespace std;

int main(void) {
    int total = 0;
    for(int i = 1000; i < 10000; i++)
        if(i % 4 == 0 || i % 5 == 0 || i % 7 == 0 || i % 20 == 0 || i % 28 == 0 || i % 35 == 0 || i % 140 == 0)
            total++;
    cout << total << endl;
    return 0;
}