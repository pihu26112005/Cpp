#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std ;

void bfs (unordered_map<int,list<int>> adj , unordered_map<int,bool> &visited , vector<int> &ans , int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adj[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
            visited[i]=1;
            }
        }
    }
}

void bfs_for_all(unordered_map<int,list<int>> adj , int noNodes)
{
    unordered_map<int,bool> visited;
    vector<int> ans;

    for (int i = 0; i < noNodes; i++) // agar components me ho toh vo bhi ho jae 
    {
        if(!visited[i])
        {
            bfs(adj,visited,ans,i);
        }
    }
    
}