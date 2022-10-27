//
// Created by Youssef Hesham on 27/10/2022.
//
#include "queue_LL.h"
#include <stdexcept>

template<typename T>
queue_LL<T>::queue_LL() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void queue_LL<T>::enqueue(T item) {
    auto * ptr = new Node<T>;
    ptr->item = item;

    if(head == nullptr){
        head = tail = ptr;
    } else{
        tail->nxtPtr = ptr;
        tail = ptr;
    }

    tail->nxtPtr = nullptr;
    size++;
}

template<typename T>
T queue_LL<T>::dequeue() {
    if(empty()){
        throw std::out_of_range("list is empty");
    }

    T item;
    if(head == tail){
        item = head->item;
        head = tail = nullptr;
    }
    else{
        item = head->item;
        head = head->nxtPtr;
    }
    size--;
    return item;
}

template<typename T>
bool queue_LL<T>::empty() {
    if(size)
        return false;
    return true;
}
