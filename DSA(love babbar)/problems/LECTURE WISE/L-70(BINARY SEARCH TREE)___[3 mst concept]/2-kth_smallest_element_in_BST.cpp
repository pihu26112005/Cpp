
#include "../L-69(BINARY SEARCH TREE)/myclass2.h" 

//  approach 1 
void inorder(node* root , vector<int>& v) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

int kthSmallest(node *root, int k)
{
   if(root == NULL)
    {
        return false ;
    }

    vector<int> ans ;

    inorder(root, ans);

    return ans[k-1] ;
}


// approach 2 

void kthElement(node* root , int& k , int& count , int& ans ) // initial ans = -1 , count = 0
{
    if (count != k)
    {
        if(root == NULL) 
        {
            return ;
        }

        kthElement(root->left,k,count,ans);
        count++ ;
        if (count == k)
        {
            ans = root->data ;
        }
        kthElement(root->right,k,count,ans);
        return ;
    }
    else
    {
        return ;
    }
}
