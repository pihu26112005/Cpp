// # singly linked list 

#include<iostream>
using namespace std ;

class node 
{
    public:
    int data ;
    node* next_pointing_pointer ; // kyokii ye node type ki value ko point krega na 
    
    node(int x) // constructor 
    {
        this->data = x;
        this->next_pointing_pointer = NULL ;
    }

    ~node() // destructor 
    {
        int value = this -> data;
        if(this->next_pointing_pointer != NULL) {
            delete next_pointing_pointer ;
            this->next_pointing_pointer = NULL ;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void add_new_node_at_beg (node* &head, int data)
{
    node* temp = new node(data); // creating new node dynamically
    temp->next_pointing_pointer = head ; // temp ko head pe point kraya (kyokii head last node pe point krega , uska kaam hi yhi hai)
    head = temp ; // head bhi abb usse point krega jise temp point kr rha tha , yani new node ki memory location pe 
}

void add_new_node_at_end (node* &tail, int data)
{
    node* temp = new node(data); // creating new node dynamically
    tail->next_pointing_pointer = temp; // temp ko head pe point kraya (kyokii head last node pe point krega , uska kaam hi yhi hai)
    tail = temp ; // head bhi abb usse point krega jise temp point kr rha tha , yani new node ki memory location pe 
}

void add_new_node_at_position (node* &head, node* &tail, int data, int position)
{
    if (position == 1) // begening me insert
    {
        add_new_node_at_beg(head, data);
        return ;
    }
    node* temporary_node_pointer = head ; //  ye class pointer hai , jo phle element pe point krega 
    int i = 1;
    while (i<position-1) // kyokii last element NULL ko point krega 
    {
        temporary_node_pointer = temporary_node_pointer->next_pointing_pointer ; // usi element ke next jisko point krega ab temp bhi use point krega 
        i++;
    }
    if (temporary_node_pointer->next_pointing_pointer == NULL)
    {
        add_new_node_at_end(tail, data);
    }
    
    node* new_node = new node(data);
    new_node->next_pointing_pointer = temporary_node_pointer->next_pointing_pointer ;
    temporary_node_pointer->next_pointing_pointer = new_node ;
}

void delet_node_at_position (node* &head, node* &tail, int position)
{
    if (position==1)
    {
        node* temp = head ;
        head = head->next_pointing_pointer ;
        temp->next_pointing_pointer = NULL ;
        delete(temp) ;
        return ;
    }
    node* temporary_node_pointer = NULL ; //  ye class pointer hai , jo phle element pe point krega 
    node* temporary_node_pointer2 = head ; //  ye class pointer hai , jo phle element pe point krega 
    int i = 1;
    while (i<position) // kyokii last element NULL ko point krega 
    {
        temporary_node_pointer = temporary_node_pointer2 ;
        temporary_node_pointer2 = temporary_node_pointer2->next_pointing_pointer ; // usi element ke next jisko point krega ab temp bhi use point krega 
        i++;
    }
    if (temporary_node_pointer2->next_pointing_pointer == NULL)
    {
        temporary_node_pointer->next_pointing_pointer = NULL ;
        tail = temporary_node_pointer ;
        delete(temporary_node_pointer2) ;
        return ;
    }
    temporary_node_pointer->next_pointing_pointer = temporary_node_pointer2->next_pointing_pointer ;
    temporary_node_pointer2->next_pointing_pointer = NULL ;
    delete(temporary_node_pointer2) ;
}
void print_L_L (node* &head)
{
    node* temporary_node_pointer = head ; //  ye class pointer hai , jo phle element pe point krega 
    while (temporary_node_pointer != NULL) // kyokii last element NULL ko point krega 
    {
        cout<<temporary_node_pointer->data<< " " ; // phle element ka data print 
        temporary_node_pointer = temporary_node_pointer->next_pointing_pointer ; // usi element ke next jisko point krega ab temp bhi use point krega 
    }
}

int main()
{
    node* node1 = new node(5); // dynimically nod1 naam ka object bnaya hai
    node* head_of_LL = node1 ; // node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko node1 point kr rha hai  
    add_new_node_at_beg(head_of_LL,3);
    node* tail_of_LL = node1; // tail (node type pointer ) isse bhi use hi access kroge jisko node1 se access kroge
    add_new_node_at_end(tail_of_LL,6);
    add_new_node_at_position(head_of_LL,tail_of_LL,4,2);
    delet_node_at_position(head_of_LL, tail_of_LL, 2);
    print_L_L(head_of_LL);
}