#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class detail {
    public:
        char type;
        string name;
        int x, y;
        double z;
        bool print = false;

        detail(char type, string name, int x, int y, double z)
            : type(type), name(name), x(x), y(y), z(z) {}
        ~detail() {}

    private:
};

vector<detail> vec;

bool cmpTYPE(detail a, detail b) {
    if (a.type == b.type) {
        if (a.type == 'P') {
            if (a.x == b.x) {
                if (a.type == 'P') {
                    if (a.y == b.y)
                        return a.z < b.z;
                    else
                        return a.y < b.y;
                } else if (a.type == 'B') {
                    if (a.y == b.y)
                        return a.z > b.z;
                    else
                        return a.y > b.y;
                }
            } else {
                return a.x > b.x;
            }
        } else if (a.type == 'B')
            if (a.x == b.x) {
                if (a.type == 'P') {
                    if (a.y == b.y)
                        return a.z < b.z;
                    else
                        return a.y < b.y;
                } else if (a.type == 'B') {
                    if (a.y == b.y)
                        return a.z > b.z;
                    else
                        return a.y > b.y;
                }
            } else {
                return a.x > b.x;
            }
    } else
        return a.type > b.type;
}

int main(void) {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int CASE;
        cin >> CASE;
        for (int j = 0; j < CASE; j++) {
            char t_type;
            string t_name;
            int t_x, t_y;
            double t_z;
            cin >> t_type >> t_name >> t_x >> t_y >> t_z;
            detail temp(t_type, t_name, t_x, t_y, t_z);
            vec.push_back(temp);
        }

        sort(vec.begin(), vec.end(), cmpTYPE);
        for (int j = 0; j < vec.size(); j++)
            cout << vec[j].type << " " << vec[j].name << endl;

        if (i < n - 1)
            cout << "=====" << endl;

        vec.clear();
    }
    return 0;
}