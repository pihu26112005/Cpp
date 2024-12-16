//A doubly linked list where each element contains the data and pointers to the next and previous elements.
// Allows efficient insertion and deletion at any position.

#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l; 
    l.push_back(1); // pushing elements 
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.push_front(-1);

    for(int i : l) //print l
    {
        cout<<i<<" ";
    }
    cout<<endl;

    l.pop_back(); // removes last element 
    l.pop_front();//removes front element

    for(int i : l)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<l.size()<<endl;
    // cout<<l.capacity()<<endl;  NHI HOTA 
    cout<<l.front()<<endl;
    cout<<l.back()<<endl;

    list<int> a(5,1);// for assigning same element 
    for(int i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    a.clear(); // for clearing
    l.erase(l.begin());//for clearign specific range of numbers 
    for(int i : l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}