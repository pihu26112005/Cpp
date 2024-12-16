#include<iostream>
#include<queue>
using namespace std;

int minCost (int arr[] , int n)
{
    priority_queue<int,vector<int>,greater<int> > mini;  
    for (int i = 0; i < n; i++)
    {
        mini.push(arr[i]);
    }

    int sum = 0;
    while (mini.size()>1)
    {
        int a = mini.top();
        mini.pop();
        int b = mini.top();
        mini.pop();

        int c = a+b;
        sum = sum + c ;
        mini.push(c);
    }
    return sum ;
}

// tc = o(nlogn) , sc = o(n)