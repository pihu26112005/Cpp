// shprtets distance based on weights in directed graphs 

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std ;

void topologicSort (unordered_map<int,list<pair<int,int>>> adj , unordered_map<int,bool> &visited , stack<int> &ans , int node)
{
    visited[node]=true;

    for(auto i:adj[node])
    {
        if(!visited[i.first])
        {
            topologicSort(adj,visited,ans,i.first);
        }
    }
    ans.push(node);
}

vector<int> shortestPathDirected(unordered_map<int,list<pair<int,int>>> adj , int start)
{
    unordered_map<int,bool> visited;
    stack<int> s;
    topologicSort(adj,visited,s,0);

    vector<int> ans(adj.size(), INT64_MAX) ;
    ans[start]=0;
    
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        if(ans[top]!=INT64_MAX)
        {
            for(auto i:adj[top])
            {
                int dis = ans[top]+i.second;
                if(dis<ans[i.first])
                {
                    ans[i.first] = dis;
                }
            }
        }
    }
}