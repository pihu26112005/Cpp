#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

 node* lca(node* root ,int n1 ,int n2 )
    {
       //base case
        if(root == NULL) // base case for null
        {
            return NULL; // base case for not null
        }
        
        if(root->data == n1 || root->data == n2) 
        {
            return root;
        }
        
        node* leftAns = lca(root->left, n1, n2);
        node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL)  // iske nich dono hai isliye yha leftans , rightans , null nhi return krna yha isko hi return krna hai 
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL) // iske nich bhi koi ek hi hai but dono nhi hai
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL) // iske niche koi ek toh hai but dono nhi hai
            return rightAns;
        else  // iske niche dono me se ek bhi nhi hai
            return NULL;
    }