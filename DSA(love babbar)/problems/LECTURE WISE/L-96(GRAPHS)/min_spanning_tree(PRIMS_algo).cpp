#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std ;

void primsMST (unordered_map<int,list<pair<int,int>>> adj)
{
    int n = adj.size();
    vector<int> key(n,INT64_MAX); // to track minimum distance with source node based on weights 
    vector<bool> mstVisited(n,0); // to track ki algo me sbko ek baar hi visited kre 
    vector<int> parent(n,-1); 

    // start 
    key[0]=0;

    for (int i = 0; i < n; i++) // iterating throught for loop on each node 
    {
        int mini = INT64_MAX;
        int u=0;
        // mini vale node from key nikalo 
        for (int j = 0; j < n; j++) 
        {
            if(key[j]<mini && mstVisited[j]==false)
            {
                u=j;
                mini = key[j];
            }
        }

        // mark mini node mst visited 
        mstVisited[u]=true;

        // call for its adj nodes 
        for(auto it:adj[u])
        {
            int adjNode = it.first;
            int adjWeight = it.second;
            if(mstVisited[adjNode]==false && adjWeight<key[adjNode])
            {
                parent[adjNode]=u;
                key[adjNode]=adjWeight;
            }
        }
    }
}