// automatic sorted queue ke liye iska use hota hai 
// SAME PRINCIPLE - first in first out 

#include<iostream>
#include<queue>
using namespace std;
int main()
{
// MAX priority queue - 
    priority_queue<int> maxi;  
    maxi.push(1); // pushing elements 
    maxi.push(2);
    maxi.push(3);
    maxi.push(0);
    maxi.push(-1);
    maxi.pop(); //first in first out element removed 
    cout<<maxi.size()<<endl;
    int n=maxi.size(); // kyokii har pop pe size ghatega toh maxi.size constant nhi hoga for loop me 
    for (int i = 0; i < n ; i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

// MIN priority queue - 
    priority_queue<int,vector<int>,greater<int> > mini;  
    mini.push(1); // pushing elements 
    mini.push(2);
    mini.push(3);
    mini.push(0);
    mini.push(-1);
    mini.pop(); //first in first out element removed 
    cout<<mini.size()<<endl;
    int m =mini.size(); // same reason as above 
    for (int i = 0; i < m; i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    
}

