#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std ;

int shortestPathDirected(vector<vector<int>> edges , int n , int start , int dest)
{
    vector<int> dist(n,INT64_MAX);
    dist[start]=0;

    // n-1 baar hr edges pr check kro aur distance update kro
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(dist[u]!=INT64_MAX && dist[u]+w<dist[v])
            {
                dist[v]=w+dist[u];
            }
        }
    }

    // check for negative cycle 
    for (int j = 0; j < edges.size(); ++j) {
        int u = edges[j][0] ;
        int v = edges[j][1] ;
        int w = edges[j][2];
        if (dist[u] != INT64_MAX && dist[u] + w < dist[v]) {
            // Negative cycle detected
            return -1; // or any other indicator
        }
    }

    return dist[dest];
}