#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &e, int n, int m, int src) {
	vector<pair<int,int>> adj[n];
        
	for(int i=0;i<m;i++){
		int x=e[i][0];
		int y=e[i][1];
		int wt=e[i][2];
		
		adj[x].push_back({y,wt});
		adj[y].push_back({x,wt});
	}
	
	vector<int> dis(n,INT_MAX);
	queue<int> q;
	
	q.push(src);
	dis[src]=0;
	
	while(q.size()){
		auto t=q.front();
		q.pop();
		
		for(auto it:adj[t]){
			int n=it.first;
			int d=it.second;

			if(dis[n]>dis[t]+d){
				dis[n]=dis[t]+d;
				q.push(n);
			}
		}
	}
	
	return dis;
}