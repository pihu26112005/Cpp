// my method
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

void add_new_node_at_beg (Node* &head, int data)
{
   Node* temp = new Node(data); // creating newNode dynamically
    temp->next_pointing_pointer = head ; // temp ko head pe point kraya (kyokii head lastNode pe point krega , uska kaam hi yhi hai)
    head = temp ; // head bhi abb usse point krega jise temp point kr rha tha , yani newNode ki memory location pe 
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

int get_length (Node* head)
{
    Node* temp = head;
    int count =0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next_pointing_pointer;
    }
    return count;
}

Node* get_tail(Node* head)
{
    Node* tail = head;
    while (tail->next_pointing_pointer != NULL)
    {
        tail = tail->next_pointing_pointer;
    }
    return tail;
}

Node* add_LL (Node* head1, Node* head2)
{
    Node* end1 = get_tail(head1);
    Node* end2 = get_tail(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;

    int sum = end1->data + end2->data;
    int digit = sum % 10;
    int carry = sum / 10;

    Node* last_digit = new Node(digit);
    Node* head_of_sum = last_digit;

    do    
    {
        while (temp1->next_pointing_pointer!=end1)
        {
            temp1 = temp1->next_pointing_pointer;
        }
        end1 = temp1;
        temp1 = head1;

        while (temp2->next_pointing_pointer!=end2)
        {
            temp2 = temp2->next_pointing_pointer;
        }
        end2 = temp2;
        temp2 = head2;

        sum = end1->data + end2->data + carry;
        digit = sum % 10;
        carry = sum / 10;

        add_new_node_at_beg(head_of_sum,digit);
    }
    while (end1 != head1 && end2 != head2);

    while (end2 != head2)
    {
        while (temp2->next_pointing_pointer!=end2 && temp2!=end2) 
        {
            temp2 = temp2->next_pointing_pointer;
        }
        end2 = temp2;
        temp2 = head2;

        sum = end2->data + carry;
        digit = sum % 10;
        carry = sum / 10;

        add_new_node_at_beg(head_of_sum,digit);
    }

    while (end1 != head1 )
    {
        while (temp1->next_pointing_pointer!=end1 && temp1!=end1)
        {
            temp1 = temp1->next_pointing_pointer;
        }
        end1 = temp1;
        temp1 = head1;

        sum = end1->data + carry;
        digit = sum % 10;
        carry = sum / 10;

        add_new_node_at_beg(head_of_sum,digit);
    }

    return head_of_sum;
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
    add_new_node_at_end(tail_of_LL1,1);

    add_new_node_at_end(tail_of_LL2,5);
    add_new_node_at_end(tail_of_LL2,6);
    add_new_node_at_end(tail_of_LL2,8);
    
    Node* sum = add_LL(head_of_LL1,head_of_LL2);

    print_L_L(head_of_LL1);
    cout<<endl;

    print_L_L(head_of_LL2);
    cout<<endl;

    print_L_L(sum);
}
