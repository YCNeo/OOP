#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, vector<int>> azmap;

void buildMap() {
    char c;
    for (c = 'a'; c <= 'z'; c++) {
        int now = (int)c - 96;
        vector<int> vect;
        for (int i = 0; i < now; i++) {
            vect.push_back(i);
        }
        azmap[c] = vect;
    }
}

int findIndex(char token, int command, int element) {
    if (azmap.find(token) == azmap.end())
        return 0;        // Token not found

    vector<int>& arr = azmap[token];

    if (command == 0 || command == 1) {
        if (element >= arr.size())
            return 0;        // Out of bounds
        if (command == 1)
            reverse(arr.begin(), arr.end());
        auto it = find(arr.begin(), arr.end(), element);
        if (it != arr.end())
            return distance(arr.begin(), it);
    } else if (command == 2) {
        vector<int> evenNumbers;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0)
                evenNumbers.push_back(arr[i]);
        }
        sort(evenNumbers.begin(), evenNumbers.end());
        if (element > evenNumbers.size())
            return 0;        // Out of bounds
        else
            for (int i = 0; i < evenNumbers.size(); i++)
                if (i == element - 1)
                    return evenNumbers[i];
    }

    return 0;
}

int main() {
    buildMap();

    vector<int> results;

    char token;
    int command, element;
    while (cin >> token >> command >> element) {
        int result = findIndex(token, command, element);
        // cout << result << endl;
        results.push_back(result);
    }

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}
