
#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 


 void traverseLeft(node* root, vector<int> &ans) {
        //base case
        if( (root == NULL) || (root->left == NULL && root->right == NULL) )
            return ;
            
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
            
    }
    
    void traverseLeaf(node* root, vector<int> &ans) {
        //base case
        if(root == NULL)
            return ;
            
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
    }
    
    void traverseRight(node* root, vector<int> &ans) {
        //base case
        if( (root == NULL) || (root->left == NULL && root->right == NULL) )
            return ;
        
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
            
        //wapas aagye
        ans.push_back(root->data);
            
    }
    
    vector <int> boundary(node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        //left part print/store
        traverseLeft(root->left, ans);
        
        //traverse Leaf nodes
        
        //left subtree
        traverseLeft(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
        //traverse right part
        traverseRight(root->right, ans);
        
        return ans;
        
        
    }