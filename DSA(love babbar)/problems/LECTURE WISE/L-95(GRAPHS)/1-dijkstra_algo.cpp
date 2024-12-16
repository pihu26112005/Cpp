// shortest distance based on weights in undirected graphs 

#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std ;

vector<int> shortestPathDirected(int n, unordered_map<int,vector<pair<int,int>>>& adj, int start) {
    // int n = adj.size();
    vector<int> ans(n, INT64_MAX); // Initialize distances with INT_MAX
    ans[start] = 0;
    set<pair<int,int>> s; // <distance from source, node>
    s.insert({0, start});

    while (!s.empty()) {
        auto top = *(s.begin());
        s.erase(s.begin());

        for (auto i : adj[top.second]) {
            int dis = top.first + i.second;
            if (dis < ans[i.first]) {
                auto record = s.find({ans[i.first], i.first});
                if (record != s.end()) {
                    s.erase(record);
                }
                ans[i.first] = dis;
                s.insert({dis, i.first});
            }
        }
    }

    for(int i=0;i<n;i++) // for some disconnected component
    {
        if(ans[i]==INT64_MAX)
            ans[i]=-1;
    }

    return ans;
}