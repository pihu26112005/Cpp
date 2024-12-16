#include<iostream>
using namespace std ;
#include<queue>

class node 
{
    public:
    int data ;
    node* next_pointing_pointer ; // kyokii ye node type ki value ko point krega na 
    
    node(int x) // constructor 
    {
        this->data = x;
        this->next_pointing_pointer = NULL ;
    }

    ~node() // destructor 
    {
        int value = this -> data;
        if(this->next_pointing_pointer != NULL) {
            delete next_pointing_pointer ;
            this->next_pointing_pointer = NULL ;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

class compare 
{
    public :
    bool operator()(node* a , node* b)
    {
        return a->data > b->data ;
    }
};

node* mergeLL(vector<node*> &arr)
{
    priority_queue<node* , vector<node*> , compare> minHeap ;
    node* ansHead = NULL ;
    node* ansTail = NULL ;

    // sbhi LL ke top node heap me daalo 
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]!=NULL) // kyooki agar null hai toh dalke bhi kya fayeda
           minHeap.push(arr[i]);
    }

    while (minHeap.size()>0)
    {
        if(ansHead==NULL)
        {
            node* temp = minHeap.top();
            minHeap.pop();
            ansHead = temp ;
            ansTail = temp ;

            if(temp->next_pointing_pointer != NULL)
            {
                minHeap.push(temp->next_pointing_pointer);
            }
        }
        else
        {
            node* temp = minHeap.top();
            minHeap.pop();
            ansTail->next_pointing_pointer = temp ;
            ansTail = ansTail->next_pointing_pointer;
            if(temp->next_pointing_pointer != NULL)
            {
                minHeap.push(temp->next_pointing_pointer);
            }
        }
    }
    return ansHead ;
    
}