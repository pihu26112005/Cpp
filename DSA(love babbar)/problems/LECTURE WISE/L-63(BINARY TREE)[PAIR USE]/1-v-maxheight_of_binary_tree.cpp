// video solution 

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