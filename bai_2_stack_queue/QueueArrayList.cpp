#pragma once
#include "../list/ArrayList.cpp"

struct QueueArrayList {
    ArrayList list;

    QueueArrayList(int cap = 100) : list(cap) {}
    QueueArrayList(const QueueArrayList&) = delete;
    QueueArrayList& operator=(const QueueArrayList&) = delete;

    void enqueue(int val) { list.insertLast(val); }

    int dequeue() { return list.removeFirst(); }

    int front() {
        if (list.isEmpty()) throw out_of_range("Queue rỗng");
        return list.arr[0];
    }

    bool isEmpty() { return list.isEmpty(); }

    void print() {
        cout << "front -> ";
        for (int i = 0; i < list.size; i++) cout << list.arr[i] << " ";
        cout << "<- back\n";
    }
};
