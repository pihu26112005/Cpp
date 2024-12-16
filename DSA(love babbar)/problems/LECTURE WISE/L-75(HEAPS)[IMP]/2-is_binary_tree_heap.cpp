#include<iostream>
using namespace std ;
#include "../L-62(BINARY TREE)/myclass.h"  
// tc - o(n) , sc - o(h)

int nodes(node* root)
{
    deque<node*> q;
    int count = 0;
    q.push_back(root);
    while (!q.empty())
    {
        node* top = q.front();
        q.pop_front();
        count++;
        if(top->left)
           q.push_back(top->left);
        if(top->right)
           q.push_back(top->right);
    }
    return count ;
    
}
bool isCBT(node* root , int index , int nodes)
{
    if(root==NULL)
       return true ;
    
    if(index>nodes)
      return false ;

    bool left = isCBT(root->left,2*index+1,nodes);
    bool right = isCBT(root->right,2*index+2,nodes);
    return left&&right ;
}

bool isHeapProperty (node* root )
{
    if(root->left==NULL && root->right==NULL) // leaf node
      return true ;
    if(root->right==NULL) // yha left ke sath && isliye nhi kiya kyokii agar right null hai toh left leaf node hi hoga kyoki agar left ke child hue toh ye cbt nhi satisfy krega 
       return root->data > root->left->data ;

    bool left = isHeapProperty(root->left);
    bool right = isHeapProperty(root->right);
    
    return (root->data > root->left->data && root->data > root->right->data && left && right) ;
}