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

bool check_loop (Node* head) // 1 - mapping approach 
{
    if (head==NULL)
    {
        return false;
    }
    Node* temp = head;
    map<Node* , bool> check_visited;
    while (temp != NULL)
    {
        if (check_visited[temp]==true)
        {
            return true;
        }
        check_visited[temp]==true;
        temp=temp->next_pointing_pointer;
    }
    return false; 
// TC - o(n) ,, SC - O(n)
}

bool floyd_cycle_detect_algo(Node* head) // 2- 2 POINTER APPROACH 
{
    if (head==NULL)
    {
        return false;
    }
    Node* fast = head;
    Node* slow = head;
    while (slow != NULL && fast != NULL)
    {
        slow=slow->next_pointing_pointer;
        fast=fast->next_pointing_pointer;
        if (fast!=NULL)
        {
            fast=fast->next_pointing_pointer;
        }
        if (slow == fast)
        {
            return true;
        }
    }
    return false;       
// TC - o(n) ,, SC - O(1)
// WHY ALWAYS MEET - jab slow loop ke begigning vali node pr hota hai , aur fast loop ke andar hota hai 
                // toh har iteration ke baad unke bich ki distance kam hoti rhti hai --> finally zero
}

int main()
{
    Node* Node1 = new Node(1); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;
}