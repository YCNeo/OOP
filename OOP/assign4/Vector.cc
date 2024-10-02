#include <cmath>
#include <iostream>

#include "Vector.h"

Vector operator*(double scale, Vector other) {
    double arr[other.getDimension()];
    for (int i = 0; i < other.getDimension(); i++)
        arr[i] = scale * other.getElement(i);
    Vector result(other.getDimension(), arr);
    return result;
}

Vector operator-(Vector other) {
    double arr[other.getDimension()];
    for (int i = 0; i < other.getDimension(); i++)
        arr[i] = -other.getElement(i);
    Vector result(other.getDimension(), arr);
    return result;
}

Vector::Vector() : allocSize(2), fDimension(2) {
    initialize(2);
    for (int i = 0; i < 2; i++)
        fElements[i] = 0;
}

Vector::Vector(int demension) : allocSize(demension), fDimension(demension) {
    initialize(demension);
    for (int i = 0; i < fDimension; i++)
        fElements[i] = 0;
}

Vector::Vector(int size, const double element[])
    : allocSize(size), fDimension(size) {
    initialize(size);
    for (int i = 0; i < size; i++)
        fElements[i] = element[i];
}

Vector::Vector(const Vector& source)
    : allocSize(source.allocSize),
      fDimension(source.fDimension),
      fElements(source.fElements) {}

Vector::~Vector() {}

double Vector::length() const {
    double total = 0;
    for (int i = 0; i < fDimension; ++i)
        total += pow(fElements[i], 2);
    return sqrt(total);
}

double Vector::getElement(int i) const {
    return fElements[i];
}

int Vector::getDimension() const {
    return fDimension;
}

void Vector::setDimension(int dimension) {
    double* fElements_temp = new double[dimension];
    for (int i = 0; i < dimension; ++i) {
        if (i < fDimension)
            fElements_temp[i] = fElements[i];
        else
            fElements_temp[i] = 0;
    }
    fElements = fElements_temp;
    fDimension = dimension;
}

void Vector::initialize(int size) {
    fElements = new double[size];
}

/*
    operator overloading
*/
Vector Vector::operator+(const Vector& other) {
    Vector result(this->getDimension());
    for (int i = 0; i < result.fDimension; ++i)
        result.fElements[i] = this->fElements[i] + other.fElements[i];
    return result;
}

Vector Vector::operator-(const Vector& other) {
    Vector result(this->getDimension());
    for (int i = 0; i < result.fDimension; ++i)
        result.fElements[i] = this->fElements[i] - other.fElements[i];
    return result;
}

Vector Vector::operator*(double scale) {
    Vector result(this->getDimension());
    for (int i = 0; i < result.fDimension; ++i)
        result.fElements[i] = scale * this->fElements[i];
    return result;
}

Vector& Vector::operator=(const Vector& other) {
    allocSize = other.allocSize;
    fDimension = other.fDimension;
    for (int i = 0; i < fDimension; ++i)
        fElements[i] = other.fElements[i];
    return *this;
}

Vector& Vector::operator+=(const Vector& other) {
    for (int i = 0; i < this->fDimension; ++i)
        this->fElements[i] += other.fElements[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    for (int i = 0; i < this->fDimension; ++i)
        this->fElements[i] -= other.fElements[i];
    return *this;
}

Vector& Vector::operator*=(double value) {
    for (int i = 0; i < this->fDimension; ++i)
        this->fElements[i] *= value;
    return *this;
}

bool Vector::operator==(const Vector& other) {
    for (int i = 0; i < this->fDimension; ++i) {
        if (this->fElements[i] != other.fElements[i])
            return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& other) {
    for (int i = 0; i < this->fDimension; ++i) {
        if (this->fElements[i] == other.fElements[i])
            return false;
    }
    return true;
}

double Vector::operator[](int index) {
    return this->getElement(index);
}

ostream& operator<<(ostream& os, const Vector& other) {
    os << "(";
    for (int i = 0; i < other.fDimension; ++i) {
        if (i < other.fDimension - 1)
            os << other.fElements[i] << ", ";
        else
            os << other.fElements[i] << ")";
    }
    return os;
}

ostream& operator<<(ostream& os, double value) {
    os << (char)value;
    return os;
}
