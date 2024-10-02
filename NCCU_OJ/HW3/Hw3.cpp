/* 測資
6
8 1 1 1 8
8 8 1 1 8
8 1 8 1 8
8 1 1 8 8
8 1 1 1 8

8 8 8 8 1
8 1 1 1 8
8 8 8 8 1
8 1 1 1 1
8 1 1 1 1

1 8 8 8 1
8 1 1 1 1
1 8 8 8 1
1 1 1 1 8
8 8 8 8 1

1 8 8 8 1
8 1 1 1 1
8 1 1 1 1
8 1 1 1 1
1 8 8 8 1

1 1 8 1 1
1 1 8 1 1
1 1 8 1 1
1 1 1 1 1
1 1 8 1 1

1 1 8 1 1
1 1 8 1 1
1 1 8 1 1
1 1 1 1 1
1 1 8 1 1
*/

#include <iostream>

using namespace std;

struct motion{
    int play[5][5];
};

int check(int x, int y, motion LaLa[]){
    double total = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(LaLa[x].play[i][j] == LaLa[y].play[i][j] && LaLa[x].play[i][j] == 8)     
                total += 5;
            else if(LaLa[x].play[i][j] == LaLa[y].play[i][j] && LaLa[x].play[i][j] == 1)    
                total += 1;
            else if(LaLa[x].play[i][j] > LaLa[y].play[i][j])    
                total += 2;
            else
                total += 7;
        }
    }
    return total;
}

int main(void){
    int n;
    motion Show[1000];
    
    cin >> n;

    for(int count = 0; count < n; ++count){
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                cin >> Show[count].play[i][j];
        if (count >= 1)
            cout << check(count-1, count, Show) << endl;
    }

    return 0;
}

///////不曉得為甚麼只有以下會過
#include <iostream>

using namespace std;

int cmp(int a, int b){
    if(a == b && a == 8)        return 5;
    else if(a == b && a == 1)   return 1;
    else if(a > b)              return 2;
    else                        return 7;
}

int main(void) {
    int n, show_CURR[5][5], show_NEXT[5][5];

    cin >> n;

    for(int count = 0; count < n; ++count){
        int total = 0;
        if(count == 0){
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j)
                    cin >> show_CURR[i][j];
        }
        else{
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j){
                    cin >> show_NEXT[i][j];
                    total += cmp(show_CURR[i][j], show_NEXT[i][j]);
                    show_CURR[i][j] = show_NEXT[i][j];
                }
            cout << total << endl;
        }
    }
    return 0;
}
