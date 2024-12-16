#include<iostream>
#include<queue>
using  namespace std ;


class node
{
    public :
    int data ;
    int row ;
    int col ;

    node(int data , int row , int column)
    {
        this->data = data;
        this->row = row ;
        this->col = column ;
    }

};

class compare 
{
    public:
    bool operator()(node* a , node* b)
    {
        return a->data > b->data ;
    }
};

int SmallestRange (vector<vector<int>> &arr , int r , int c)
{
    priority_queue<node* , vector<node*> , compare > heap ;
    int maxi = INT64_MIN ;
    int mini = INT64_MAX ;

    // starting ke k elements heap me daalo 
    for (int i = 0; i < r; i++)
    {
        maxi = max(maxi,arr[i][0]);
        mini = min(mini,arr[i][0]);
        node* temp = new node(arr[i][0],i,0);
        heap.push(temp);
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while(!heap.empty())
    {
        node* temp = heap.top();
        heap.pop();

        mini = temp->data ;
        if((maxi-mini)<(ansEnd-ansStart)) // range updata
        {
            ansStart = mini ;
            ansEnd = maxi ;
        }

        if(temp->col +1 < c)
        {
            maxi = max(maxi,arr[temp->row][temp->col+1]); // maxi updata
            heap.push(new node(arr[temp->row][temp->col+1],temp->row,temp->col+1)); // usi LL ka gla element daal diya 
        }
        else
        {
            break;
        }
    }

    return (ansEnd - ansStart +1) ;
    
}