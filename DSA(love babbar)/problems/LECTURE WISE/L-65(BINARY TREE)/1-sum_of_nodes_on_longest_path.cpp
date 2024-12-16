
#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 


void node_sumgth_binary_tree(node* root , int& node_sum , int& max_node_sum)
{
    node_sum = node_sum + root->data ;
    max_node_sum = max(max_node_sum,node_sum);
    if (root->left==NULL && root->right==NULL)
    {
        node_sum = node_sum - root->data;
        return ;
    }
    else if (root->left!=NULL && root->right==NULL)
    {
        node_sumgth_binary_tree(root->left , node_sum , max_node_sum);
    }    
    else if (root->left==NULL && root->right!=NULL)
    {
        node_sumgth_binary_tree(root->right , node_sum , max_node_sum);
    }    
    else
    {
        node_sumgth_binary_tree(root->left , node_sum , max_node_sum);
        node_sumgth_binary_tree(root->right , node_sum , max_node_sum);

    }
    node_sum = node_sum - root->data;
    return ;
}

int sum_of_nodes_on_longest_path(node*root) 
{
	//Write your code here.  
        int node_sum = 0 ;
     int max_node_sum = -1 ;
     node_sumgth_binary_tree(root, node_sum , max_node_sum);
    return max_node_sum ;
}

int main()
{
    node* root ;
    build_tree(root);
    bool fir = true ;

    int len = 0;
    int length = -1 ;
    length_binary_tree(root , len , length);
    queue<node*> q;
    q.push(root);
    levelOrderTraversal(length , q );

    cout<<sum_of_nodes_on_longest_path(root );
}