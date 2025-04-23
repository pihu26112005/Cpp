class Solution {
    public:
        void h(TreeNode* root, TreeNode* &prev, int &mini){
            if(root == NULL) return;
    
            h(root->left, prev, mini);
    
            if(prev != NULL) mini = min(mini, abs(root->val - prev->val));
            prev = root; // update prev after processing
    
            h(root->right, prev, mini);
        }
    
        int getMinimumDifference(TreeNode* root) {
            int mini = INT_MAX;
            TreeNode* prev = NULL;
            h(root, prev, mini);
            return mini;
        }
    };
    
    
    // we are doing inorder traversal using dfs 
    // hum aate vaqt prev set kr rhe hai 
    // ksii bhi node ke liye uska prev pahle uski left node banegi then 
    // then prev update hoke root ban jata hai, then right call jati hai
    // then right me update hota hai 
    // then again prev update hoke right an jata hai 
    
    // so basically root ke liye prev root->left 
    // and root->right ke liye prev uska root hai 
    
    // inorder array me arr[i] and arr[i+1] ka diff le rhe hai 