/*  測資
4
0 bedroom 0 0 CanSleepingHere Sophomore
1 livingRoom 0 1 CanWatchTV Junior
2 GameRoom 0 2 PlayGame Senior
3 bedroom 1 0 CanSnoozingHere Freshman
n n n
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ROOM{
    public:
        int x, y;

        ROOM(int R_id, string R_name, int R_x, int R_y, string R_description, string R_forWho);
        ~ROOM(){}

        static int check(char dir, int C_x, int C_y, int c_scale, int count);
        static int find(int scale, int f_x, int f_y);
        void R_print();

    private:
        int id;
        string name, description, forWho;
};

vector<ROOM> vec;

ROOM::ROOM(int R_id, string R_name, int R_x, int R_y, string R_description, string R_forWho){
    id = R_id;
    x = R_x;
    y = R_y;
    name = R_name;
    description = R_description;
    forWho = R_forWho;
}

void ROOM::R_print(){
    cout << "Room#" << id << "\n" << name << "\n(" << x << "," << y << ")\n" << description << "\n" << forWho << "\n********************" << endl;
}

int ROOM::check(char dir, int C_x, int C_y, int C_scale, int count){
    if(dir == 'n')  C_y++;
    else if(dir == 's') C_y--;
    else if(dir == 'e') C_x++;
    else if(dir == 'w') C_x--;

    if(ROOM::find(C_scale, C_x, C_y) == -1 && count < C_scale){
        // cout << "C_x = " << C_x << ", C_y = " << C_y << ", count = " << count << endl << endl;
        count++;
        return ROOM::check(dir, C_x, C_y, C_scale, count);
    }
    else    return ROOM::find(C_scale, C_x, C_y);
}

int ROOM::find(int scale, int f_x, int f_y){
    for(int i = 0; i < scale; i++)
        if(vec[i].x == f_x && vec[i].y == f_y)
            return i;
    
    return -1;
}

int main(void){
    int n;
    char direction[3];

    // input
    cin >> n;
    for(int i = 0; i < n; i++){
        int Tid, Tx, Ty;
        string Tname, Tdescription, TforWho;
        cin >> Tid >> Tname >> Tx >> Ty >> Tdescription >> TforWho;
        ROOM temp(Tid, Tname, Tx, Ty, Tdescription, TforWho);
        vec.push_back(temp);
    }
    cin >> direction[0] >> direction[1] >> direction[2];
    
    int record = ROOM::find(n, 0, 0);
    vec[record].R_print();
    
    for(int i = 0; i < 3; ++i){
        if(ROOM::check(direction[i], vec[record].x, vec[record].y, n, 0) == -1)    vec[record].R_print();
        else{
            record = ROOM::check(direction[i], vec[record].x, vec[record].y, n, 0);
            vec[record].R_print();
            // printf("record = %d\n\n", record);
        }
    }

    return 0;
}