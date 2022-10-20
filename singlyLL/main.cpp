#include <iostream>
#include "SLinkedList.cpp"
using namespace std;


int main() {
    SLinkedList<int> sll;
    sll.push_back(2);
    sll.push_back(3);
    sll.push_back(4);
    sll.reverse();
    cout<<sll.front();
    cout<<sll.value_at(2);
}
