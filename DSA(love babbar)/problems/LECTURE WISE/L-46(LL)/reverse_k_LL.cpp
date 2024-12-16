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

int length_of_LL(Node* head)
{
    Node* temp = head;
    int i=1;
    while (temp != NULL)
    {
        i++;
        temp = temp->next_pointing_pointer;
    }
    
}
// void reverse_L_L_in_k (Node* &head, int k) // my approach
// {
//     int length = length_of_LL(head);
//     if ((k>length )|| (length%k != 0))
//     {
//         return;
//     }

//     if (head == NULL || head->next_pointing_pointer == NULL)
//     {
//         return ;
//     }
//     Node* temp_tail = head;
//     bool firstiter = false;

//     for (int i = 0; i < k-1; i++)

//     {
//         temp_tail = temp_tail->next_pointing_pointer;
//     }

//     if (temp_tail==NULL)
//     {
//         firstiter = true;
//     }
    
//     Node* previous = NULL;
//     Node* current = head;
//     Node* forward = NULL;
//     while (previous != temp_tail)
//     {
//         forward = current->next_pointing_pointer;
//         current->next_pointing_pointer = previous;
//         previous = current;
//         current = forward;
//     }

//     if (firstiter)
//     {
//         head->next_pointing_pointer = current;
//         head = previous;  
//         return ;
//     }

//     reverse_L_L_in_k(current,k);
//     head->next_pointing_pointer = current;
//     head = previous;    
//     return ;
// }

Node* reverse_L_L_in_k (Node* &head, int k) // video 
{
    //base case 
    if (head == NULL)
    {
    return NULL;
    }
    // step 1 - reversew first k elements 
    Node* previous = NULL;
    Node* current = head;
    Node* forward = NULL;
    int count =0;
    while (current != NULL && count<k)
    {
        forward = current->next_pointing_pointer;
        current->next_pointing_pointer = previous;
        previous = current;
        current = forward;
        count++;
    }
    //step 2 
    if (forward!= NULL)
    {
        head->next_pointing_pointer = reverse_L_L_in_k(forward,k);
    }

    //return head 
    return previous;
} // TC - o(n) ,, SC - O(n)


int main()
{
    Node* Node1 = new Node(1); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;
    add_new_node_at_end(tail_of_LL,2);
    add_new_node_at_end(tail_of_LL,3);
    add_new_node_at_end(tail_of_LL,4);
    add_new_node_at_end(tail_of_LL,5);
    add_new_node_at_end(tail_of_LL,6);
    add_new_node_at_end(tail_of_LL,7);
    add_new_node_at_end(tail_of_LL,8);

    reverse_L_L_in_k(head_of_LL, 4);
    // head_of_LL = reverse_L_L_in_k(head_of_LL, 4);

    print_L_L(head_of_LL);
}