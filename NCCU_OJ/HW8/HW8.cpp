#include <iostream>

using namespace std;

class App {
    public:
        App(int d) { download = d; }
        ~App(){};
        int getDownload() { return download; }
        void increaseDownload() { ++download; }

    private:
        int download;
};

class JJBox : public App {
    public:
        JJBox(int d) : App(d) { fresh(); }
        ~JJBox() {}
        void increaseDownload() { App::increaseDownload(); }
        void fresh() { Music_Num = App::getDownload() * 5; }
        int getMusic() { return Music_Num; }

    private:
        int Music_Num;
};

class Nosebook : public App {
    public:
        Nosebook(int d) : App(d) { fresh(); }
        ~Nosebook() {}
        void increaseDownload() { App::increaseDownload(); }
        void fresh() { Friend_Num = App::getDownload() * 3 + 5; }
        int getFriend() { return Friend_Num; }

    private:
        int Friend_Num;
};

int main() {
    int n1, n2, Operation;
    cin >> n1 >> n2;
    JJBox JJB(n1);
    Nosebook Nose(n2);
    while (true) {
        cin >> Operation;
        if (Operation == -1)
            break;
        switch (Operation) {
            case 1:
                JJB.increaseDownload();
                break;
            case 2:
                Nose.increaseDownload();
                break;
            case 3:
                JJB.increaseDownload();
                Nose.increaseDownload();
                break;
            case 4:
                JJB.fresh();
                break;
            case 5:
                Nose.fresh();
                break;
            default:
                break;
        }

        cout << "JJBox now has " << JJB.getMusic() << " songs." << endl
             << "NoseBook now has " << Nose.getFriend() << " friends." << endl
             << "==========" << endl;
    }

    return 0;
}