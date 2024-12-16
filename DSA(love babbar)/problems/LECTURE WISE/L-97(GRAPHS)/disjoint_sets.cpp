#include<iostream>
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
void disjointSet()
{
    vector<int> parent;
    vector<int> rank;
}