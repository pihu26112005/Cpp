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

void solve(Node* &head1, Node* &head2)
{

    if(head1->next_pointing_pointer == NULL)
    {
        head1->next_pointing_pointer = head2;
        return ; 
    }
    Node* current1 = head1;
    Node* forward1 = current1->next_pointing_pointer;
    Node* current2 = head2;
    while (forward1!=NULL && current2!=NULL)
    {
        if (current1->data<=current2->data && forward1->data>current2->data)
        {
            head2 = current2->next_pointing_pointer;
            current1->next_pointing_pointer = current2;
            current2->next_pointing_pointer = forward1;
            current2 = head2;
        }
        else
        {
            current1 = forward1;
            forward1 = forward1->next_pointing_pointer;
        }
    }
    if (current2!=NULL)
    {
        current1->next_pointing_pointer = current2;
    }
    return ;
}

// yhe hum dono ll ko merge kr rhe hai 
Node* merge_LL(Node* head1, Node* head2)
{
    if (head1==NULL)
    {
        return head2;
    }
    else if (head2==NULL)
    {
        return head1;
    }
    else
    {
        if (head1->data <= head2->data)
        {
            solve(head1,head2);
            return head1;
        }
        else
        {
            solve(head2,head1);
            return head2;
        }
    }
}

int main()
{
    Node* Node1 = new Node(1); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL1 = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL1 = Node1 ;

    Node* Node2 = new Node(2);
    Node* head_of_LL2 = Node2;
    Node* tail_of_LL2 = Node2;

    add_new_node_at_end(tail_of_LL1,4);
    add_new_node_at_end(tail_of_LL1,7);
    add_new_node_at_end(tail_of_LL1,9);

    add_new_node_at_end(tail_of_LL2,5);
    add_new_node_at_end(tail_of_LL2,6);
    add_new_node_at_end(tail_of_LL2,8);
    
    Node* merge_head = merge_LL(head_of_LL1,head_of_LL2);

    print_L_L(merge_head);
}