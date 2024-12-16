#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

// SC - O(h1 + h2)

void BSTintoSortedDoublyLL(node* root , node*& head)
{
    if (root == NULL)
    {
        return ;
    }
    BSTintoSortedDoublyLL(root->right , head);

    root->right = head ;
    if(head->left)
    {
        head->left = root ;
    }
    head = root ;

    BSTintoSortedDoublyLL(root->left , head);

    return ;
}

node* Merge2SortedLL (node* head1 , node* head2)
{
    node* head = NULL;
    node* tail = NULL;

    while(head1!=NULL && head2!=NULL)
    {
        if (head1->data<head2->data)
        {
            if (head==NULL)
            {
                head = head1 ;
                tail = head1 ;
                head1 = head1->right ;
            }
            else
            {
               tail = head2 ;
                head2 = head2->right ;
            }
        }
        else 
        {
            if (head==NULL)
            {
                head = head2 ;
                tail = head2 ;
                head2 = head2->right ;
            }
            else
            {
               tail = head1 ;
                head1 = head1->right ;
            }
        }
        
    }

    while (head1!=NULL)
    {
         if (head==NULL)
            {
                head = head1 ;
                tail = head1 ;
                head1 = head1->right ;
            }
            else
            {
               tail = head2 ;
                head2 = head2->right ;
            }
    }

    while (head2 != NULL)
    {
        if (head==NULL)
            {
                head = head2 ;
                tail = head2 ;
                head2 = head2->right ;
            }
            else
            {
               tail = head1 ;
                head1 = head1->right ;
            }
    }
    
    
}

node* SortedLLintoBST(node* head , int n) // n is length of total merged ll in step 2 
{
    if (n<0 || head == NULL) // hum leaf node pe phunch gye ya head LL me traverse krta krta end pe phunch gya 
    {
        return NULL ;
    }

    node* leftp = SortedLLintoBST(head , n/2);

    node* root = head ;
    root->left = leftp;

    head = head->right ;

    root->right = SortedLLintoBST(head , n-1-n/2);

    return root ;
}