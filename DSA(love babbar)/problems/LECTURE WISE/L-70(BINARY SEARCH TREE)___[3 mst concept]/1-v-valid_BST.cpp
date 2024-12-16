#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 
void check (node* root , bool& first , int& upper , int& lower)
{
    if (root->data > upper && root-> data < lower)
    {
        first = true ;
    }
    if(root->left)
       check(root->left , first , root->data , lower);
    if(root->right)
       check(root->right , first , upper , root->data);
    
    return ;
}

bool validateBST(node* root) 
{
    if(root == NULL)
    {
        return true ;
    }

    bool first = true;
    int lower = INT64_MIN ;
    int upper = INT64_MAX ;

    check(root , first , upper , lower);

    return first ;
}