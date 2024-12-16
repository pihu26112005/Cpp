#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int n, int edges, int src) 
{
	vector<vector<pair<int,int>>> adj(n);
    vector<int> vis(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> qu;

    for(auto it: edge){
        adj[it[0]].push_back({it[1],it[2]});
		adj[it[1]].push_back({it[0],it[2]});
    }

    qu.push({0,src});
    vis[0]=0;
    while(!qu.empty()){
        auto it= qu.top();
        qu.pop();
        for(int i=0; i<adj[it.second].size();++i){
            int ind=adj[it.second][i].first;
            int dist=it.first+ adj[it.second][i].second;

            if(vis[ind]>dist){
                vis[ind]=dist;
                qu.push({dist,ind});
            }
        }
    }

    // for(int i=0; i<n;++i){
    //     if(vis[i]==INT_MAX) vis[i]=-1;
    // }

    return vis;
}