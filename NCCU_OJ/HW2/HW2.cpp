/*  測資
3
Amy Bob Kevin
Chatting Bob Amy
Chatting Amy Bob
Field_Game Amy Bob
Field_Game Bob Amy  */

#include <iostream>
using namespace std;

struct Relationship_Cheesy {
    int Relationship = 0;
    int CheesyTimes = 0; 
};

int n;
Relationship_Cheesy table[100][100];
string name_arr[100];

void NameCompare(int A, int B) {
    if(name_arr[A] <= name_arr[B])
        cout << name_arr[A] << " " << name_arr[B] << endl;
    else if(name_arr[A] > name_arr[B])
        cout << name_arr[B] << " " << name_arr[A] << endl;
}

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (table[i][j].Relationship >= 10 && table[j][i].Relationship >= 10) {
                NameCompare(i, j);
                return false;
            }
    return true;
}

int FindName(string name) {
    for (int i = 0; i < n; i++)
        if (name_arr[i] == name)
            return i;
    return -1;
}

void Chatting(int A, int B) {
    table[A][B].Relationship += 2;
    table[B][A].Relationship += 2;
}

void Field_Game(int A, int B) {
    table[A][B].Relationship += 3;
    table[B][A].Relationship += 3;
}

void Night_Education(int A, int B) {
    table[A][B].Relationship += 5;
    table[B][A].Relationship += 5;
}

void Cheesy_Joke(int A, int B) {
    table[A][B].Relationship += 2;
    table[A][B].CheesyTimes += 1;
    if (table[A][B].CheesyTimes >= 3){
        table[A][B].CheesyTimes = 0;
        table[B][A].Relationship = 0;
    }
}

int main(void) {
    cin >> n;
    
    for (int i = 0; i < n; i++)  cin >> name_arr[i];

    do {
        string action, NameA, NameB;
        cin >> action >> NameA >> NameB;
        int A = FindName(NameA), B = FindName(NameB);

        if (action[0] == 'C' && action[2] == 'a')   Chatting(A, B);
        else if (action[0] == 'F')  Field_Game(A, B);
        else if (action[0] == 'N')  Night_Education(A, B);
        else if (action[0] == 'C')  Cheesy_Joke(A, B);

    } while (check() == true);

    return 0;
}