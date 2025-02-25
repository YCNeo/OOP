/**
 * File: Hello.cc
 * Purpose: Sample program for the OOP class
 * Author: Tsai-Yen Li (li@cs.nccu.edu.tw) 8/28/96
 *         (You need put your ID here as well.)
 */

#include "Hello.h"
#include <iostream>

// constant string definition
const char* kHelloMessage = "Hello, C++ World:q.\n";

/**
 * A function that prints "Hello" greeting message
 */

void PrintHello() {
    std::cout << kHelloMessage;
}
