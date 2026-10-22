#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

// 1. Queue dùng Array List
class QueueArray {
private:
    ArrayList list;
public:
    void enqueue(int val) { list.insertLast(val); }
    int dequeue() { return list.removeFirst(); } 
    bool isEmpty() { return list.isEmpty(); }
};

// 2. Queue dùng Linked List
class QueueLinked {
private:
    LinkedList list;
public:
    void enqueue(int val) { list.insertLast(val); }
    int dequeue() { return list.removeFirst(); }
    bool isEmpty() { return list.isEmpty(); }
};

#endif
