//
// Created by youssef on 18/10/2022.
//

#ifndef BST_BST_H
#define BST_BST_H

template<typename T>
class Node{
public:
    T data;
    Node* right;
    Node* left;
};

template<typename T>
class bst {
private:
    Node<T>* cur;
    Node<T>* root;
    int size;
    Node<T>* insert_p(Node<T> *r, T data);
    void inorder_p_sorted(Node<T>* n);
    int get_height_p(Node<T>* n);
    void reverse_sort(Node<T>* n);
    Node<T>* find_node(T item);
    Node<T>* git_min_p(Node<T>* n);
    Node<T>* delete_p(Node<T>* n, T item);
public:
    bst();
    void insert(T data );
    int  get_node_count();
    void print_sorted_inorder();
    void print_reverse_sorted();
    T get_min();
    T get_max();
    int get_height();
    bool is_in_tree(T item);
    T find_successor(T item);
    string delete_(T item);


};


#endif //BST_BST_H
