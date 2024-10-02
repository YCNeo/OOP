#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
#include <iostream>

#include "AnsiPrint.h"

template <class T>
class Queue {
    public:
        Queue();
        Queue(T input);
        Queue(const Queue<T>&);
        ~Queue() {}

        void enqueue(T);
        int dequeue();

        // operator
        Queue<T>& operator=(const Queue<T>&);

    private:
        bool initialized;
        T element;

        Queue<T>* next;
};

#endif        // QUEUE_H