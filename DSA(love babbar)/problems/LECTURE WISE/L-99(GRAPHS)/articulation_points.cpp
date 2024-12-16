// basically , dfs tree me rrot node ki agar 1 se jyada child hai toh co articulation point hogi , hum root node ko alag se handle kr rhe hai 
// kyokii jb diff child pr dfs call jati hai toh ho skta hai ki root node ko multiple time check kiya gya ho , toh vo ans me multiple time push kr di jayegi 
// isliye use alag se end me handle kr rhe hai 

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void dfs(int node , unordered_map<int,vector<int>> adj , int timer , int &parent , vector<int> &discoveryTime , vector<int> &low ,  unordered_map<int,bool> &visited , vector<int> &result)
{
    visited[node]=true;
    discoveryTime[node]=low[node]=timer;
    timer++;
    int child = 0;

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
            if(low[i]>discoveryTime[node] && parent!=-1) 
            {
                result.push_back(node);
            }
            child++;
        }
        else
        {
            // back edge ka case
            low[node]=min(low[node],discoveryTime[i]);
        }
    }
    if(parent==-1 && child >1)
       result.push_back(node);
}
vector<vector<int>> articulationPointsFind (unordered_map<int,vector<int>> adj)
{
    int n = adj.size();
    int timer=0;
    int parent=-1;
    vector<int> discoveryTime(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,bool> visited;
    vector<int> result;

    // dfs call to find bridge for each edge 
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, timer, parent, discoveryTime, low, visited, result);
        }
    }
}