// codestudio -  BST to Min Heap

#include "../L-62(BINARY TREE)/myclass.h"  
#include<iostream>
#include<queue>
using namespace std;

void inorder(node* root , vector<int>& v) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

void BSTtoHeap(node* &root , int &index , int in[])
{
    if (root==NULL)
    {
        return ;
    }

    root->data = in[index];
    index++;

    BSTtoHeap(root->left,index,in);
    BSTtoHeap(root->right,index,in);

    return ;
    
}