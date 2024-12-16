// odd me middle , even me 2nd middle return krni hai node


// bruuteforce --> simple length nikalo , phir mide nikalo, then aram se temp node of while loop se middle node tak le jao
// FAST AND SLOW POINTER APPROACH

#include<iostream>
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

void add_new_node_at_end (Node* &tail, int data)
{
    Node* temp = new Node(data); // creating new node dynamically
    tail->next_pointing_pointer = temp; // temp ko head pe point kraya (kyokii head last node pe point krega , uska kaam hi yhi hai)
    tail = temp ; // head bhi abb usse point krega jise temp point kr rha tha , yani new node ki memory location pe 
}

void print_L_L (Node* &head)
{
    Node* temporary_node_pointer = head ; //  ye class pointer hai , jo phle element pe point krega 
    while (temporary_node_pointer != NULL) // kyokii last element NULL ko point krega 
    {
        cout<<temporary_node_pointer->data<< " " ; // phle element ka data print 
        temporary_node_pointer = temporary_node_pointer->next_pointing_pointer ; // usi element ke next jisko point krega ab temp bhi use point krega 
    }
}

Node* middle_node_of_LL (Node* head)
{
    if (head == NULL || head->next_pointing_pointer == NULL) // 0 element, 1 element case 
    {
        return head;
    }
    if (head->next_pointing_pointer->next_pointing_pointer == NULL) // 2 elements case 
    {
        return head->next_pointing_pointer;
    }
    
    Node* slow = head;
    Node* fast = head->next_pointing_pointer;
    while (fast != NULL)
    {
        slow = slow->next_pointing_pointer;
        fast = fast->next_pointing_pointer;
        if (fast!=NULL) // agar check nhi krenge toh even ke case me fast null ke bhi age chala jayega and error dega 
        {
            fast = fast->next_pointing_pointer;
        }
        
    }
    return slow;
    
    
}

int main()
{
    Node* Node1 = new Node(5); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;
    add_new_node_at_end(tail_of_LL,6);
    add_new_node_at_end(tail_of_LL,7);
    add_new_node_at_end(tail_of_LL,8);
    // add_new_node_at_end(tail_of_LL,9);

    Node* middle = middle_node_of_LL(head_of_LL);

    print_L_L(middle);
}