#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdexcept>
using namespace std;
// 1. Cấu trúc Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    LinkedList() : head(nullptr), tail(nullptr) {}

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
        if (index < 0) throw std::out_of_range("Index không hợp lệ");
        if (index == 0) {
            insertFirst(val);
            return;
        }
        
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!curr) throw std::out_of_range("Index vượt quá kích thước danh sách");
            curr = curr->next;
      }
        
        if (!curr) throw std::out_of_range("Index vượt quá kích thước danh sách");
        
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        if (newNode->next == nullptr) tail = newNode; 
    }

    int removeFirst() {
        if (!head) throw std::out_of_range("List rỗng");
        int val = head->data;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        return val;
    }

    int removeLast() {
        if (!head) throw std::out_of_range("List rỗng");
        if (head == tail) return removeFirst(); 
        
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        
        int val = tail->data;
        delete tail;
        tail = curr;
        tail->next = nullptr;
        return val;
    }

    int removeN(int index) {
        if (!head || index < 0) throw std::out_of_range("Index không hợp lệ hoặc List rỗng");
        if (index == 0) return removeFirst();
        
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!curr->next) throw std::out_of_range("Index vượt quá kích thước danh sách");
            curr = curr->next;
        }
        
        Node* temp = curr->next;
        if (!temp) throw std::out_of_range("Index vượt quá kích thước danh sách");
        
        int val = temp->data;
        curr->next = temp->next;
        if (temp == tail) tail = curr; 
        delete temp;
        return val;
    }
    
    bool isEmpty() { return head == nullptr; }
};

// 2. Cấu trúc Array List (List mảng tĩnh)
class ArrayList {
private:
    int* arr;
    int capacity;
    int size;
public:
    ArrayList(int cap = 100) : capacity(cap), size(0) {
        arr = new int[capacity];
    }
    ~ArrayList() { delete[] arr; }

    void insertFirst(int val) {
        if (size == capacity) throw std::out_of_range("List đầy");
        for (int i = size; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        size++;
    }

    void insertLast(int val) {
        if (size == capacity) throw std::out_of_range("List đầy");
        arr[size++] = val;
    }

    void insertN(int index, int val) {
        if (size == capacity) throw std::out_of_range("List đầy");
        if (index < 0 || index > size) throw std::out_of_range("Index không hợp lệ");
        
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1]; 
        }
        arr[index] = val;
        size++;
    }

    int removeFirst() {
        if (size == 0) throw std::out_of_range("List rỗng");
        int val = arr[0];
        for (int i = 1; i < size; ++i) {
            arr[i - 1] = arr[i]; 
        }
        size--;
        return val;
    }

    int removeLast() {
        if (size == 0) throw std::out_of_range("List rỗng");
        return arr[--size];
    }

    int removeN(int index) {
        if (size == 0 || index < 0 || index >= size) throw std::out_of_range("Index không hợp lệ");
        int val = arr[index];
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1]; 
        }
        size--;
        return val;
    }

    bool isEmpty() { return size == 0; }
};

#endif
