#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

struct ArrayList {
    int* arr;
    int capacity;
    int size;

    ArrayList(int cap = 100) : capacity(cap), size(0) {
        arr = new int[capacity];
    }
    ~ArrayList() { delete[] arr; }

    void insertFirst(int val) {
        if (size == capacity) throw out_of_range("List đầy");
        for (int i = size; i > 0; --i) arr[i] = arr[i - 1];
        arr[0] = val;
        size++;
    }

    void insertLast(int val) {
        if (size == capacity) throw out_of_range("List đầy");
        arr[size++] = val;
    }

    void insertN(int index, int val) {
        if (size == capacity) throw out_of_range("List đầy");
        if (index < 0 || index > size) throw out_of_range("Index không hợp lệ");
        for (int i = size; i > index; --i) arr[i] = arr[i - 1];
        arr[index] = val;
        size++;
    }

    int removeFirst() {
        if (size == 0) throw out_of_range("List rỗng");
        int val = arr[0];
        for (int i = 1; i < size; ++i) arr[i - 1] = arr[i];
        size--;
        return val;
    }

    int removeLast() {
        if (size == 0) throw out_of_range("List rỗng");
        return arr[--size];
    }

    int removeN(int index) {
        if (size == 0 || index < 0 || index >= size) throw out_of_range("Index không hợp lệ");
        int val = arr[index];
        for (int i = index; i < size - 1; ++i) arr[i] = arr[i + 1];
        size--;
        return val;
    }

    bool isEmpty() { return size == 0; }
};
