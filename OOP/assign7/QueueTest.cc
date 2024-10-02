/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE

   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

#include <fstream>
#include <iostream>
#include "AnsiPrint.h"
#include "Queue.cc"

using namespace std;

/**
 * Print my id
 */

void PrintMyID(const char* studId) {
    char* str = new char[strlen(studId) + 5];
    sprintf(str, "ID: %s", studId);
    AnsiPrint(str, yellow, red, true, true);
    cout << endl;
    delete[] str;
}

/**
 * PrintUsage
 */

void PrintUsage(const char* progName) {
    assert(progName);
    cout << "Usage: " << progName << " intfile [charfile]" << endl;
}

int main(int argc, char** argv) {
    istream *is1 = &cin, *is2 = &cin;

    if (argc > 3 || argc == 1) {
        PrintUsage(argv[0]);
        exit(-1);
    } else if (argc > 2) {
        is2 = new ifstream(argv[2]);
        if (!(*is2)) {
            cerr << "Can't open file " << argv[2] << endl;
            exit(1);
        }
    }
    if (argc > 1) {
        is1 = new ifstream(argv[1]);
        if (!(*is1)) {
            cerr << "Can't open file " << argv[1] << endl;
            exit(2);
        }
    }

    // You need to provide testing exercises here

    const char* PIQ = {"Integer Queue:"};
    const char* PCQ = {"Character Queue:"};
    const char* DEEQ = {"Attempt to dequeue empty queue"};

    bool DMQ = false;

    AnsiPrint(PIQ, yellow, black, true, true);
    cout << endl;

    // test integer queue
    Queue<int>* myIntQPtr = new Queue<int>;
    // enqueue exercises on myIntQPtr
    int number;
    while (*is1 >> number)
        myIntQPtr->enqueue(number);

    // test copy constructor
    Queue<int> myIntQ = *myIntQPtr;
    // test destructor
    delete myIntQPtr;
    // dequeue exercises on myIntQ
    DMQ += myIntQ.dequeue();

    AnsiPrint(PCQ, yellow, black, true, true);
    cout << endl;
    // test character queue
    Queue<char> myCharQ, myCharQ1;
    // enqueue exercises on myCharQ
    char ch;
    while (*is2 >> ch)
        myCharQ.enqueue(ch);

    // test assignment operator
    myCharQ1 = myCharQ;
    // dequeue exercise on myCharQ1
    DMQ += myCharQ1.dequeue();

    if (DMQ) {
        AnsiPrint(DEEQ, red, yellow, true, true);
        cout << endl;
    }

    PrintMyID("110703013");
    return 0;
}
