// using morris traverse 
// hme end final resukt me sbko right pointer se jodna hai 
#include "../L-62(BINARY TREE)/myclass.h" 

void flattenBinaryTree(node* root)
{
    if(root==NULL)
    {
        return ;
    }          
    node*curr ;
    node*pre ;
    curr = root ;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            curr = curr->right;
        }
        else
        {
            pre = curr->left ;
            while(pre->right)
            {
                    pre = pre->right ;
            }
            if(pre->right == NULL)
            {
                pre->right = curr->right ;
                curr->right = curr->left ;
                curr->left = NULL ;
                curr = curr->right ;
            }
        }
    }
}