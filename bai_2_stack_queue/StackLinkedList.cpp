#pragma once
#include "../linkedlist/LinkedList.cpp"

struct StackLinkedList {
    LinkedList list;

    StackLinkedList() {}
    StackLinkedList(const StackLinkedList&) = delete;
    StackLinkedList& operator=(const StackLinkedList&) = delete;

    void push(int val) { list.insertFirst(val); }

    int pop() { return list.removeFirst(); }

    int top() {
        if (list.isEmpty()) throw out_of_range("Stack rỗng");
        return list.head->data;
    }

    bool isEmpty() { return list.isEmpty(); }

    void print() {
        cout << "top -> ";
        for (Node* p = list.head; p != nullptr; p = p->next) cout << p->data << " ";
        cout << "\n";
    }
};
