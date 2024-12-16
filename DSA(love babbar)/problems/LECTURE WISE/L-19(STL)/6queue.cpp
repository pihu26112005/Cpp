// PRINCIPLE - first in first out 

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> que; 
    que.push(1); // pushing elements 
    que.push(2);
    que.push(3);
    que.push(0);
    que.push(-1);
    que.pop(); //first in first out element removed 
    cout<<que.size()<<endl;
    cout<<que.front()<<endl; // .top ka kaam .front krta hai 
    // que.empty();


//  que.pop_back(); NHI HOTA 
//  que.pop_front(); NHI HOTA 
// cout<<l.capacity()<<endl;  NHI HOTA 
// cout<<que.front()<<endl;
// cout<<que.back()<<endl;

}