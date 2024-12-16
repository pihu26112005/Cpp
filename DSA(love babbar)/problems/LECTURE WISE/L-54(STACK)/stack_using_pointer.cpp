#include<iostream>
// #include<stack>
using namespace std;

class node 
{
    public:
    int data;
    node* previous;
    node* next;
};

class stack 
{
    public:
    int count = -1;
    int size;
    node* head = NULL;

    stack(int size)
    {
        this->size = size;
    }

    void push(int element)
    {
        if (size - count > 0)
        {
            count ++;
            node* x = new node;
            x->data = element;
            x->previous = head;
            x->next = NULL;
            head = x;
        }
    }

    void pop()
    {
        node* temp = head;
        head = head->previous;
        delete(temp);
    }

    void top()
    {
        cout<<head->data<<endl;
    }
};

int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();
    s.pop();
    s.top();
}