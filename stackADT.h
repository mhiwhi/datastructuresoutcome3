#ifndef STACKADT_H
#define STACKADT_H

class StackADT {
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual void display() = 0;
    virtual ~StackADT() {}
};

#endif