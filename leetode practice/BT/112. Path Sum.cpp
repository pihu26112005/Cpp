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
        bool hasPathSum(TreeNode* root, int t) {
    
            if (root == NULL) return false;
            if (root->left == NULL && root->right == NULL) {
                return (root->val == t);
                // isse ye ho rha hia ki leaf node pe hi ruk jaa rha hai 
                // leaf se niche nhi jaa rha hai 
            }
    
    
            bool a1 = false;
            bool a2 = false;
            if(root->left) a1=hasPathSum(root->left,t-root->val);
            if(root->right) a2=hasPathSum(root->right,t-root->val);
    
            return a1||a2;
        }
    };