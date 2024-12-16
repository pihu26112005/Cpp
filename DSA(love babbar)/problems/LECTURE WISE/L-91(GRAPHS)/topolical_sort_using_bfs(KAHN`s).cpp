// KAHN`S ALGORITHM 

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

void kahnsALGO (unordered_map<int,list<int>> adj  , vector<int> &ans )
{
    vector<int> indegree(adj.size(), 0); // sirf vo node se kitni node judi hai , ( vo node kitno se jake judti hai not included )
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < adj.size(); i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adj[frontNode])
        {
            indegree[i]--; // jb bhi node pop hoti hai toh uski adjacent ki indegree ghat jati hai 
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
    }
}
 