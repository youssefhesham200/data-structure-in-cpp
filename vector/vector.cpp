//
// Created by youssef on 12/10/2022.
//
#include "vector.h"
#include <stdexcept>

template<typename T>
vector<T>::vector(int capacity) {
    arr = new T[capacity];
    size = 0;
}

template<typename T>
int vector<T>::get_size() {
    return size;
}

template<typename T>
int vector<T>::get_capacity() {
    return capacity;
}

template<typename T>
bool vector<T>::is_empty() {
    if(size == 0)
        return true;
    return false;
}

template<typename T>
void vector<T>::resize(int new_capacity) {
    //double capacity
    capacity = new_capacity;
    //allocate new array
    T* new_arr = new T[new_capacity];
    // copy elements of array to this new array
    for(int i=0; i < size; i++){
        *(new_arr + i) = *(arr + i);
    }
    //delete old array
    delete [] arr;
    //make pointer of old array point to new one
    arr = new_arr;
}

template<typename T>
int vector<T>::find(T item) {
    for(int i=0; i < size; i++){
        if(*(arr + i) == item)
            return i;
    }
    return -1;
}

template<typename T>
void vector<T>::insert(T item, int index) {
    if(index > size){
        throw std::out_of_range("this index is out of range");
    }
    //if no place for push another element
    if(size >= capacity){
        resize(2 * capacity);
    }

    if(size == index){
        *(arr + size) = item;
    }
    else{
        for(int i = size; i>=0; i--){
            *(arr + i + 1) = *(arr + i);
            if(i == index){
                *(arr + i) = item;
                break;
            }
        }
    }
    size++;
}

template<typename T>
void vector<T>::push(T item){
    insert(item, size);
}

template <typename T>
void vector<T>::prepend(T item) {
    insert(item, 0);
}

template<typename T>
T vector<T>::at(int index) {
    if(index >= size){
        throw std::out_of_range("this index is out of range");
    }
    return *(arr + index);
}

template<typename T>
void vector<T>::Delete(int index) {
    if(index >= size){
        throw std::out_of_range("this index is out of range");
    }
    for(int i = index; i<size-1; i++){
        *(arr + i) = *(arr + i+1);
    }
    size--;
    if(4 * size <= capacity){
        resize(0.5 * capacity);
    }
}

template<typename T>
void vector<T>::remove(T item) {
    int ind = find(item);
    Delete(ind);
}

template<typename T>
T vector<T>::pop() {
    T item = at(size-1);
    Delete(size-1);
    return item;
}

