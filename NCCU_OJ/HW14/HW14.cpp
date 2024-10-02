#include <iostream>
#include <vector>

using namespace std;

void printStituation(char map[100][100], int ScaleX, int ScaleY, int x, int y) {
    cout << "***************" << endl;
    for (int j = ScaleY - 1; j >= 0; --j) {
        for (int i = 0; i < ScaleX; ++i) {
            cout << "+";
            if (x == i && y == j)        // determine where man is
                cout << "H";
            else
                cout << " ";

            if (map[i][j] == '0')        // determine if there is room
                cout << " ";
            else
                cout << map[i][j];
            cout << " ";
        }
        cout << "+" << endl;
    }
    cout << "***************" << endl;
}

int main() {
    char map[100][100] = {};
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            map[i][j] = '0';

    string name, description;
    char abbr;
    int n, id, posX, posY;
    int ScaleX = 0, ScaleY = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> name >> posX >> posY >> description >> abbr;
        map[posX][posY] = abbr;
        // final scale
        if (posX + 1 > ScaleX)
            ScaleX = posX + 1;
        if (posY + 1 > ScaleY)
            ScaleY = posY + 1;
    }

    int currX = 0, currY = 0;
    printStituation(map, ScaleX, ScaleY, currX, currY);        // man at (0, 0)

    char ins;
    for (int i = 0; i < 5; ++i) {
        cin >> ins;
        if (ins == 'n') {        // n -> (0, 1)
            if (currY + 1 < ScaleY)
                ++currY;
        } else if (ins == 'e') {        // e -> (1, 0)
            if (currX + 1 < ScaleX)
                ++currX;
        } else if (ins == 's') {        // s -> (0, -1)
            if (currY - 1 >= 0)
                --currY;
        } else if (ins == 'w') {        // w -> (-1, 0)
            if (currX - 1 >= 0)
                --currX;
        }

        printStituation(map, ScaleX, ScaleY, currX, currY);
    }

    return 0;
}