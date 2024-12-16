#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

void inorder(node* root , vector<int>& v) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

bool validateBST(node* root) 
{
    if(root == NULL)
    {
        return false ;
    }

    vector<int> ans ;
    bool first = true ;

    inorder(root, ans);

    for(int i=0 ; i<ans.size()-1 ; i++)
    {
        if(ans[i+1]<=ans[i]) // increasing hona chahiye 
           first = false ;
    }

    return first ;
}