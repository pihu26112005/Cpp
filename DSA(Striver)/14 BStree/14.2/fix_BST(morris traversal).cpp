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


    /*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the number of nodes in the Binary Search Tree.
*/


/*The idea is to visit the tree in an in-order fashion and search for two swapped nodes. After finding the incorrect nodes, we will swap their data. */
TreeNode * FixBST(TreeNode * root) {
    TreeNode * first = NULL, * second = NULL, * prev = new TreeNode (-1);

    TreeNode * curr = root;

    // Using Morris Traversal to traverse the BST in the inorder fashion.
    while (curr != NULL) {
        if (curr -> left == NULL) {
            if (curr -> data < prev -> data) {
                if (first == NULL) {
                    first = prev;
                }
                second = curr;
            }
            prev = curr;
            curr = curr -> right;
        } 
        else {
            TreeNode * temp = curr -> left;
            while (temp -> right and temp -> right != curr) {
                temp = temp -> right;
            }

            if (temp -> right == NULL) {
                temp -> right = curr;
                curr = curr -> left;
            } else {
                temp -> right = NULL;
                if (curr -> data < prev -> data) {
                    if (first == NULL) {
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                curr = curr -> right;
            }
        }
    }

    // Swapping the data of the incorrect nodes to fix the BST.
    swap(first -> data, second -> data);
    return root;
}


/* why we assign first as prev and sec as correct 
ek array socho jo increasing honi chhiye thi but 2 pair hai usme jinme order ulta ho jata hai 
fir pta chalega ki phle pair ke first element ko aur dusre ke second ko hatana chahiye */