#pragma once

class Queue {
private:
    int* data;
    int size;
    int cap;
    void resize();
public:
    Queue();
    ~Queue();
    int pop();
    int top();
    void push(int value);
    bool IsFull();
    bool IsEmpty();
    void print();
};