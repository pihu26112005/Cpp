// code studio pe na mila 
#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

  pair<int,int> solve(node* root) 
  {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    int getMaxSum(node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }