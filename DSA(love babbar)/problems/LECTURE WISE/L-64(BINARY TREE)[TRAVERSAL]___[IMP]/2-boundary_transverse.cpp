#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void boundary_tranverse(node* root , bool left_direction , bool right_direction)
{
    if (root == NULL)
    {
        return ;
    }
    
    if (root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return ;
    }
    if (left_direction && !right_direction)
    {
        cout<<root->data<<" ";
        if (root->left!=NULL && root->right!=NULL)
        {
            boundary_tranverse(root->left , left_direction , right_direction);
            boundary_tranverse(root->right , !left_direction , right_direction);  
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            boundary_tranverse(root->left , left_direction , right_direction);
        }
        else if (root->left==NULL && root->right!=NULL)
        {
            boundary_tranverse(root->right , left_direction , right_direction);
        }
    }
    if (!left_direction && right_direction)
    {
        if (root->left!=NULL && root->right!=NULL)
        {
            boundary_tranverse(root->left , left_direction , !right_direction);
            boundary_tranverse(root->right , left_direction , right_direction);
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            boundary_tranverse(root->right , left_direction , right_direction);
        }
        else if (root->left!=NULL && root->right==NULL)
        {
            boundary_tranverse(root->left , left_direction , right_direction);
        }
        cout<<root->data<<" ";
    }
    if (!left_direction && !right_direction)
    {
        boundary_tranverse(root->left , left_direction , right_direction);
        boundary_tranverse(root->right , left_direction , right_direction);
    }
    return ;
}

int main()
{
   
    node* root ;
    build_tree(root);

    if (root==NULL)
    {
        return 0;
    }

    int len = 0;
    int length = -1 ;
    length_binary_tree(root , len , length);
    queue<node*> q;
    q.push(root);
    levelOrderTraversal(length , q );

    bool left = true ;
    bool right = true ;

    cout<<root->data<<" ";
    boundary_tranverse(root->left , left , !right);
    boundary_tranverse(root->right , !left , right);

}