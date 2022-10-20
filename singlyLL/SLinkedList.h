//
// Created by youssef on 12/10/2022.
//

#ifndef SINGLYLL_SLINKEDLIST_H
#define SINGLYLL_SLINKEDLIST_H
template <typename T>
class Node{
public:
    T item;
    Node* nxtPtr;
};

template <typename T>
class SLinkedList {
private:
    Node<T>*head;
    Node<T>*tail;
    int size;

public:
    SLinkedList();
    int get_size();
    bool empty();
    void push_back(T item);
    void push_front(T item);
    void insert(T item, int index);
    T back();
    T front();
    T value_at(int index);
    T pop_back();
    T pop_front();
    void erase(int index);
    void remove_value(T item);
    void reverse();
};


#endif //SINGLYLL_SLINKEDLIST_H
