//A dynamic array that can change in size

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec; // DYANIMIC ARRAY : 
    vec.push_back(1); // pushing elements at back
    vec.push_back(2);
    vec.push_back(3);

    for(int i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    vec.pop_back(); // removes last element 

    for(int i : vec)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;

    vector<int> a(5,1);// for assigning same element in a vector 
    for(int i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    a.clear(); // for clearing
}
