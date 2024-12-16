#include<iostream>
#include<algorithm>
using namespace std;

template <typename T>
class BinaryTreeNode {
       public:
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

#include<bits/stdc++.h>

pair<int,int> solve(BinaryTreeNode<int> *root)
{
    if(root==NULL)
            return make_pair(0,INT64_MIN);
    // Write your code here

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> ans;
    ans.first = root->data + max(left.first,right.first);
    int temp = root->data + left.first + right.first ;
    int tempL = root->data + left.first;
    int tempR = root->data + right.first;

    ans.second = max(root->data,max(temp,max(tempL,max(tempR,max(left.second,right.second)))));

    return ans;

}

int maxPathSum(BinaryTreeNode<int> *root)
{
    if(root==NULL)
            return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    // Write your code here

   pair<int,int> ans = solve(root);

    return ans.second;


}


/******************************************************************************************************************************************************************************************/

int maxsum(BinaryTreeNode<int> *root,int &maxi){

    if(root==NULL){

        return 0;

    }

    int leftsum=max(0,maxsum(root->left,maxi));

    int rightsum=max(0,maxsum(root->right,maxi));

    int value=root->data;

    maxi=max(maxi,value+rightsum+leftsum);

    return value+max(leftsum,rightsum);

 

}

int maxPathSum(BinaryTreeNode<int> *root)

{

    // Write your code here

    int maxi=INT64_MIN;

    maxsum(root,maxi);

    return maxi;

 

}