#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
using namespace std;
void makeSet(vector<int> &parent , vector<int> &rank , int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

// basically phle toh hum node se top pr phunch rhe hai parent pr , fir sath he har node ko us top parent pe lga de rhe hai i.e. path compression kr de rhe hai hatho hath hi
int findParent(vector<int> &parent , int node)
{
    if(parent[node]==node)
    {
        return node;
    }

    return parent[node]=findParent(parent,parent[node]); // path compression 
}

void unionSet(int u , int v , vector<int> &parent , vector<int> &rank)
{
    int uP = findParent(parent,u);
    int vP = findParent(parent,v);

    if(rank[uP]<rank[vP])
    {
        parent[uP]=vP;
    }
    else if(rank[vP]<rank[uP])
    {
        parent[vP]=uP;
    }
    else
    {
        parent[vP]=uP;
        rank[uP]++;
    }
}

bool cmp(vector<int> a , vector<int> b)
{
    return a[2]<b[2];
}
int kruskalMST(vector<vector<int>> edges , int n)
{
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int minWeightSum = 0;

    for (int i = 0; i < n; i++)
    {
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int weight = edges[i][2];

        if(u!=v)
        {
            minWeightSum += weight;
            unionSet(u,v,parent,rank);
        }
    }
    return minWeightSum;
}