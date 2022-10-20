#include <iostream>
#include "bst.cpp"
using namespace std;

int main() {
    bst<int> b;
    b.insert(4);
    b.insert(2);
    b.insert(7);
    b.insert(8);
    b.insert(6);
    b.insert(3);


   b.delete_(2);
   b.print_sorted_inorder();
}
