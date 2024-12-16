// KAHN`S ALGORITHM 

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std ;

bool isCycle (unordered_map<int,list<int>> adj  , int node)
{
    vector<int> indegree; // sirf vo node se kitni node judi hai , ( vo node kitno se jake judti hai not included )
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
    
    int count =0;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        count++;

        for(auto i : adj[frontNode])
        {
            indegree[i]--; // jb bhi node pop hoti hai toh uski adjacent ki indegree ghat jati hai 
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
    }

    if(count == adj.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
 