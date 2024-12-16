#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

void topologicSort (unordered_map<int,vector<int>> adj , unordered_map<int,bool> &visited , stack<int> &ans , int node)
{
    visited[node]=true;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            topologicSort(adj,visited,ans,i);
        }
    }
    ans.push(node);
}

void dfs(unordered_map<int,vector<int>> transpose , int node ,  unordered_map<int,bool> &vis )
{
    vis[node]=true;
    for(auto i:transpose[node])
    {
        if(!vis[i])
        {
            dfs(transpose,i,vis);
        }
    }

}

int SSC_kosaraju(unordered_map<int,vector<int>> adj)
{
    stack<int> topo;
    unordered_map<int,bool> vis;
    for (int i = 0; i < adj.size(); i++)
    {
        if(!vis[i])
           topologicSort(adj , vis , topo , i);
    }
    
    unordered_map<int,vector<int>> transpose;
    for (int i = 0; i < adj.size(); i++)
    {
        vis[i]=0; // visited ko dubara se zero 
        for(auto j:adj[i])
        {
            transpose[j].push_back(i);
        }
    }

    int count=0;
    while(!topo.empty())
    {
        int top = topo.top();
        topo.pop();
        if(!vis[top])
        {
            count++;
        }
    }
    
}