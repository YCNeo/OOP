#include <iostream>

#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue() : initialized(false), next(nullptr) {}

template <class T>
Queue<T>::Queue(T input) : element(input), initialized(true), next(nullptr) {}

template <class T>
Queue<T>::Queue(const Queue<T>& other)
    : element(other.element),
      initialized(other.initialized),
      next(other.next) {}

template <class T>
void Queue<T>::enqueue(T input) {
    try {
        Queue<T>* head = this;
        while (1) {
            if (head->next == nullptr) {
                Queue<T>* temp = new Queue<T>(input);
                head->next = temp;
                break;
            } else
                head = head->next;
        }
    } catch (exception& e) {
        cout << "exception: " << e.what() << endl;
    }
}

template <class T>
int Queue<T>::dequeue() {
    Queue<T>* head = this;
    while (1) {
        if (!head->initialized)
            head = head->next;
        cout << head->element << endl;
        if (head->next != nullptr)
            head = head->next;
        else
            return 1;
    }
    return 0;
}

// operator
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    element = other.element;
    initialized = other.initialized;
    next = other.next;
    return *this;
}