// https://www.geeksforgeeks.org/problems/water-connection-problem5822/1

class Solution {
    public:
      void dfs(int i,vector<vector<pair<int,int>>>adj,queue<int>&q,int &mini,
      vector<int>&vis)
      {
          vis[i]=1;
          for(auto it:adj[i])
          {
              if(!vis[it.first])
              {
                  int val=it.second;
                  mini=min(mini,val);
                  dfs(it.first,adj,q,mini,vis);
              }
          }
          q.push(i);
      }
      vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b,
                                vector<int> d) {
          // code here
          vector<vector<pair<int,int>>>adj(n+1);
          for(int i=0;i<a.size();i++)
          {
              adj[a[i]].push_back({b[i],d[i]});
          }
          vector<int>vis(n+1,0);
          vector<vector<int>>ans;
          vector<int>indegree(n+1,0);
          for(int i=1;i<=n;i++)
          {
              for(auto it:adj[i])
              {
                  indegree[it.first]++;
              }
          }
          for(int i=1;i<=n;i++)
          {
              if(indegree[i]==0)
              {
                  //find minimum d and last vertex in the path
                  queue<int>q;
                  int mini=INT_MAX;
                  dfs(i,adj,q,mini,vis);
                  if(q.front()==i) continue;
                  ans.push_back({i,q.front(),mini});
              }
          }
          return ans;
      }
  };
  