#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

node* solve(vector<int> pre , int &i , int mini , int maxi) // starting mini = int_min , maxi = int_max
{
    if (i>=pre.size() || pre[i]<mini || pre[i]>maxi)
    {
        return NULL ;
    }

    node* root = new node(pre[i]); // i iterate krke btata hai kis data ke correspond node  bnani hai 
    i++;

    root->left = solve(pre , i , mini , root->data);
    root->right = solve(pre , i , root->data , maxi);

    return root ;
}

