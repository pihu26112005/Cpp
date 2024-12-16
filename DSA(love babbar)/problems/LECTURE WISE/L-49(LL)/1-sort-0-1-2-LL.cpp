// approach 1 - phle sare 0 dhund ke starting me lga do , fir sare 2 dhund ke end me lga do .
// approach 2 - gin lo ke kitne 0 hai , kitnr 1 , 2 hai , aur fir starting se utne 0,1,2 rakh do nodes ke data me .


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

// jaise hi zero vali node mile toh use hta ke shuru me head ke age lga de rhe hai , same jaise hi 2 vali branch mile toh use tail ke age lga demge 
Node* sort_0_1_2(Node* head, Node* tail)
{
    if (head==NULL)
    {
        return head;
    }
    
    Node* current = head;
    int zero_count = 0;
    while (current->next_pointing_pointer!= NULL)
    {
        if (current->next_pointing_pointer->data == 0)
        {
            Node* temp = current;
            temp = temp->next_pointing_pointer;
            current->next_pointing_pointer=temp->next_pointing_pointer;
            temp->next_pointing_pointer=head;
            head = temp;
            zero_count++;
        }
        current = current->next_pointing_pointer;
    }

    current = head;
    while (current->next_pointing_pointer!= NULL)
    {
        if (current->next_pointing_pointer->data == 2)
        {
            Node* temp = current;
            temp = temp->next_pointing_pointer;
            current->next_pointing_pointer=temp->next_pointing_pointer;
            temp->next_pointing_pointer=NULL;
            tail->next_pointing_pointer = temp;
            tail = temp;
        }
        current = current->next_pointing_pointer;
    }
    return head;
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
    
    head_of_LL=sort_0_1_2(head_of_LL,tail_of_LL);

    print_L_L(head_of_LL);
}