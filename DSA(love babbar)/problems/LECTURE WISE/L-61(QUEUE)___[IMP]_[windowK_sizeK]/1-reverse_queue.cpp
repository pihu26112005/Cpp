#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> rev(queue<int> q) // approach 1
{
    stack<int> s;
    
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

void reverse(queue<int>& q) // approach 2
{
    if(q.size()==0)
    {
        return ;
    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
    return ;
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    reverse(q);
    for (int i = 0; i < 4; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}