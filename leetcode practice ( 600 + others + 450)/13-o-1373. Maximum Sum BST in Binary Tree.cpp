
class info {
    public:
        int sum;
        bool isbst;
        int maxi;
        int mini;
    };
    
    class Solution {
    public:
        int ans=0;
        info h(TreeNode* root){
            if(root==NULL) return {0,true,INT_MIN,INT_MAX};
    
            info l=h(root->left);
            info r=h(root->right);
            info curr;
            curr.isbst = l.isbst && r.isbst && (root->val<r.mini && root->val>l.maxi);
            curr.mini = min(root->val,l.mini);
            curr.maxi = max(root->val,r.maxi);
            curr.sum = curr.isbst ? l.sum+r.sum+root->val : max(l.sum,r.sum);
            ans=max(ans,curr.sum);
            // question says if max sum is -ve return empty subtree
    
            return curr;
        }
        int maxSumBST(TreeNode* root) {
            // return h(root).sum;
            h(root);
            return ans;
        }
    };
    
    // x->a == (*x).a
    
    