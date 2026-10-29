#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (!isEmpty()) removeFirst();
    }

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertN(int index, int val) {
        if (index < 0) throw out_of_range("Index không hợp lệ");
        if (index == 0) {
            insertFirst(val);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!curr) throw out_of_range("Index vượt quá kích thước danh sách");
            curr = curr->next;
        }
        if (!curr) throw out_of_range("Index vượt quá kích thước danh sách");

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        if (newNode->next == nullptr) tail = newNode;
    }

    int removeFirst() {
        if (!head) throw out_of_range("List rỗng");
        int val = head->data;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        return val;
    }

    int removeLast() {
        if (!head) throw out_of_range("List rỗng");
        if (head == tail) return removeFirst();
        Node* curr = head;
        while (curr->next != tail) curr = curr->next;
        int val = tail->data;
        delete tail;
        tail = curr;
        tail->next = nullptr;
        return val;
    }

    int removeN(int index) {
        if (!head || index < 0) throw out_of_range("Index không hợp lệ hoặc List rỗng");
        if (index == 0) return removeFirst();
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!curr->next) throw out_of_range("Index vượt quá kích thước danh sách");
            curr = curr->next;
        }
        Node* temp = curr->next;
        if (!temp) throw out_of_range("Index vượt quá kích thước danh sách");

        int val = temp->data;
        curr->next = temp->next;
        if (temp == tail) tail = curr;
        delete temp;
        return val;
    }

    bool isEmpty() { return head == nullptr; }
};
