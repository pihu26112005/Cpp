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
        void h(TreeNode* root, int &ans, int n){
            if(root==NULL) return;
    
            if(root->left==NULL && root->right==NULL){
                n=n*10+root->val;
                ans+=n;
                return;
            }
    
            if(root->left) h(root->left,ans,n*10+root->val);
            if(root->right) h(root->right,ans,n*10+root->val);
    
            return;
        }
        int sumNumbers(TreeNode* root) {
            int n=0;
            int ans=0;
            h(root,ans,n);
            return ans;
        }
    };