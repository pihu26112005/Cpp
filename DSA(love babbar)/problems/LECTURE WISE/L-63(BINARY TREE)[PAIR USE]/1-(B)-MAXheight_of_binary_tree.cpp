
#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 


void length_binary_tree(node* root , int& len , int& max_len)
{
    len++;
    max_len = max(max_len,len);
    if (root->left==NULL && root->right==NULL)
    {
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

int findMaxDepth(node*root) 
{
	//Write your code here.  
        int len = 0 ;
     int height = -1 ;
     length_binary_tree(root, len , height);
    return height ;
}
