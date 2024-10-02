#include <iostream>

using namespace std;

class Complex {
    private:
        double ration;
        double irration;

    public:
        Complex() {}
        Complex(int x, int y) : ration(x), irration(y) {}
        Complex operator+(const Complex&);
        Complex operator-(const Complex&);
        Complex operator*(const Complex&);      // define *
        Complex& operator++();                  // 定義 ++（前置） 如++p
        Complex operator++(int);                // 定義 ++（後置） 如p++
        Complex& operator--();
        Complex operator--(int);
        Complex& operator+=(Complex&);          // define +=
        Complex& operator-=(Complex&);
        bool operator==(const Complex&);        // define ==
        bool operator<(const Complex&);         // define <
        bool operator>(const Complex&);         // define >
        friend ostream& operator<<(ostream&,
                                   const Complex&);            // define cout
        friend istream& operator>>(istream&, Complex&);        // define cin
};

Complex Complex::operator+(const Complex& other) {
    Complex result(this->ration + other.ration,
                   this->irration + other.irration);
    return result;
}

Complex Complex::operator-(const Complex& other) {
    Complex result(this->ration - other.ration,
                   this->irration - other.irration);
    return result;
}

Complex Complex::operator*(const Complex& other) {
    Complex result(
        (this->ration * other.ration) - (this->irration * other.irration),
        (this->ration * other.irration )+ (this->irration * other.ration));
    return result;
}

Complex& Complex::operator++() {        // ++i: ++ then return
    this->ration++;
    this->irration++;
    return *this;
}

Complex Complex::operator++(int) {        // i++: return then ++
    Complex result = (*this);
    this->operator++();
    return result;
}

Complex& Complex::operator--() {
    this->ration--;
    this->irration--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex result = (*this);
    this->operator--();
    return result;
}

Complex& Complex::operator+=(Complex& other) {
    this->ration += other.ration;
    this->irration += other.irration;
    return *this;
}

Complex& Complex::operator-=(Complex& other) {
    this->ration -= other.ration;
    this->irration -= other.irration;
    return *this;
}

bool Complex::operator==(const Complex& other) {
    return (this->ration == other.ration && this->irration == other.irration)
               ? true
               : false;
}

bool Complex::operator>(const Complex& other) {
    if (this->ration > other.ration)
        return true;
    else if (this->ration == other.ration && this->irration > other.irration)
        return true;
    else
        return false;
}

bool Complex::operator<(const Complex& other) {
    if (this->ration < other.ration)
        return true;
    else if (this->ration == other.ration && this->irration < other.irration)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& os, const Complex& Complex) {
    if (Complex.irration < 0)
        os << Complex.ration << Complex.irration << "i";
    else
        os << Complex.ration << "+" << Complex.irration << "i";
    return os;
}

istream& operator>>(istream& is, Complex& Complex) {
    is >> Complex.ration >> Complex.irration;
    return is;
}

int main() {
    Complex C1, C2;
    while (cin >> C1 >> C2) {
        cout << "C1 = " << C1 << endl;
        cout << "C2 = " << C2 << endl;

        cout << "C1==C2? " << ((C1 == C2) ? "true" : "false") << endl;
        cout << "C1<C2?  " << ((C1 < C2) ? "true" : "false") << endl;
        cout << "C1>C2?  " << ((C1 > C2) ? "true" : "false") << endl;

        cout << "C1+C2 = " << C1 + C2 << endl;
        cout << "C1-C2 = " << C1 - C2 << endl;
        cout << "C1*C2 = " << C1 * C2 << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "--C2  = " << --C2 << endl;
        cout << "--C2  = " << --C2 << endl;

        C1 += C2;
        cout << "C1+=C2  " << C1 << endl;
        cout << "==============" << endl;
    }
    return 0;
}