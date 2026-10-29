#ifndef HASH_TABLE_ARRAY_LIST_H
#define HASH_TABLE_ARRAY_LIST_H
#include "List.h"
struct HashTableArrayList {
    ArrayList** buckets;               
    int M;                              

    HashTableArrayList(int m = 11, int bucketCap = 10) : M(m) {
        buckets = new ArrayList*[M];
        for (int i = 0; i < M; i++)
            buckets[i] = new ArrayList(bucketCap);   
    }
    ~HashTableArrayList() {
        for (int i = 0; i < M; i++) delete buckets[i];
        delete[] buckets;
    }
    HashTableArrayList(const HashTableArrayList&) = delete;
    HashTableArrayList& operator=(const HashTableArrayList&) = delete;

    int hash(int key) {
        int h = key % M;
        return h < 0 ? h + M : h;
    }

    bool insert(int key) {
        ArrayList* b = buckets[hash(key)];
        if (b->indexOf(key) != -1) return false;     
        if (b->size == b->capacity) return false;  
        b->insertLast(key);
        return true;
    }

    bool search(int key) {
        return buckets[hash(key)]->indexOf(key) != -1;
    }

    bool remove(int key) {
        ArrayList* b = buckets[hash(key)];
        int idx = b->indexOf(key);
        if (idx == -1) return false;
        b->removeN(idx);                             
        return true;
    }

    void print() {
        for (int i = 0; i < M; i++) {
            cout << "[" << i << "] ";
            for (int j = 0; j < buckets[i]->size; j++)   
                cout << buckets[i]->arr[j] << " | ";
            cout << "\n";
        }
    }
};

#endif
