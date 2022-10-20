//
// Created by youssef on 12/10/2022.
//
#include <stdexcept>
#include "SLinkedList.h"

template<typename T>
SLinkedList<T>::SLinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
int SLinkedList<T>::get_size() {
    return size;
}

template<typename T>
bool SLinkedList<T>::empty() {
    if(size)
        return false;
    return true;
}

template<typename T>
void SLinkedList<T>::push_back(T item) {
    auto* node = new Node<T>;   //must make pointer to current node not object like (Node n);
    node->item = item;
    if(head == nullptr && tail == nullptr){
            head = tail = node;
    }
    else{
        tail->nxtPtr = node; // previous node point to current node
        tail = node; // assign tail to last node (current)
    }
    node->nxtPtr = nullptr;
    size++;
}

template<typename T>
void SLinkedList<T>::push_front(T item) {
    auto* node = new Node<T>;
    node->item = item;
    if(head == nullptr && tail == nullptr){
        head = tail = node;
        node->nxtPtr = nullptr;
    }
    else{
        node->nxtPtr = head;
        head = node;
    }
    size++;
}

template<typename T>
void SLinkedList<T>::insert(T item, int index) {
    auto* node = new Node<T>;
    node->item = item;

    if(index == 0){
        head = tail = node;
    }
    else{
        auto* current = head;
        for(int i=0; i<index-1; i++){
            current = current->nxtPtr;
        }
        node->nxtPtr = current->nxtPtr;
        current->nxtPtr = node;
    }
}

template<typename T>
T SLinkedList<T>::value_at(int index) {
    if(empty()){
        throw std::out_of_range("list is empty");
    }

    auto* current = head;
    for(int i=0; i<index; i++){
        current = current->nxtPtr;
    }
    return current->item;
}

template<typename T>
T SLinkedList<T>::back() {
    if(empty()){
        throw std::out_of_range("list is empty");
    }
    return tail->item;
}

template<typename T>
T SLinkedList<T>::front() {
    if(empty()){
        throw std::out_of_range("list is empty");
    }
    return head->item;
}



template<typename T>
T SLinkedList<T>::pop_back(){
    if(empty()){
        throw std::out_of_range("list is empty");
    }

    T item;
    if(head == tail){
        item = head->item;
        head = tail = nullptr;
    }
    else{
        auto* current = head;
        while (current->nxtPtr->nxtPtr != nullptr){
            current = current->nxtPtr;
        }
        item = current->nxtPtr->item;
        current->nxtPtr = nullptr;
        tail = current;
    }
    size--;
    return item;
}

template<typename T>
T SLinkedList<T>::pop_front() {
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
void SLinkedList<T>::erase(int index) {
    if(empty()){
        throw std::out_of_range("list is empty");
    }

    if(index >= size){
        throw std::out_of_range("index is out of range");
    }

    if(index == 0){
        pop_front();
    }
    else if(index == size-1){
        pop_back();
    }
    else{
        auto* current = head;
        for(int i=0; i<index-1; i++){
            current = current->nxtPtr;
        }
        current->nxtPtr = current->nxtPtr->nxtPtr;
        size--;
    }
}

template<typename T>
void SLinkedList<T>::remove_value(T item) {
    if(empty()){
        throw std::out_of_range("list is empty");
    }

    int ind = -1;
    auto* current = head;
    for(int i=0; i<size; i++){
        if(current->item == item){
            ind = i;
            break;
        }
        current = current->nxtPtr;
    }

    if(ind == -1){
        throw std::out_of_range("not found");
    }
    else{
        erase(ind);
    }
}

template<typename T>
void SLinkedList<T>::reverse() {
    tail = head;
    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    if(head == nullptr)
        throw std::out_of_range("list is empty");
    Node<T>* next = cur->nxtPtr;
    while (cur != nullptr){
        cur->nxtPtr = prev;
        prev = cur;
        cur = next;
        if(next != nullptr)
            next = next->nxtPtr;
    }
    head = prev;
}



