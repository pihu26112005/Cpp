#include <iostream>
#include<array>
using namespace std;
int main()
{
    // contiguous , fixed , similar data types
    array<int,5> arr = {1,2,3,4,5};
    cout<<arr[2]<<endl;
    cout<<arr.at(2)<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
    int s = arr.size();
    cout<<s<<endl;
    cout<<arr.empty()<<endl; //1 if empty and 0 if non - empty 
}