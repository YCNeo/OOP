#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {0, 2, 6, 9, 99, 8, 0};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    cout << fmod((1.0 / 2.0), 1.0) << endl;
    return 0;
}