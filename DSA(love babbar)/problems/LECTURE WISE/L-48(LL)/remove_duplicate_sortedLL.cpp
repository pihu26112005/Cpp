// 2 3 3 4 5 6 6 6 7 8 8   ko    2 3 4 5 6 7 8 bnana hai 
#include<iostream>
#include<map>
using namespace std ;

class Node 
{
    public:
    int data ;
    Node* next_pointing_pointer ; // kyokii ye Node type ki value ko point krega na 
    
    Node(int x) // constructor 
    {
        this->data = x;
        this->next_pointing_pointer = nullptr ;
    }
    // Node(int x): data(x), next_pointing_pointer(nullptr);

    ~Node() // destructor 
    {
        int value = this -> data;
        if(this->next_pointing_pointer != NULL) {
            delete next_pointing_pointer ;
            this->next_pointing_pointer = NULL ;
        }
        cout << " memory is free for Node with data " << value << endl;
    }
};

Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next_pointing_pointer != NULL) && curr -> data == curr -> next_pointing_pointer -> data) {
            Node* next_next = curr ->next_pointing_pointer -> next_pointing_pointer;
            Node* nodeToDelete = curr -> next_pointing_pointer;
            delete(nodeToDelete);
            curr -> next_pointing_pointer = next_next;
        }
        else //not equal
        {
            curr = curr -> next_pointing_pointer;
        }   
    }
    
    return head; 
}