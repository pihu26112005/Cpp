#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 
#include<map>v

void levelOrderTraversal(  queue<node*> q  , vector<int>& ans )
{
    if (q.size() == 0) // base case 
    {
        return ;
    }
       ans.push_back(q.front()->data);
    
    queue<node*> q2 ;

    while (!q.empty())
    {

        if ((q.front()->left != NULL) && (q.front()->right != NULL))
        {
        q2.push(q.front()->right); // HERE IS THE CHANGE 
        q2.push(q.front()->left);
        }
        else if ((q.front()->left == NULL) && (q.front()->right != NULL))
        {
            q2.push(q.front()->right);
        }        
        else if ((q.front()->left != NULL) && (q.front()->right == NULL))
        {
            q2.push(q.front()->left);
        }  
        q.pop();
    }

   levelOrderTraversal( q2 , ans );

   return ;
}


vector<int> getLeftView(node *root)
{     vector<int> ans ;

    if(root == NULL)
    {
        return ans ;
    }
    //    Write your code here
    queue<node*> q;
    q.push(root);
    levelOrderTraversal(q, ans);
    return ans ;
}



-----------



class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            queue<TreeNode*> q;
            if (root) q.push(root);
    
            while (!q.empty()) {
                TreeNode* rightSide = nullptr;
                int size = q.size();
    
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front(); q.pop();
                    if (node) {
                        rightSide = node;
                        if (node->left) q.push(node->left);
                        if (node->right) q.push(node->right);
                    }
                }
    
                if (rightSide) {
                    res.push_back(rightSide->val);
                }
            }
    
            return res;
            
        }
    };