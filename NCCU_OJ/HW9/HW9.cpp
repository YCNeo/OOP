#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Orchestral {
    public:
        Orchestral(int, int, vector<double>);
        ~Orchestral() {}

        void assign();
        void print();

        int FindLargest();

    private:
        int p, n;

        vector<double> n_arr;
        vector<double> assignment;
        vector<double> assignP;
};

Orchestral::Orchestral(int p, int n, vector<double> arr)
    : p(p), n(n), n_arr(arr), assignment(arr) {
    for (int i = 0; i < n; ++i)
        assignP.push_back(1);
}

void Orchestral::assign() {
    for (int i = 0; i < p - n; ++i) {
        int LI = FindLargest();
        assignP[LI] += 1;
        assignment[LI] = n_arr[LI] / assignP[LI];
    }
}

int Orchestral::FindLargest() {
    int largest = 0, largestI = -1;
    for (int i = 0; i < n; ++i)
        if (assignment[i] > largest) {
            largest = assignment[i];
            largestI = i;
        }

    return largestI;
}

void Orchestral::print() {
    if (fmod(assignment[FindLargest()], 1.0) != 0)
        cout << (int)assignment[FindLargest()] + 1 << endl;
    else
        cout << (int)assignment[FindLargest()] << endl;
}

int main() {
    int p, n;
    while (scanf("%d %d", &p, &n) != EOF) {
        vector<double> arr;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        Orchestral Orc(p, n, arr);

        Orc.assign();
        Orc.print();
    }
    return 0;
}