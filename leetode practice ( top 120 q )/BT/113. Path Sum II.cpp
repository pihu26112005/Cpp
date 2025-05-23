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
    
        void h(TreeNode* root, int t, vector<int> temp, vector<vector<int>> &ans){
            if (root == NULL) return ;
            if (root->left == NULL && root->right == NULL) {
                if(root->val == t){
                    temp.push_back(root->val);
                    ans.push_back(temp);
                    return;
                }
                // isse ye ho rha hia ki leaf node pe hi ruk jaa rha hai 
                // leaf se niche nhi jaa rha hai 
            }
    
            temp.push_back(root->val);
            if(root->left) h(root->left,t-root->val,temp,ans);
            if(root->right) h(root->right,t-root->val,temp,ans);
    
            return;
        }
        vector<vector<int>> pathSum(TreeNode* root, int t) {
            vector<int> temp;
            vector<vector<int>> ans;
            h(root,t,temp,ans);
            return ans;
        }
    };