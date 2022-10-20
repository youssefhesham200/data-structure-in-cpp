#include "iostream"
#include "vector.cpp"

using namespace std;

int main(){
    vector<int> arr;
    arr.push(2);
    arr.push(3);
    arr.prepend(1);
    cout<<arr.pop()<<"\n";
    cout<<arr.pop()<<"\n";
    cout<<arr.at(0)<<"\n";
    cout<<arr.get_capacity()<<"\n";
    cout<<arr.find(1)<<'\n';
    arr.remove(1);
    cout<<arr.find(1)<<'\n';
    cout<<arr.is_empty()<<'\n';
    return 0;
}
