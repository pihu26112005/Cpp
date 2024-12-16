// diameter = length of longest path between any two end nodes 

#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void length_binary_tree(node* root , int& len , int& max_len , int& min_len) // TC - o(n) // this program tells me max and min height 
{
        if(root == NULL)
    {
        return  ;
    }
    else
    {
    len++;
    max_len = max(max_len,len);
    if (root->left==NULL && root->right==NULL)
    {
        min_len = min(min_len,len);
        len--;
        return ;
    }
    else if (root->left!=NULL && root->right==NULL)
    {
        length_binary_tree(root->left , len , max_len , min_len);
    }    
    else if (root->left==NULL && root->right!=NULL)
    {
        length_binary_tree(root->right , len , max_len , min_len);
    }    
    else
    {
        length_binary_tree(root->left , len , max_len , min_len);
        length_binary_tree(root->right , len , max_len , min_len);
    }
    len--;
    return ;
    }
}

int diameter_of_node(node*root) // TC - o(n)
{
     int len = 0 ;
     int min_len = 100000;
     int max_len_left = 0 ;
     int max_len_right = 0 ;
     length_binary_tree(root->left, len , max_len_left , min_len);
     length_binary_tree(root->right, len , max_len_right , min_len);
     len = max_len_left + max_len_right  ;
    return len ;
}

void daimeter_at_each_node(node*root , int& diameter , int& max_diameter) // TC - o(n*n)
{
    diameter = diameter_of_node(root);
    max_diameter = max(max_diameter,diameter);
    if (root->left!=NULL && root->right!=NULL)
    {
        daimeter_at_each_node(root->left , diameter , max_diameter);
        daimeter_at_each_node(root->right , diameter , max_diameter);
    } 
    else if (root->left!=NULL && root->right==NULL)
    {
        daimeter_at_each_node(root->left , diameter , max_diameter);
    }    
    else if (root->left==NULL && root->right!=NULL)
    {
        daimeter_at_each_node(root->right , diameter , max_diameter);
    }   
    else
    {
        return ;
    }
    return;
}


int diameterOfBinaryTree(node*root)
{
	
    int diameter ;
    int max_diameter = 0 ;
    daimeter_at_each_node(root, diameter, max_diameter);

    return max_diameter ;
}
