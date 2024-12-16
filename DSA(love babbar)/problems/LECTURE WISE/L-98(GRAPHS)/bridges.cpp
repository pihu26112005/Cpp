#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void dfs(int node , unordered_map<int,vector<int>> adj , int timer , int &parent , vector<int> &discoveryTime , vector<int> &low ,  unordered_map<int,bool> &visited , vector<vector<int>> &result)
{
    visited[node]=true;
    discoveryTime[node]=low[node]=timer;
    timer++;

    for(auto i:adj[node])
    {
        if(i==parent)
        {
            continue;
        }
        if(!visited[i])
        {
            dfs(i,adj,timer,node,discoveryTime,low,visited,result);
            // ho skta hai ki i neighbour bridhe edge na ho backedge ho , toh return krte vqt uske parent ko bhi check kre 
            low[node]=min(low[node],low[i]);
            // check for bridge edge 
            if(low[i]>discoveryTime[node])
            {
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(i);
                result.push_back(temp);
            }
        }
        else
        {
            // back edge ka case
            low[node]=min(low[node],discoveryTime[i]);
        }
    }
}
vector<vector<int>> bridgeFind (unordered_map<int,vector<int>> adj)
{
    int n = adj.size();
    int timer=0;
    int parent=-1;
    vector<int> discoveryTime(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,bool> visited;
    vector<vector<int>> result;

    // dfs call to find bridge for each edge 
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, timer, parent, discoveryTime, low, visited, result);
        }
    }
}