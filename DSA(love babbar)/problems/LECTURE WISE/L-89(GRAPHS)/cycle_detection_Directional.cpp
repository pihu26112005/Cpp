#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std ;

bool isCycle (unordered_map<int,list<int>> adj , unordered_map<int,bool> &visited , unordered_map<int,bool> &DFSvisited , int node)
{
    visited[node]=true;
    DFSvisited[node]=true;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            bool ans = isCycle(adj,visited,DFSvisited,i);
            if(ans)
                return true ;
        }
        else
        {
            if(DFSvisited[i])
            {
                return true;
            }
        }
    }
    DFSvisited[node] = false;
    return false;
}