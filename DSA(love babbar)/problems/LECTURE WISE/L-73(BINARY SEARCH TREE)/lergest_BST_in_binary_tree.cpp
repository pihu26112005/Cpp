#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 
#include<iostream>
using namespace std;

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBST(node* root) 
{
    if (root == nullptr) {
        return {true, 0, INT64_MAX, INT64_MIN};
    }

    Info left = largestBST(root->left);
    Info right = largestBST(root->right);

    Info curr;
    if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) 
    {
        curr.isBST = true;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->data, min(left.minVal, right.minVal));
        curr.maxVal = max(root->data, max(left.maxVal, right.maxVal));
    } else 
    {
        curr.isBST = false;
        curr.size = max(left.size, right.size);
        curr.minVal = INT64_MIN;
        curr.maxVal = INT64_MAX;
    }

    return curr;
}



 int main()
 {
    node* root ;
    build_tree(root);

    int len = 0 ;
    int length = -1 ;
    length_binary_tree(root , len , length);
    cout<<endl<<"length"<<length<<endl;

    Info ans = largestBST(root);
    cout<<endl<<"ans : "<<ans.size;
 }
