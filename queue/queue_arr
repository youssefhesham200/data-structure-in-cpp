//
// Created by Youssef Hesham on 27/10/2022.
//

#include "queue_arr.h"

template<typename T>
queue_arr<T>::queue_arr(int capacity) {
    this->capacity = capacity;
    arr = new T [capacity];
    start = 0;
    end = 0;
    count = 0;
}

template<typename T>
void queue_arr<T>::enqueue(T item) {
    *(arr + end) = item;
    end++;
    end %= capacity;
    count++;
}

template<typename T>
T queue_arr<T>::dequeue() {
    T item = *(arr + start);
    start++;
    start %= capacity;
    count--;
    return item;
}

template<typename T>
bool queue_arr<T>::full() {
    if(count == capacity)
        return true;
    return false;
}

template<typename T>
bool queue_arr<T>::empty() {
    if(count)
        return false;
    return true;
}
