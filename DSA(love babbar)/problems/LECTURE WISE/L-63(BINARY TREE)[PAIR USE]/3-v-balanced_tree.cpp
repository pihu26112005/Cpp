// APPROACH 1  - using pair 
// TC - o(n)
// SC - O(HEIGHT)


#include "../L-62(BINARY TREE)/myclass.h"  

 pair<bool, int> isBalancedFast(node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(left.first && right.first && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(node *root)
    {
        return isBalancedFast(root).first;
    }
    