/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
          void h(TreeNode* root, TreeNode* &prev, int &mini){
            if(root == NULL) return;
    
            h(root->left, prev, mini);
    
            if(prev != NULL) mini = min(mini, abs(root->val - prev->val));
            prev = root; // update prev after processing
    
            h(root->right, prev, mini);
        }
        int minDiffInBST(TreeNode* root) {
            int mini = INT_MAX;
            TreeNode* prev = NULL;
            h(root, prev, mini);
            return mini;
        }
    };