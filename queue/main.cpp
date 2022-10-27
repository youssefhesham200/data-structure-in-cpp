#include <iostream>
#include "queue_LL.cpp"
#include "queue_arr.cpp"

using namespace std;
int main() {
    //try queue using linked list
    queue_LL<int> queueLl;
    queueLl.enqueue(2);
    queueLl.enqueue(3);
    queueLl.enqueue(4);
    cout << queueLl.dequeue();
    cout << queueLl.dequeue();
    cout << queueLl.dequeue();
    cout << queueLl.empty();

    cout<<"\n";
    //try queue using fixed array
    queue_arr<int> queueArr(3);
    queueArr.enqueue(2);
    queueArr.enqueue(3);
    queueArr.enqueue(4);
    cout<<queueArr.full();
    cout << queueArr.dequeue();
    cout << queueArr.dequeue();
    cout << queueArr.dequeue();
    cout << queueArr.empty();
}
