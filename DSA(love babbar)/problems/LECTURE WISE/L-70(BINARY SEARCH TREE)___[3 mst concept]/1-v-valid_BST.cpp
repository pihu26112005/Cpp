
// upper lower ki rang bada di 

class Solution {
public:
    void check(TreeNode* root, bool& first, long long upper, long long lower) {
        if (root == NULL)
            return;

        if (root->val <= lower || root->val >= upper) {
            first = false;
            return;
        }

        check(root->left, first, root->val, lower);
        check(root->right, first, upper, root->val);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        bool first = true;
        long long lower = LLONG_MIN;
        long long upper = LLONG_MAX;

        check(root, first, upper, lower);
        return first;
    }
};
