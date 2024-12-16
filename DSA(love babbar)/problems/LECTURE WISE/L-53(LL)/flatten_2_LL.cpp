#include<iostream>
#include<map>
using namespace std ;


class Node {
public:
	int data;
	Node *next_pointing_pointer;
	Node *child;
	Node() : data(0), next_pointing_pointer(nullptr), child(nullptr){};
	Node(int x) : data(x), next_pointing_pointer(nullptr), child(nullptr) {};
	Node(int x, Node *next, Node *child) : data(x), next_pointing_pointer(next), child(child) {};
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
        Node* current1 = head1;
        Node* current2 = head2;
        Node* merge_head = new Node(-1);
        Node* merge_tail = merge_head;
        while (current1!=NULL && current2!=NULL)
        {
            if (current1->data <= current2->data)
            {
                merge_tail->child = current1;
                merge_tail = current1;
            current1 = current1->child;
            }
            else if (current2->data < current1->data)
            {
                
                merge_tail->child = current2;
                merge_tail = current2;
            current2 = current2->child;
            }
        }
        while (current1!=NULL)
        {
            merge_tail->child = current1;
            merge_tail = current1;
            current1 = current1->child;
        }
        while (current2!=NULL)
        {
            merge_tail->child = current2;
            merge_tail = current2;
            current2 = current2->child;
        }
        return merge_head->child;
    }
    
}

// ending ll me connextion child node se hona chahiye (question bol rha hai)
Node* flatten_LL(Node* head)
{
    // base case 
    if (head==NULL || head->next_pointing_pointer==NULL)
    {
        return head;
    }

    Node* first_head = head;
    Node* sec_head = flatten_LL(head->next_pointing_pointer);
    // first_head->next_pointing_pointer = first_head->child;

    Node* flatten_LL_head = merge_LL(first_head,sec_head);

    return flatten_LL_head;

}

int main(){
    Node* node3 = new Node(5);
    Node* node1 = new Node(1, node3, new Node(2, NULL, new Node(3)));
    Node* node2 = new Node(3, node1, new Node(4));
    Node* head = flatten_LL(node2);
    print_L_L(head);
}