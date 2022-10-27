//
// Created by Youssef Hesham on 27/10/2022.
//

#ifndef QUEUE_QUEUE_ARR_H
#define QUEUE_QUEUE_ARR_H

template<typename T>
class queue_arr {
private:
    T *arr;
    int capacity;
    int start;
    int end;
    int count;
public:
    queue_arr(int capacity);
    void enqueue(T item);
    T dequeue();
    bool full();
    bool empty();
};




#endif //QUEUE_QUEUE_ARR_H
