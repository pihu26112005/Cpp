// no of path jinme sum of nodes ke data = k 
// code studio pe :  K - Sum Path In A Binary Tree
//  CHAL TOH SHI RHA HAI   BUT QUESTION ME KHA HAI KI LEFT TO RIGHT JANA HAI , AUR SOLUTION DENE HAI 
                          // BUT YE PROGRAM LEFT TO RIGHT NODES KE SARE SOLUTION EK SATH DETA HAI 

#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 

void k_sum_path(node* root , int& k , int& sum , int& count)
{
    if(root==NULL)
    {
        return ;
    }
    sum = sum + root->data;
    if (sum == k)
        {
            count++ ;
        }
    if (root->left != NULL) {
        k_sum_path(root->left , k , sum , count);
    }

    if (root->right != NULL) {
        k_sum_path(root->right , k , sum , count);
    }
    sum = sum - root->data;
    return ;
}

void har_path_ke_liye(node* root , int& k , int& sum , int& count)
{
    if(root==NULL)
    {
        return ;
    }
    if (root->left==NULL && root->right==NULL)
    {
        if (root->data == k)
        {
            count++;
        }
        return ;
    }
    sum = 0;
    k_sum_path(root , k , sum , count);
    har_path_ke_liye(root->left , k , sum , count);
    har_path_ke_liye(root->right , k , sum , count);
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

    int k ;
    cin>>k;
    int sum = 0;
    int paths = 0;
    har_path_ke_liye(root , k , sum , paths);

}

// 2 vctor bne hai ek path , ek ans 
// jha jha sum bda ghata rha hu , vha path me push pop krna hai data
// jha jha coun++ kr rha hu vha vha ans me push krna hai path   