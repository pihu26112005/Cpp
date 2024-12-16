#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 
 
void predessor_and_successor(node* root , int target , int pressor , int successor)
{
    node* temp = root ;
    while (temp!=NULL)
    {
        if (target == temp->data)
        {
            break;
        }
        else if (target < temp->data)
        {
            temp = temp->left ;
        }
        else
        {
            temp = temp->right ;
        }
    }

    if (temp && temp->left)
    {
        node* pre = temp->left ;
        while (pre->right != NULL)
        {
            pre = pre->right ;
        }
        pressor = pre->data ; 
    }
    
    if (temp && temp->right)
    {
        node* succ = temp->right ;
        while (succ->left != NULL)
        {
            succ = succ->left ;
        }
        successor = succ->data ;
    }
     
}