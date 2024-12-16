// code studio pe - Check If Binary Tree Is Sum Tree Or Not
// TC - o(n) using pair 
// SC - O(HEIGHT)

#include "../L-62(BINARY TREE)/myclass.h"  

 pair<bool,int> isSumTreeFast(node* root) 
 {
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL )  // leaf node case 
        {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool condn = root->data == leftAns.second + rightAns.second;
        
        pair<bool, int> ans;
        
        if(leftAns.first && rightAns.first && condn) {
            ans.first = true;
            ans.second = root->data + leftAns.second + rightAns.second ;
        }
        else
        {
            ans.first = false;
        }
        return ans;
        
    }


    bool isSumTree(node* root)
    {
        return isSumTreeFast(root).first;
    }