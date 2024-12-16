// APPROACH 1  - BRUTE FORCE 
// TC - o(n*n)

#include "../L-62(BINARY TREE)/myclass.h"  

 int height(node* root)
  {
        //base case
        if(root == NULL) {
            return 0;
        }
        
        int left = height(root ->left);
        int right = height(root->right);
        
        int ans = max(left, right) + 1;
        return ans;
        
}

bool is_balanced_tree (node* root) 
{
    if (root == NULL)
    {
        return true ;
    }

    bool left = is_balanced_tree(root->left);
    bool right = is_balanced_tree(root->right);
    bool diff = abs(height(root->left) - height(root->right))<=1 ;

    if (left && right && diff)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}