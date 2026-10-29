#include "stack/StackLinkedList.cpp"
#include "stack/StackArrayList.cpp"
#include "queue/QueueLinkedList.cpp"
#include "queue/QueueArrayList.cpp"

int main() {
    cout << "=== Stack dung LINKED LIST ===\n";
    StackLinkedList s1;
    s1.push(1); s1.push(2); s1.push(3);
    s1.print();
    cout << "top: " << s1.top() << "\n";
    cout << "pop: " << s1.pop() << "\n";
    s1.print();

    cout << "\n=== Stack dung ARRAY LIST ===\n";
    StackArrayList s2(10);
    s2.push(1); s2.push(2); s2.push(3);
    s2.print();
    cout << "top: " << s2.top() << "\n";
    cout << "pop: " << s2.pop() << "\n";
    s2.print();

    cout << "\n=== Queue dung LINKED LIST ===\n";
    QueueLinkedList q1;
    q1.enqueue(1); q1.enqueue(2); q1.enqueue(3);
    q1.print();
    cout << "front: " << q1.front() << "\n";
    cout << "dequeue: " << q1.dequeue() << "\n";
    q1.print();

    cout << "\n=== Queue dung ARRAY LIST ===\n";
    QueueArrayList q2(10);
    q2.enqueue(1); q2.enqueue(2); q2.enqueue(3);
    q2.print();
    cout << "front: " << q2.front() << "\n";
    cout << "dequeue: " << q2.dequeue() << "\n";
    q2.print();
    return 0;
}
