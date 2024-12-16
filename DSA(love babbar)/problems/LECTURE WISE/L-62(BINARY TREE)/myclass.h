#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

#ifndef MYCLASS_H  // Header guard to prevent multiple inclusions
#define MYCLASS_H

class node //class representing ek element ko 
{
    public:
    int data ;
    node* left ;
    node* right ;

    node(int d)
    {
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

void build_tree(node*& NODE)// ek pointer node type ka input me liya hai and uske corresponding node create kiya hai
{
    int data ;
    cout<<"enter data or enter -1 "<<endl;
    cin>>data;
    cout<<endl;

   if (data == -1) // base case
   {
    return  ;
   }

    NODE = new node(data);
   
   cout<<"now left of "<<data<<endl;
   build_tree(NODE->left);

   cout<<"now right of "<<data<<endl;
   build_tree(NODE->right);

   return ;
}

void length_binary_tree(node* root , int& len , int& max_len)
{
    len++;
    max_len = max(max_len,len);
    if (root->left==NULL && root->right==NULL)
    {
        len--;
        return ;
    }
    else if (root->left!=NULL && root->right==NULL)
    {
        length_binary_tree(root->left , len , max_len);
    }    
    else if (root->left==NULL && root->right!=NULL)
    {
        length_binary_tree(root->right , len , max_len);
    }    
    else
    {
        length_binary_tree(root->left , len , max_len);
        length_binary_tree(root->right , len , max_len);

    }
    len--;
    return ;
}

 // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// my algo
void levelOrderTraversal( int len , queue<node*> q )
{
    if (len == 0) // base case 
    {
        return ;
    }
    
    queue<node*> q1 ;
    queue<node*> q2 ;

    while (!q.empty())
    {
        q1.push(q.front());

        if ((q.front()->left == NULL) && (q.front()->right == NULL))
        {
            node* temp = new node(0);
            q2.push(temp);
            q2.push(temp);
        }
        else if ((q.front()->left == NULL) && (q.front()->right != NULL))
        {
            node* temp = new node(0);
            q2.push(temp);
            q2.push(q.front()->right);
        }        
        else if ((q.front()->left != NULL) && (q.front()->right == NULL))
        {
            node* temp = new node(0);
            q2.push(q.front()->left);
            q2.push(temp);
        } 
        else
        {
        q2.push(q.front()->left);
        q2.push(q.front()->right);
        }   

        q.pop();
    }
   while (!q1.empty())
   {
        for (int i = 0; i < pow(2,(len-1)); i++)
        {
            cout<<" ";
        }
        
        if (q1.front()->data == 0)
        {
            cout<<" ";
        }
        else
        {
            cout<<q1.front()->data;
        }
        
        for (int i = 0; i < pow(2,(len-1)); i++)
        {
            cout<<" ";
        }
        q1.pop();
   }
   cout<<endl;

   levelOrderTraversal(len-1 , q2 );

   return ;
}

#endif // MYCLASS_H