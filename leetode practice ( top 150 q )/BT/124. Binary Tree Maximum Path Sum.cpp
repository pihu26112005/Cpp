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
 // ye love babbar me nhi hai 
 class Solution {
    public:
        int maxSum = INT_MIN;
        int dfs(TreeNode* node) {
            if (!node) return 0;
            int left = max(0, dfs(node->left));
            int right = max(0, dfs(node->right));
            int pathSumThroughNode = node->val + left + right; // neg se befaltu me ye kam ho jayega 
            maxSum = max(maxSum, pathSumThroughNode);
            return node->val + max(left, right);
        }
        int maxPathSum(TreeNode* root) {
            dfs(root);
            return maxSum;
        }
    };
    
    
    // For each node:
    // Recursively calculate the maximum gain from left and right subtree.
    // Compute the path sum passing through the current node:
    // path_through_node = node.val + left_gain + right_gain
    // Update the global max with this path_through_node.
    // Return to parent: node.val + max(left_gain, right_gain)
    // (You can’t return both left and right to parent — because that would create a forked path, which is invalid.)
    
    // FIX - When getting the left and right gains, if they’re negative, set them to 0 — because taking a negative path would reduce the total.