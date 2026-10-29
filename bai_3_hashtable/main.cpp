#include "HashTableLinkedList.h"
#include "HashTableArrayList.h"

int main() {
    int keys[] = {10, 15, 20, 7, 12, 3};    

    cout << "=== Hash table dung LINKED LIST ===\n";
    HashTableLinkedList h1(5);
    for (int k : keys) h1.insert(k);
    h1.print();
    cout << "search(15): " << (h1.search(15) ? "co" : "khong") << "\n";
    h1.remove(15);
    cout << "search(15) sau xoa: " << (h1.search(15) ? "co" : "khong") << "\n";
    h1.print();

    cout << "\n=== Hash table dung ARRAY LIST ===\n";
    HashTableArrayList h2(5, 4);             
    for (int k : keys) h2.insert(k);
    h2.print();
    cout << "search(20): " << (h2.search(20) ? "co" : "khong") << "\n";
    h2.remove(20);
    cout << "search(20) sau xoa: " << (h2.search(20) ? "co" : "khong") << "\n";
    h2.print();
    return 0;
}
