#ifndef STACK_H
#define STACK_H
#include "List.h"

// 1. Stack dùng Array List
class StackArray {
private:
    ArrayList list;
public:
    void push(int val) { list.insertLast(val); }
    int pop() { return list.removeLast(); }
    bool isEmpty() { return list.isEmpty(); }
};

// 2. Stack dùng Linked List
class StackLinked {
private:
    LinkedList list;
public:
    void push(int val) { list.insertFirst(val); } 
    int pop() { return list.removeFirst(); }      
    bool isEmpty() { return list.isEmpty(); }
};

#endif
