//
// Created by Youssef Hesham on 27/10/2022.
//

#ifndef QUEUE_QUEUE_LL_H
#define QUEUE_QUEUE_LL_H
template <typename T>
class Node{
public:
    T item;
    Node* nxtPtr;
};

template <typename T>
class queue_LL {
private:
    Node<T>*head;
    Node<T>*tail;
    int size{};

public:
    queue_LL();
    void enqueue(T item);
    T dequeue();
    bool empty();
};




#endif //QUEUE_QUEUE_LL_H
