// video - // phle middle nikal lunga 
           // fir middle ke age ko reverse kr do
           // fir comapre kr lo dono half ko 


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

Node* getMid(Node* head ) {
    Node* slow = head;
    Node* fast = head -> next_pointing_pointer;
    
    while(fast != NULL && fast-> next_pointing_pointer != NULL) {
        fast = fast -> next_pointing_pointer -> next_pointing_pointer;
        slow = slow -> next_pointing_pointer;
    }
    
    return slow;
}
Node* reverse(Node* head) {
    
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    
    while(curr != NULL) {
        forward = curr -> next_pointing_pointer;
        curr -> next_pointing_pointer = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
//adhi ahdi LL ko compare kr rhe hai
bool isPalindrome(Node *head)
{
    if(head -> next_pointing_pointer == NULL) {
        return true;
    }
    
    //step 1 -> find Middle
    Node* middle = getMid(head);
    //cout << "Middle " << middle->data << endl;
    
    //step2 -> reverse List after Middle
    Node* temp = middle -> next_pointing_pointer;
    middle -> next_pointing_pointer = reverse(temp);
    
    //step3 - Compare both halves
    Node* head1 = head;
    Node* head2 = middle -> next_pointing_pointer;
    
    while(head2 != NULL) {
        if(head2->data != head1->data) {
            return 0;
        }
        head1 = head1 -> next_pointing_pointer;
        head2 = head2 -> next_pointing_pointer;
    }

    //step4 - repeat step 2
    temp = middle -> next_pointing_pointer;
    middle -> next_pointing_pointer = reverse(temp);
    
    return true;
}