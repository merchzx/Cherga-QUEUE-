#include "Queue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Queue::Queue() : size(0), cap(10) {
    data = new int[cap];
}

Queue::~Queue() {
    delete[] data;
}

int Queue::pop() {
    if (IsEmpty()) {
        cout<<"Queue is empty!";
    }

    int result = data[0];
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size-=1;
    return result;
}

int Queue::top() {
    if (IsEmpty()) {
        cout<<"Queue is empty!";
    }
    return data[0];
}

void Queue::push(int value) {
    if (IsFull()) {
        resize();
    }
    data[size] = value;
    size+=1;
}

bool Queue::IsFull() {
    size == cap;
    return size;
}

bool Queue::IsEmpty() {
    size = 0;
    return size;

}

void Queue::print() {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

void Queue::resize() {
    cap *= 2;
    int* newData = new int[cap];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}