//Deque (Double-ended Queue):
                    //  A DYNAMIC ARRAY that allows insertion and deletion at BOTH ENDS efficiently

#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> deq; // DYANIMIC ARRAY  ka baap : 
    deq.push_back(1); // pushing elements 
    deq.push_back(2);
    deq.push_back(3);
    deq.push_front(0);
    deq.push_front(-1);

    for(int i : deq) //print deq
    {
        cout<<i<<" ";
    }
    cout<<endl;

    deq.pop_back(); // removes last element 
    deq.pop_front();//removes front element

    for(int i : deq)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<deq.size()<<endl;
    // cout<<deq.capacity()<<endl;  NHI HOTA 
    cout<<deq.front()<<endl;
    cout<<deq.back()<<endl;

    deque<int> a(5,1);// for assigning same element in a vector 
    for(int i : a)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    a.clear(); // for clearing
    deq.erase(deq.begin(),deq.begin()+1);//for clearign specific range of numbers 
}