
class Solution {
    public:
        int h(TreeNode* &root, int valueFromP){
            if(root==NULL) return 0;
    
            int nodevalue = root->val;
            int r = h(root->right,valueFromP);
            root->val = root->val + r + valueFromP;
            int l = h(root->left,root->val);
    
            return r+l+nodevalue;
        }
        TreeNode* convertBST(TreeNode* root) {
            if(root==NULL || (root->right==NULL && root->left==NULL)) return root;
            h(root,0);
            return root;
        }
    };
    
    // h is returning sum of all nodes of subtree rooted at node 
    // for any node , we need to add 2 things 
    // 1- all right subtree nodes value 
    // 2- value coming from parent  
    
    // i first just moved to right with parent value as zero, 
    // since right are greater then current node
    // then i update current node value 
    // then i call left subtree, with that updated node value as parent value 
    
    // so at any node, we first go to right, then process node then go left 
    // so when we go left ALL NODES GREATER THAN IT ARE PROCESSED 
    // 