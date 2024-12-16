#include<iostream>
using namespace std ;
#include<queue>

class node
{
    public :
    int data ;
    int i ;
    int j ;

    node(int data , int i , int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class compare  // kiske basis pr queue compare krega
{
    public :
    bool operator () (node* a, node* b)
    {
        return a->data > b->data ;
    }
};

vector<int> mergeKarray (vector<vector<int>> &arr , int k)
{
    priority_queue<node* , vector<node*> , compare> minHeap ;
    vector<int> ans ;

    // sare array ke first element heap me daale 
    for (int i = 0; i < k; i++)
    {
        node* temp = new node(arr[i][0],i,0);
        minHeap.push(temp);
    }

    while (minHeap.size()>0)
    {
        // sbse min element ans me daaalo 
        node* temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);

        // fir vo jis array ka tha uska nest element heap me daal do 
        int arraySize =  arr[temp->i].size();
        if(temp->j+1 < arraySize)
        {
        node* next = new node(arr[temp->i][temp->j+1],temp->i,temp->j+1);
        minHeap.push(next);
        }
    }
    
    return ans ;
}