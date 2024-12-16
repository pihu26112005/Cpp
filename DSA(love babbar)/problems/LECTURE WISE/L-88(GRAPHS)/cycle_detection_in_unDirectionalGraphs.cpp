#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std ;

bool isCycle (unordered_map<int,list<int>> adj , unordered_map<int,bool> &visited , int node)
{
    unordered_map<int,int> childTOparent;
    childTOparent[node]=-1; // sbse phli node 

    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto i : adj[frontNode])
        {
            if(visited[i] && i!=childTOparent[frontNode])
            {
                return true ;
            }

            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
                childTOparent[i]=frontNode;
            }
        }
    }
    return false;
}