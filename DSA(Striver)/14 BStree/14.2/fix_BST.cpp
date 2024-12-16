#include<iostream>
#include<vector>
using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

    bool swap_node(TreeNode* & node1, TreeNode* & node2){
    swap(node1->data, node2->data);
    bool return_flag = true;
    if (node2->left != NULL) if (node2->data < node2->left->data) return_flag = false;
    if (node2->right != NULL) if (node2->data > node2->right->data) return_flag = false;
    if (node1->left != NULL) if (node1->data < node1->left->data) return_flag = false;
    if (node1->right != NULL) if (node1->data > node1->right->data) return_flag = false;

    swap(node1->data, node2->data); // We redo our swap because later we will swap again in Fix_BST()
    return return_flag;
}

void check_node(TreeNode* & node, int& count, vector<TreeNode*>& a, TreeNode* min_bound, TreeNode* max_bound){
    if (count == 2)
        return;
    bool update_bound = true;
    if (node->data > max_bound->data || node->data < min_bound->data) {
        a[count] = node;
        count++;
        update_bound = false;
        if (node->data > max_bound->data) {
            if (swap_node(node, max_bound)) {
                a[count] = max_bound;
                count = 2;
                return;
            }
        }
        if (node->data < min_bound->data){
            if (swap_node(node, min_bound)){
                a[count] = min_bound;
                count = 2;
                return;
            }
        }
    }
    if (node->left != NULL){
        TreeNode* newMaxBound = update_bound ? node : max_bound;
        check_node(node->left, count, a, min_bound, newMaxBound);
    }
    if (node->right != NULL){
        TreeNode* newMinBound = update_bound ? node : min_bound;
        check_node(node->right, count, a, newMinBound, max_bound);
    }
}

TreeNode* FixBST(TreeNode* & root){
    vector<TreeNode*> a(2);
    int count = 0;
    check_node(root, count, a, new TreeNode(-10000000), new TreeNode(10000000));
    if (a[1] == NULL) a[1] = root;
    int k = a[0]->data;
    a[0]->data = a[1]->data;
    a[1]->data = k;
    return root;
}
