/*  test case
2
3 3
Super 51 65 73
Jeff 80 80 92
ZWei 67 87 20
4 5
Yu 72 83 82 84 29
QQ 29 39 21 16 72
ZZZZ 78 82 91 84 77
GG 57 76 82 99 48
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class subjects{
    private:
    int grade;

    public:
    friend class students;
    subjects(int int_gra) { grade = int_gra ;}
    ~subjects() {}
    int getGrade() { return grade; }
};

class students{
    private:
    string name;
    vector<subjects> sub;
    double average;

    public:
    students(string input_name, vector<subjects> vec, double input_average) {
        name = input_name;
        sub = vec;
        average = input_average;
    }
    ~students() {}
    int getAver() { return average; }
    void setName(string input_name) { this->name = input_name; }
    void setGrade(subjects grade) { sub.push_back(grade); }
    void print();
    void g_sort();
};

bool comp1(students a, students b) {
    return a.getAver() > b.getAver();
}

bool comp2(subjects a, subjects b) {
    return a.getGrade() > b.getGrade();
}

void students::g_sort() {
    sort(sub.begin(), sub.end(), comp2);
}

void students::print() {
    cout << name << ":";
    for(int i = 0; i < (this->sub).size(); i++)
        cout << sub[i].getGrade() << " ";
    cout << average << endl;
} 


int main(){
    int n, C1, C2;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<students> stud;
        cin >> C1 >> C2;
        for(int j = 0; j < C1; j++){
            double temp_average = 0;
            string temp_name;
            cin >> temp_name;
            vector<subjects> temp_vec;
            
            for(int k = 0; k < C2; k++){
                double temp_grade;
                cin >> temp_grade;
                subjects t_grade(temp_grade);
                temp_average += temp_grade;
                temp_vec.push_back(t_grade);
                // t_grade.~subjects();
            }
            students temp_stud(temp_name, temp_vec, temp_average/C2);
            temp_stud.g_sort();
            stud.push_back(temp_stud);
            // temp_vec.~vector();
            // temp_stud.~students();
        }
        sort(stud.begin(), stud.end(), comp1);
        for(int j = 0; j < stud.size(); j++)
            stud[j].print();
        cout << "==========" << endl;
        // stud.~vector();
    }
    return 0;
}