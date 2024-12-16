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

void reverse_L_L (Node* &head)
{
//   3 pointer approach (using loop)
        // TC - o(n)
        // SC - 0(1)

// time limit exceed (my approach) :
    // Node* previous = NULL;
    // Node* current = head;
    // Node* next = head->next_pointing_pointer;
    // while (current->next_pointing_pointer != NULL)
    // {
    //     current->next_pointing_pointer = previous;
    //     previous = current;
    //     current = next;
    //     next = next->next_pointing_pointer;
    // }
    // current->next_pointing_pointer = previous;
    // head = current;


// video approach
    Node* previous = NULL;
    Node* current = head;
    Node* forward = NULL;
    while (current!= NULL)
    {
        forward = current->next_pointing_pointer;
        current->next_pointing_pointer = previous;
        previous = current;
        current = forward;
    }
    head = previous;
}

void reverse_using_recursion_1(Node* &head, Node* prev, Node* current)
{
    if (current==NULL)
    {
        head = prev;
        return;
    }
    Node* next = current->next_pointing_pointer;
    current->next_pointing_pointer = prev;
    reverse_using_recursion_1(head, current,  next);
    // or
    // 2 pointer approach 
    // reverse_using_recursion(head, current,  current->next_pointing_pointer);
    // current->next_pointing_pointer = prev;
}

// void reverse_using_recursion_2(Node* &head) // discuss
// {
// // 1 pointer approach
//     if (head == NULL || head->next_pointing_pointer == NULL)
//     {
//         return ;
//     }
//     reverse_using_recursion_2(head->next_pointing_pointer);
//     head->next_pointing_pointer->next_pointing_pointer = head;
//     head->next_pointing_pointer = NULL;

//     return ;
    
// }

int main()
{
    Node* Node1 = new Node(5); // dynimically nod1 naam ka object bnaya hai
    Node* head_of_LL = Node1 ; // Node1 khud pointer hai (this is not double pointer , this is pointing to same address jisko Node1 point kr rha hai  
    Node* tail_of_LL = Node1 ;
    add_new_node_at_end(tail_of_LL,6);
    add_new_node_at_end(tail_of_LL,7);
    add_new_node_at_end(tail_of_LL,8);
    add_new_node_at_end(tail_of_LL,9);

    // print_L_L(head_of_LL);

    // reverse_L_L(head_of_LL);
    // reverse_using_recursion_1(head_of_LL, NULL, head_of_LL);
    // reverse_using_recursion_2(head_of_LL);

    print_L_L(head_of_LL);
}