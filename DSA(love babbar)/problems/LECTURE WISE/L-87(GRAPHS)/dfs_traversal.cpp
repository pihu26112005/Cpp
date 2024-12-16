#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std ;

void dfs (int node , unordered_map<int,bool> &visited , unordered_map<int,list<int>> adj , vector<int> &ans)
{
    ans.push_back(node);
    visited[node]=1;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,ans);
        }
    }
    return ;
}