//
// Created by youssef on 18/10/2022.
//
#include <iostream>
using namespace std;
#include "bst.h"

// private methods
// (left root right) sorted bst o(n)
template<typename T>
void bst<T>::inorder_p_sorted(Node<T> *n) {
    if(root == nullptr){
        cout<<"empty tree\n";
        return;
    }

    if(n != nullptr){
        inorder_p_sorted(n->left);
        cout<<n->data<<"\n";
        inorder_p_sorted(n->right);
    }
}

// (right root left) reverse sorted bst  o(n)
template<typename T>
void bst<T>::reverse_sort(Node<T> *n) {
    if(root == nullptr){
        cout<<"empty tree\n";
        return;
    }

    if(n != nullptr){
        reverse_sort(n->right);
        cout<<n->data<<"\n";
        reverse_sort(n->left);
    }
}

// O(h) == O(log n) in best case
template<typename T>
Node<T>* bst<T>::insert_p(Node<T>* r, T data) {
    if(r == nullptr){
        auto *node = new Node<T>;
        node->data = data;
        r = node;
        size++;
    }
    else if(data < r->data){
        r->left = insert_p(r->left, data);
    }
    else{
        r->right = insert_p(r->right, data);
    }

    return r;
}

// height of tree h = log n
template<typename T>
int bst<T>::get_height_p(Node<T> *n) {
    if(n == nullptr){
        return 0;
    }

    return 1 + max(get_height_p(n->left), get_height_p(n->right));
}


template<typename T>
Node<T> *bst<T>::find_node(T item) {
    if(root == nullptr)
        return nullptr;

    Node<T>* cur1 = root;
    while (cur1 != nullptr){
        if(cur1->data == item)
            return cur1;
        else if(cur1->data >= item)
            cur1 = cur1->left;
        else
            cur1 = cur1->right;
    }

    return nullptr;
}

// deep left of left subtree
template<typename T>
Node<T> *bst<T>::git_min_p(Node<T> *n) {
    auto * ptr = n;
    while (ptr->left != nullptr){
        ptr = ptr->left;
    }
    return ptr;
}


template<typename T>
Node<T>* bst<T>::delete_p(Node<T> *n, T item) {
    if(n == nullptr) return nullptr;
    else if(item < n->data) n->left = delete_p(n->left, item);
    else if (item > n->data) n->right = delete_p(n->right, item);

    else{
        //case1: no children
        if(n->right == nullptr && n->left == nullptr){
            delete n;
            n = nullptr;
        }

        //case 2: if node have one child
        else if(n->right == nullptr){
            Node<T> *temp = n;
            n = n->left;
            delete temp;
        }

        else if(n->left == nullptr){
            Node<T> *temp = n;
            n = n->right;
            delete temp;
        }

        // have two children
        else{
            // get successor
            Node<T>* min_right = git_min_p(n->right);
            // replace data
            n->data = min_right->data;
            // recurse to remove duplicated item
            n->right = delete_p(n->right,min_right->data);
        }
    }
    // must put n after all conditions for correctly working stack
    return n;
}


// public methods
template<typename T>
bst<T>::bst(){
root = cur = nullptr;
size = 0;
}

template<typename T>
void bst<T>::insert(T data) {
    cur = insert_p(cur, data);
    if(size == 1){
        root = cur;
    }
}

template<typename T>
int bst<T>::get_node_count() {
    return size;
}

template<typename T>
T bst<T>::get_min() {
    return git_min_p(root)->data;
}

// deep right of right subtree
template<typename T>
T bst<T>::get_max() {
    auto * ptr = root;
    while (ptr->right != nullptr){
        ptr = ptr->right;
    }
    return ptr->data;
}

template<typename T>
int bst<T>::get_height() {
    get_height_p(root);
}

template<typename T>
void bst<T>::print_sorted_inorder() {
    inorder_p_sorted(root);
}

template<typename T>
void bst<T>::print_reverse_sorted() {
    reverse_sort(root);
}

//binary search algo in (log n)
template<typename T>
bool bst<T>::is_in_tree(T item) {
    if(find_node(item) != nullptr)
        return true;
    return false;
}


// successor is the next highest node for a given node
// CASE 1: if a node have a right subtree -> ( inorder successor is the left most node in right subtree of a node (git min) )
// CASE 2: if a node don't have a right subtree -> (inorder successor is the deepest node in which cur node is in left)

template<typename T>
T bst<T>::find_successor(T item) {
    Node<T>* current = find_node(item);
    if(current == nullptr)
        return -1;

    // case 1 : if a node have a right subtree
    if(current->right != nullptr){
        return git_min_p(current->right)->data;
    }

    // case 2 : if a node don't have a right subtree
    else {
        Node<T> *successor = nullptr;
        Node<T> *ancestor = root;

        while (ancestor != current) {
            if (ancestor->data > current->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor->data;
    }
}

template<typename T>
string bst<T>::delete_(T item) {
    delete_p(root, item);
}





