// approach 3 - 0, 1, 2 ke liye alag se teen linked lists bna do , aur utne elements add kro jitne inke numbers ho 
            // fir merge krdo 


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

// basicallly teen puri new link list bna rhe hai ek zero ke liye , ek one ke , ek two ke liye , baad me tino ko jod denge 
Node* sort_0_1_2(Node* head)
{
    Node* zero_head = new Node(-1);
    Node* one_head = new Node(-1);
    Node* two_head = new Node(-1);
    Node* zero_tail = zero_head;
    Node* one_tail = one_head;
    Node* two_tail = two_head;

    Node* current = head;
    while (current!= NULL)
    {
        
        if (current->data==0)
        {
            zero_tail->next_pointing_pointer = current;
            zero_tail = current;
        }
        else if (current->data==1)
        {
            one_tail->next_pointing_pointer = current;
            one_tail = current;
        }
        else if (current->data==2)
        {
            two_tail->next_pointing_pointer = current;
            two_tail = current;
        }
        current = current->next_pointing_pointer;
    }
    zero_head = zero_head->next_pointing_pointer;
    zero_tail->next_pointing_pointer = one_head->next_pointing_pointer;
    one_tail->next_pointing_pointer = two_head->next_pointing_pointer;
    two_tail->next_pointing_pointer = NULL;
    return zero_head;
}

int main()
{
    Node* Node1 = new Node(1); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;
    add_new_node_at_end(tail_of_LL,0);
    add_new_node_at_end(tail_of_LL,1);
    add_new_node_at_end(tail_of_LL,2);
    add_new_node_at_end(tail_of_LL,0);
    add_new_node_at_end(tail_of_LL,2);
    add_new_node_at_end(tail_of_LL,0);
    add_new_node_at_end(tail_of_LL,1);
    
    head_of_LL=sort_0_1_2(head_of_LL);

    print_L_L(head_of_LL);
}