#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<int>> adj;

    void make_connection(int u , int v , bool kyaDirectedHai)
    {
        adj[u].push_back(v);
        if(kyaDirectedHai)
        {
            adj[v].push_back(u);
        }
    }
};