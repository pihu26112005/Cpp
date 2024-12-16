#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

 template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string result="";
    if(root==NULL)
        return result;

    vector<int> ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root -> data);

    while(!q.empty()) {
        TreeNode<int> * temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            if(temp ->left) {
                q.push(temp ->left);
                ans.push_back(temp->left -> data);
            }
            else
            {
                ans.push_back(-1);
            }

            if(temp ->right) {
                q.push(temp ->right);
                ans.push_back(temp->right -> data);
            }
            else
            {
                ans.push_back(-1);
            }
        }
    }


    for (int i = 0; i < ans.size(); i++) 
    {
        if(ans[i]!=-1)
        {
            result.push_back('0'+ans[i]);
            result.push_back(' ');
        }
        else
        {
            result.push_back('-');
            result.push_back('1');
            result.push_back(' ');
        }
    }
    result.pop_back();

    return result;
}

TreeNode<int>* deserializeTree(string &s)
{
    if(s.size()==2)
        return NULL;
 //    Write your code here for deserializing the tree

    reverse(s.begin(), s.end());

    char val = s.back();
    s.pop_back();
    s.pop_back();

    TreeNode<int>* root = new TreeNode<int> (val-'0');
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* temp = q.front();
        q.pop();
        
        val = s.back();
        s.pop_back();
        if(val=='-')
        {
            temp->left=NULL;
            s.pop_back();
            if(s.size()>1)
                s.pop_back();
        }
        else
        {
            temp->left = new TreeNode<int> (val-'0');
            q.push(temp->left);
            if(s.size()>1)
                s.pop_back();
        }

        val = s.back();
        s.pop_back();
        if(val=='-')
        {
            temp->right=NULL;
            s.pop_back();
            if(s.size()>1)
                s.pop_back();
        }
        else
        {
            temp->right = new TreeNode<int> (val-'0');
            q.push(temp->right);
            if(s.size()>1)
                s.pop_back();
        }

    }

    return root;
}


