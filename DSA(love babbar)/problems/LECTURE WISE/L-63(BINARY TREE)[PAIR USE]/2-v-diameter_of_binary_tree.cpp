// video solution 
// SC - O(HEIGHT)

#include "../L-62(BINARY TREE)/myclass.h"  

pair<int,int> diameterFast(node* root)
{
        //base case
        if(root == NULL) 
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));; // diameter 
        ans.second = max(left.second , right.second) + 1; // height 

        return ans;
    }


    int diameter(node* root) 
    {
        return diameterFast(root).first;
    }