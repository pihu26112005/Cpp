// code studio - Vertical Order Traversal , Vertical Binary Tree ,  Vertical Order Traversal

#include "../L-62(BINARY TREE)/myclass.h"  // realitive path se class import 
#include<map>



void vertical_transverse(deque<pair<node*,int>> d , map<int,deque<int>>& m  ) 
{
    vector<int> ans;
    int maxCount = -1;
    int minCount = 10000;
    int size = d.size();
    if (size == 0)
    {
        return ;
    }
    
    while (!d.empty())
    {
        node* root = d.front().first;
        int count = d.front().second;
        d.pop_front();
            m[count].push_back(root->data);
            maxCount = max(maxCount,count);
            minCount = min(minCount,count);
            if (root->right)
            {
                int right_count = count+1;
                pair<node* , int> right_node(root->right,right_count);
                d.push_back(right_node);
            }
            if (root->left)
            {
                int left_count = count-1;
                pair<node* , int> left_node(root->left,left_count);
                d.push_back(left_node);
            }
    }   

    for(int i=minCount;i<=maxCount;i++)
    {
        deque<int> temp = m[i];
        while(!temp.empty())
        {
            int element = temp.front();
            temp.pop_front();
            ans.push_back(element);
        }
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

    map<int,deque<int>> m;
    int count = 0;
    pair<node*,int> p(root,count);
    deque<pair<node*,int>> d;
    d.push_back(p);
    vertical_transverse(d, m );

    for(auto i : m)
    {
        cout<<i.first<<"--> ";
        while (i.second.size()!=0)
        {
            int temp = i.second.front();
            i.second.pop_front();
            cout<<temp<<" ";
        }
        cout<<endl;
    }
}