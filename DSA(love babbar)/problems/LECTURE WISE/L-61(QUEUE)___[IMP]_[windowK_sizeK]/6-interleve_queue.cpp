// interleave first half of queue with second half 
// using deque 

#include<iostream>
#include<queue>
#include<deque>
using namespace std ;

void add (deque<int>& q1 , deque<int>& q2)
{
    if (q1.size()==0 && q2.size()==0)
    {
        return ;
    }
    
    int temp1 = q1.back();
    int temp2 = q2.back();
    q1.pop_back();
    q2.pop_back();
    add ( q1 , q2 ) ;
    q1.push_back(temp1);
    q1.push_back(temp2);
    return ;
}

void interLeaveQueue (queue <int > & q) 
{
    int n = q.size()/2 ;
    deque<int> q1 ;
    deque<int> q2 ;
    for(int i=0 ; i<n; i++)
    {
        int temp = q.front();
        q1.push_back(temp);
        q.pop();
    }
    for (int i = n; i < 2*n; i++)
    {
        int temp = q.front();
        q2.push_back(temp);
        q.pop();      
    }
    
    add ( q1, q2);

    for (int i = 0; i < 2*n; i++)
    {
        int temp = q1.front();
        q.push(temp);
        q1.pop_front();
    }
    
}

int main()
{
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interLeaveQueue(q);

    for (int i = 0; i < 6; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}