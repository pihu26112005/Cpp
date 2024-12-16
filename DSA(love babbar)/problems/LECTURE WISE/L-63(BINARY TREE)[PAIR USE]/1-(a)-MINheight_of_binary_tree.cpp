// already done as 
              // length_binary_tree ()  in implementation in L-1

#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void length_binary_tree(node* root , int& len , int& max_len)
{
    len++;
    if (root->left==NULL && root->right==NULL)
    {
        max_len = min(max_len,len);
        len--;
        return ;
    }
    else if (root->left!=NULL && root->right==NULL)
    {
        length_binary_tree(root->left , len , max_len);
    }    
    else if (root->left==NULL && root->right!=NULL)
    {
        length_binary_tree(root->right , len , max_len);
    }    
    else
    {
        length_binary_tree(root->left , len , max_len);
        length_binary_tree(root->right , len , max_len);

    }
    len--;
    return ;
}

int minDepth(node* root)
{
    // write your code here
    if(root == NULL)
    {
        return  0 ;
    }
     int len = 0 ;
     int height = 10000;
     length_binary_tree(root, len , height);
    return height ;
}