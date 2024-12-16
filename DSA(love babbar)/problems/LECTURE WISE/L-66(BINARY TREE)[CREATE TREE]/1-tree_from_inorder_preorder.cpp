#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 
#include<map>

// int pos_in_inorder(vector<int> in , int&n , int element)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (in[i]==element)
//         {
//             return i ;
//         }
//     }
//     return -1 ;
// }

void create_map(vector<int> in , map<int,int> element_to_value , int n)
{
    for (int i = 0; i < n; i++)
    {
        element_to_value[in[i]]=i;
    }
    return ;
}

node* solve(vector<int> pre , vector<int> in , int n , int& preorder_index  , int inorder_start_index , int inorder_ending_index , map<int,int> element_to_index)
{
    if (preorder_index>=n && inorder_start_index>inorder_ending_index)
    {
        return NULL ;
    }
    
    int element = pre[preorder_index];
    node* root = new node(element);
    int position = element_to_index[element];

    preorder_index++;
    root->left = solve(pre , in , n , preorder_index  , inorder_start_index , position-1 , element_to_index);
    root->right = solve(pre , in , n , preorder_index  , position+1 , inorder_ending_index , element_to_index);

    return root ;
}

// why map - taaki o(n) tc kam ho jae 
// phle hi inorder ke har element ko uske index se map kra do taaki badme o(1) TC me access kr ske