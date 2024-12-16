// QUESTION - har node ke paas ek random pointer bhi hai , jo randomly kisi ek node ko point krega 
// approach 1 - NORMOL - sbse phle linked list copy krlo puri ek for loop aur temp se , 
            // fir ek aur for loop chalake dekhlo ki har element ka random pointer kha point kr rha hai , aur copy krdo
            // TC - o(n*n) ,, SC - O(n)

// approach 2 - ek map me each node aur uska random pointer store krlo 
           // fir ek for loop lgaage LL copy krlo 
           // TC - o(n) ,, SC - O(n)

#include<iostream>
#include<map>
using namespace std ;

class Node 
{
    public:
    int data ;
    Node* next_pointing_pointer ; // kyokii ye Node type ki value ko point krega na 
    Node* arb;
    
    Node(int x) // constructor 
    {
        this->data = x;
        this->next_pointing_pointer = nullptr ;
        this->arb = nullptr ;
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



    void insertAtTail(Node* &head, Node* &tail, int d) 
    {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next_pointing_pointer = newNode;
            tail = newNode;
        }
    }

    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next_pointing_pointer;
        }
        
        //step 2 : create map 
        map<Node* , Node*> old_to_new ;
        Node* old_temp = head;
        Node* new_temp = cloneHead;
        while (old_temp!=NULL)
        {
            old_to_new[old_temp]=new_temp;
            old_temp = old_temp->next_pointing_pointer;
            new_temp = new_temp->next_pointing_pointer;
        }
        old_temp = head;
        new_temp = cloneHead;
        while (old_temp!=NULL)
        {
            new_temp->arb = old_to_new[old_temp->arb];
            old_temp = old_temp->next_pointing_pointer;
            new_temp = new_temp->next_pointing_pointer;
        }
        return cloneHead;
        
    }
