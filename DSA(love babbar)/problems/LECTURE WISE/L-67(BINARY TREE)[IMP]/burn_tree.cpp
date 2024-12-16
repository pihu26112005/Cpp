#include "../L-62(BINARY TREE)/myclass.h"  
#include<map>

node* parentMapandTargetnode(node* root , int target , map<node* , node*> &nodeToTparent)
{
    nodeToTparent[root]=NULL;
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) // level order traverse
    {
        node* temp = q.front();
        q.pop();
        if (temp->data == target) // for target node
        {
            res = temp;
        }

        if (temp->left)
        {
            nodeToTparent[temp->left]=temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            nodeToTparent[temp->right]=temp;
            q.push(temp->right);
        }

    }
    return res;
}

int burnTree(node* targetNode , map<node* ,node*> &nodeToTparent)
{
    map<node*,bool> visited ;
    queue<node*> q;
    q.push(targetNode);
    int time = 0;

    while (!q.empty())// level order traverse 
    {
        bool q_me_add_hua = false ;
        int size = q.size();
        for (int i = 0; i < size; i++) // ek level ko ek sath nipta rhe hai 
        {
            node* top = q.front();
            q.pop();
            if (top->left && !visited[top->left])
            {
                visited[top->left]=1;
                q.push(top->left);
                q_me_add_hua = true;
            }
            if (top->right && !visited[top->right])
            {
                visited[top->right]=1;
                q.push(top->right);
                q_me_add_hua = true;
            }
            if (nodeToTparent[top] && !visited[nodeToTparent[top]])
            {
                visited[nodeToTparent[top]]=1;
                q.push(nodeToTparent[top]);
                q_me_add_hua = true;
            }
        }
        if (q_me_add_hua) // agar q me add hua matlab element burn hua 
        {
            time++;
        }
    }
    return time ;
}