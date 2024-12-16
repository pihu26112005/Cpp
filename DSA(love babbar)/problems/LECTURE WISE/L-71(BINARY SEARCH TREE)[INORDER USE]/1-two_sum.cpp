
#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

void inorder(node* root , vector<int>& v) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

bool twoSum(node* root , int k)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return false ;
    }
    
    vector<int> v ;
    inorder(root , v);

    int i = 0;
    int j = v.size()-1;
    while (i<j)
    {
        int sum = v[i]+v[j];
        
        if (sum == k)
        {
            return true ;
        }
        else if (sum > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}