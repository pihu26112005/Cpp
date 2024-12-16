// har col apni row ko point krega 
// toh first element ke liye row ka baap vo khud , col ka baap row hoga 
// ab jab age ke elements me agar row , ya col kuch bhi same hoga toh vo pichli row ke andar jake union ho jaega 
// at the end , you have group of all baaps , jo rhne chahiye toh agar total me se unka number minus kr de , toh vo aajeyenge jo nhi rhne chahiye 
 

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
class DisjointSet
{
   public:
   vector<int> parent;
   vector<int> size;
   vector<int> rank;
   
   DisjointSet(int n)
   {
       parent.resize(n+1);
       rank.resize(n+1, 0);
       size.resize(n+1);
       
       for(int i=0;i<=n;i++)
       {
           parent[i]=i;
           size[i]=1;
       }
   }
   
   int findUParent(int node)
   {
       if(node==parent[node])
       {
           return node;
       }
       
       return parent[node]=findUParent(parent[node]);
   }
   void unionBySize(int u, int v)
   {
       int ulp_u=findUParent(u);
       int ulp_v=findUParent(v);
       
       if(ulp_u==ulp_v)
       {
           return;
       }
       
       if(size[ulp_u]<size[ulp_v])
       {
           parent[ulp_u]=ulp_v;
           size[ulp_v]+=size[ulp_u];
       }
       else
       {
           parent[ulp_v]=ulp_u;
           size[ulp_u]+=size[ulp_v];
       }
   }
};
int removeStones(vector<vector<int>> &stones){
DisjointSet ds(20005);
   for(auto it : stones){
       int r = it[0];
       int c = it[1];
       ds.unionBySize(r,c+10001);
   }
   unordered_set<int> st;
   for(auto it : stones){
       int par = ds.findUParent(it[0]);
       st.insert(par);
   }
   int comp = st.size();
   return stones.size()-comp;
}