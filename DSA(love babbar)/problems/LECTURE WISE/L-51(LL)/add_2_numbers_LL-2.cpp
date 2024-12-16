// video - phlew dono ko reverse kiya , fir add kiya , final ans ko fir se reverse kiya 
// TC - o(m+n)
// SC = O(max(m,n)) --> new linked lists me max element bade vale number ke barabar honge 

#include<iostream>
using namespace std;
class Node 
{
    public:
    int data ;
    Node* next_pointing_pointer ; // kyokii ye Node type ki value ko point krega na 
    
    Node(int x) // conor 
    {
        this->data = x;
        this->next_pointing_pointer = nullptr ;
    }
    // Node(int x): data(x), next_pointing_pointer(nullptr);

    ~Node() // deor 
    {
        int value = this -> data;
        if(this->next_pointing_pointer != NULL) {
            delete next_pointing_pointer ;
            this->next_pointing_pointer = NULL ;
        }
        cout << " memory is free for Node with data " << value << endl;
    }
};

    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next_pointing_pointer;
            curr -> next_pointing_pointer = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail( Node* &head,  Node* &tail, int val) {
        
        Node* temp = new Node(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next_pointing_pointer = temp;
            tail = temp;
        }
    }
    
    Node* add( Node* first,  Node* second) 
    {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next_pointing_pointer;
            
            if(second != NULL)
                second = second -> next_pointing_pointer;
        }
        return ansHead;
    }

    //Function to add two numbers represented by linked list.
    Node* add_LL( Node* first,  Node* second)
    {
        //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        Node* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
    }

