#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 
#include<map>

void create_map(vector<int> in , map<int,int> &element_to_value , int n)
{
    for (int i = 0; i < n; i++)
    {
        element_to_value[in[i]]=i;
    }
    return ;
}

node* solve(vector<int> post , vector<int> in , int n , int& postorder_index  , int inorder_start_index , int inorder_ending_index , map<int,int> element_to_index)
{
    if (postorder_index<0 && inorder_start_index>inorder_ending_index)
    {
        return NULL ;
    }
    
    int element = post[postorder_index];
    node* root = new node(element);
    int position = element_to_index[element];

    postorder_index--;
    root->right = solve(post , in , n , postorder_index  , position+1 , inorder_ending_index , element_to_index);
    root->left = solve(post , in , n , postorder_index  , inorder_start_index , position-1 , element_to_index);

    return root ;
}

// why map - taaki o(n) tc kam ho jae 
// phle hi inorder ke har element ko uske index se map kra do taaki badme o(1) TC me access kr ske