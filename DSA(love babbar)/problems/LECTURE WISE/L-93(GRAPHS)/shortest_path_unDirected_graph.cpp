// shortest distance based on length of path in undirected/directed graph (both applicable)

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
#include <bits/stdc++.h> 
using namespace std ;

int shortestPath (unordered_map<int,list<int>> adj , unordered_map<int,bool> &visited  , int startNode , int endNode )
{
    unordered_map<int,int> childTOparent;
    childTOparent[startNode]=-1; // sbse phli startNode 

    queue<int> q;
    q.push(startNode);
    visited[startNode]=1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto i : adj[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
                childTOparent[i]=frontNode;
            }
        }
    }

    vector<int> ans ;
    ans.push_back(endNode);
    while(endNode!=startNode)
    {
        endNode = childTOparent[endNode];
        ans.push_back(endNode);
    }
    reverse(ans.begin(),ans.end());
    // reverse ans before submtiing 
    // return ans ;
}
// why -> ex - ans is 8,3,1 (end = 8 , start = 1)
// but ans should be 1,3,8 .