// my approach - // ek beg pointer bnaya , aur ek end 
                // fir unka data compare kiya aur beg ko age kiya aur end ko piche 



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

// 2 pointer approach age + piche se compare 
bool check_palindrome(Node* head)
{
    Node* beg = head;
    Node* temp = beg;
    while (temp->next_pointing_pointer!=NULL)
    {
        temp = temp->next_pointing_pointer;
    }
    Node* end = temp;
    temp = head;
    while ((beg->next_pointing_pointer!=end) && (beg != end))
    {
        while (temp->next_pointing_pointer != end)
        {
            temp = temp->next_pointing_pointer;
        }
        if (beg->data != end->data)
        {
            return false;
        }
        end = temp;
        beg = beg->next_pointing_pointer;
        temp = beg;
    }
    return true;
    // TC - o(n)
    // SC - O(1)
}

int main()
{
    Node* Node1 = new Node(1); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;

    add_new_node_at_end(tail_of_LL,4);
    add_new_node_at_end(tail_of_LL,7);
    add_new_node_at_end(tail_of_LL,7);
    add_new_node_at_end(tail_of_LL,4);
    add_new_node_at_end(tail_of_LL,1);


    if (check_palindrome(head_of_LL)==true)
    {
        cout<<endl<<" yes"<<endl;
    }
    
}