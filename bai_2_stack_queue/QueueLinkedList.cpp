#pragma once
#include "../linkedlist/LinkedList.cpp"

struct QueueLinkedList {
    LinkedList list;

    QueueLinkedList() {}
    QueueLinkedList(const QueueLinkedList&) = delete;
    QueueLinkedList& operator=(const QueueLinkedList&) = delete;

    void enqueue(int val) { list.insertLast(val); }

    int dequeue() { return list.removeFirst(); }

    int front() {
        if (list.isEmpty()) throw out_of_range("Queue rỗng");
        return list.head->data;
    }

    bool isEmpty() { return list.isEmpty(); }

    void print() {
        cout << "front -> ";
        for (Node* p = list.head; p != nullptr; p = p->next) cout << p->data << " ";
        cout << "<- back\n";
    }
};
