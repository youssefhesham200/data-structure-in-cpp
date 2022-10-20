//
// Created by youssef on 12/10/2022.
//

#ifndef VECTOR_IMPLEMENTATION_VECTOR_H
#define VECTOR_IMPLEMENTATION_VECTOR_H

template<typename T> class vector {
private:
    int capacity = 16;
    int size;
    T* arr;
    void resize(int new_capacity);
public:
    vector(int capacity = 16);
    T pop();
    void push(T item);
    int get_size();
    int get_capacity();
    bool is_empty();
    T at(int index);
    void insert(T item, int index);
    void prepend(T item);
    void Delete(int index);
    int find(T item);
    void remove(T item);
};


#endif //VECTOR_IMPLEMENTATION_VECTOR_H
