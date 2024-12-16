#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

node* creatseBST (vector<int> v , int s , int e)
{
    if (s>e)
    {
        return NULL ;
    }

    int m = (s+e)/2 ;
    node* mid = new node(m);
    mid->left = creatseBST(v , s , m-1);
    mid->right = creatseBST(v , m+1 , e);
    
}
void inorder(node* root , vector<int>& v) 
{
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}