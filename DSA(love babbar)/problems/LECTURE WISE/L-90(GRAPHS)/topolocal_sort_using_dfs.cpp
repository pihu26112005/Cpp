#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std ;

void topologicSort (unordered_map<int,list<int>> adj , unordered_map<int,bool> &visited , stack<int> &ans , int node)
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
    // std::reverse(ans.begin(), ans.end()); // Reverse to get the correct topological order
    // agar stack se final ve ctor me store kroge toh automatically reverse ho jayega, but agar initial stack ki jagah vec tor us kroge toh end me reverse krna padega
}