// QUESTIONS - 1) LOOP DETECT 
            // 2) LOOP IF PRESENT - BEGINING NODE
            // 3) LOOP DELETION 

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

Node* floyd_cycle_beg_loop(Node* head) // 2- 2 POINTER APPROACH 
{
    if (head==NULL)
    {
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    bool firstiter = true;
    while (slow != NULL && fast != NULL && firstiter==true)
    {
        slow=slow->next_pointing_pointer;
        fast=fast->next_pointing_pointer;
        if (fast!=NULL)
        {
            fast=fast->next_pointing_pointer;
        }
        if (slow == fast)
        {
            firstiter = false;
        }
    }
    slow = head;
    while (slow!=fast)
    {
        slow=slow->next_pointing_pointer;
        fast=fast->next_pointing_pointer;
    }
    
    return slow;       
// TC - o(n) ,, SC - O(1)
}

void delet_loop_LL(Node* head)
{    
    Node* loop_beg = floyd_cycle_beg_loop(head);
    Node* temp = loop_beg;
    while (temp->next_pointing_pointer != loop_beg)
    {
        temp = temp->next_pointing_pointer;
    }
    temp->next_pointing_pointer = NULL;
    return ;
}

int main()
{
    Node* Node1 = new Node(1); // dynimically node1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;
}