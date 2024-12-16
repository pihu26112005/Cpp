
#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void family_chart(node* root , int& child_data , deque<int>& ans , bool& firstiter)
{
    if (root == NULL)
    {
        return ;
    }
    if (!firstiter)
    {
        ans.push_back(root->data);
    }
    
    if (root->data == child_data)
    {
        firstiter = true;
        return ;
    }
    family_chart(root->left , child_data , ans , firstiter);
    family_chart(root->right , child_data , ans , firstiter);
    if (!firstiter)
    {
        ans.pop_back();
    }
    return ;
}

int kth_ancesstor_find (node* root , int& target_value , int& k)
{
    if (root == NULL)
    {
        return -1 ;
    }
    deque<int> family ;
    bool firstiter = false ;
    family_chart(root , target_value ,family , firstiter);

    for (int i = 0; i < k; i++)
    {
        family.pop_back();
    }
    int ans = family.back();
    return ans ;
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

    int target , k ;
    cin>>target;
    cin>>k;
    cout<<endl<<"ans : "<<kth_ancesstor_find(root , target , k);
}