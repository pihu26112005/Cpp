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


// In a directed graph, a cycle exists only if:
// You can go from a node back to itself through its own DFS path (not just any visited node).

// why not only vis se
// 1 → 2 → 3
// ↓    ↑
// 4 → 5
// If 3 was visited from another path earlier, but not part of current path, visited[3] would be true — but that doesn't mean there's a cycle.


