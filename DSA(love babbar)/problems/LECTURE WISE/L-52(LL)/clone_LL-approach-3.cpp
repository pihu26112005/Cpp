// QUESTION - har node ke paas ek random pointer bhi hai , jo randomly kisi ek node ko point krega 
// approach 3 - 
// TC - o(n) ,, SC - O(1)

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
    
    void print(Node* head) 
    {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next_pointing_pointer;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next_pointing_pointer;
            cout << endl;
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
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next_pointing_pointer;
            originalNode -> next_pointing_pointer = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next_pointing_pointer;
            cloneNode -> next_pointing_pointer = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next_pointing_pointer;
            }
            else
            {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next_pointing_pointer;
            originalNode = originalNode -> next_pointing_pointer;
        }
        
        //step 4: revert step 2 changes
        originalNode = head;
        cloneNode = cloneHead;
        
         while (originalNode!=NULL && cloneNode!=NULL)
            {
                originalNode->next_pointing_pointer = cloneNode->next_pointing_pointer;
                originalNode = originalNode->next_pointing_pointer;
                if (originalNode!=NULL)
                {
                cloneNode->next_pointing_pointer = originalNode->next_pointing_pointer;
                }
                cloneNode = cloneNode->next_pointing_pointer;
            }

        // step 5 answer return
        return cloneHead;
    }
