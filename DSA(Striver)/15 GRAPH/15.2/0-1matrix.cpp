#include<stack>
#include<queue>
#include <bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    stack<pair<int,int>> s;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                s.push({i,j});
                ans[i][j]=0;
            }
        }
    }

    while(!s.empty())
    {
        auto topa = s.top();
        s.pop();
        queue<pair<int,int>> q;
        q.push(topa);
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=top.first+dx[i];
                int y=top.second+dy[i];
                int val = ans[top.first][top.second];
                if(x>=0 && x<n && y>=0 && y<m && ans[x][y]!=0 && ans[x][y]>val+1)
                {
                    ans[x][y]=val+1;
                    q.push({x,y});
                }
            }
        }
    }

    return ans;
} 