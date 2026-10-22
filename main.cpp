#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main() {
    cout << "\n--- TEST STACK ---\n";
    StackArray sArr;
    sArr.push(100);
    sArr.push(200);
    cout << "Stack Array pop: " << sArr.pop() << "\n";

    StackLinked sLink;
    sLink.push(300);
    sLink.push(400);
    cout << "Stack Linked pop: " << sLink.pop() << "\n";

    cout << "\n--- TEST QUEUE ---\n";
    QueueArray qArr;
    qArr.enqueue(11);
    qArr.enqueue(22);
    cout << "Queue Array dequeue: " << qArr.dequeue() << "\n";

    QueueLinked qLink;
    qLink.enqueue(33);
    qLink.enqueue(44);
    cout << "Queue Linked dequeue: " << qLink.dequeue() << "\n";

    return 0;
}
