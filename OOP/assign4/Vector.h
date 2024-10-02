/* Copyright (c) 1996 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Vector.h
   PURPOSE
     Generic geometric vector
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Aug 27, 1996: Created.
***************************************************************************/

/* $Log:$ */

#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>

using namespace std;

// scalar multiplication
class Vector;
Vector operator*(double scale, Vector other);
Vector operator-(Vector other);

class Vector {
    public:
        // default constrcutor
        Vector();

        // construct a vector of the give dimension
        Vector(int dimension);

        // constructor for easier initialization
        Vector(int size, const double elements[]);

        // copy constructor
        Vector(const Vector& source);

        // destructor
        ~Vector();

        double length() const;

        double getElement(int) const;

        // get the dimension of the vector
        int getDimension() const;

        /**
         * set the dimension of the vector
         * vector is trucated if the new dimension is shorter than the current
         * one vector is copied over if the new dimension is longer
         */
        void setDimension(int dimension);

        /* operator overloading */
        Vector operator+(const Vector&);
        Vector operator-(const Vector&);
        Vector operator*(double);
        Vector& operator=(const Vector&);
        Vector& operator+=(const Vector&);
        Vector& operator-=(const Vector&);
        Vector& operator*=(double);
        bool operator==(const Vector&);
        bool operator!=(const Vector&);
        double operator[](int index);
        friend ostream& operator<<(ostream&, const Vector&);
        friend ostream& operator<<(ostream&, double);

    private:
        // initialization routine for allocating appropriate memory
        void initialize(int size);
        // current allocated number of elements >= fDimension
        int allocSize;
        // dimension of the vector
        int fDimension;
        // array of double for storing vector elements
        double* fElements;
};

#endif
