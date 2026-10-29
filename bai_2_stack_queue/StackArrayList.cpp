#pragma once
#include "../list/ArrayList.cpp"

struct StackArrayList {
    ArrayList list;

    StackArrayList(int cap = 100) : list(cap) {}
    StackArrayList(const StackArrayList&) = delete;
    StackArrayList& operator=(const StackArrayList&) = delete;

    void push(int val) { list.insertLast(val); }

    int pop() { return list.removeLast(); }

    int top() {
        if (list.isEmpty()) throw out_of_range("Stack rỗng");
        return list.arr[list.size - 1];
    }

    bool isEmpty() { return list.isEmpty(); }

    void print() {
        cout << "top -> ";
        for (int i = list.size - 1; i >= 0; i--) cout << list.arr[i] << " ";
        cout << "\n";
    }
};
