#ifndef HASH_TABLE_LINKED_LIST_H
#define HASH_TABLE_LINKED_LIST_H
#include "List.h"

struct HashTableLinkedList {
    LinkedList* buckets;                
    int M;                              

    HashTableLinkedList(int m = 11) : M(m) {
        buckets = new LinkedList[M];   
    }
    ~HashTableLinkedList() {
        delete[] buckets;               
    }
    HashTableLinkedList(const HashTableLinkedList&) = delete;         
    HashTableLinkedList& operator=(const HashTableLinkedList&) = delete;

    int hash(int key) {
        int h = key % M;                
        return h < 0 ? h + M : h;     
    }

    bool insert(int key) {
        LinkedList& b = buckets[hash(key)];    
        if (b.indexOf(key) != -1) return false; 
        b.insertLast(key);                     
        return true;
    }

    bool search(int key) {
        return buckets[hash(key)].indexOf(key) != -1;  
    }

    bool remove(int key) {
        LinkedList& b = buckets[hash(key)];
        int idx = b.indexOf(key);              
        if (idx == -1) return false;           
        b.removeN(idx);                        
        return true;
    }

    void print() {
        for (int i = 0; i < M; i++) {
            cout << "[" << i << "] ";
            for (Node* p = buckets[i].head; p != nullptr; p = p->next)
                cout << p->data << " -> ";
            cout << "NULL\n";
        }
    }
};

#endif
