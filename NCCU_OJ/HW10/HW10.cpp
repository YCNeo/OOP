#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T add(T x, T y) {
    return x + y;
}

int main() {
    string TypeA, TypeB;
    float x, y, result;
    while (1) {
        cin >> TypeA;
        if (TypeA == "-1")
            break;
        cin >> x >> TypeB >> y;

        result = add(x, y);
        if ((result * 10) - (int)(result * 10) >= 0.5)
            result = (float)((int)(result * 10 + 1)) / 10;
        else if ((result * 10) - (int)(result * 10) < 0.5)
            result = (float)((int)(result * 10)) / 10;

        cout << "Sum: " << result << endl;
    }
    return 0;
}