// concept --> 
    // 1. jo bhi boundary O hoga , ya Koi O kisi boundary O se juda hoga toh vo island nhi bna skte 
    // 2. agar koi O , ya O ka group boundary ke touch me nhi hai toh vo bnayega island 

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* my solution 
iterate kro , jab bhi O mile toh uske charo taraf dekho , agar boundray pr ho , toh age bd jao , vrna agar side element x ho toh ignore , lekin agar O ho toh uske liye check kro 
parent array ki mada se main ye sure kr rha hu ki 1st O ne jb 2nd O ko call kiya , toh dubara 2nd O 1st O ko na call krde 
Then isi tarah O , apne pdosi agle O ko bulate rhenge , agar unme se koi bhi Boundary O nikla toh break , vrna unko X me bdlenge end me */

#include<map>
#include<queue>
#include<iostream>
using namespace std;

bool check(pair<int, int> a, pair<int, int> b) {
    return (a.first == b.first && a.second == b.second);
}

void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here   
    map<pair<int,int>,pair<int,int>> parent;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='O')
            {
                parent[{i,j}]={i,j};
                vector<pair<int,int>> tochange;
                tochange.push_back({i,j});
                queue<pair<int,int>> q;
                q.push({i,j});

                while(!q.empty())
                {
                    auto top = q.front();
                    int x = top.first;
                    int y = top.second;
                    if(x-1<0 || y-1<0 || x+1>=n || y+1>=m)
                        break;

                    if(arr[x-1][y]=='O' && !check( make_pair(x-1,y) , parent[{x,y}] ))
                    {
                        parent[{x-1,y}]={x,y};
                        q.push({x-1,y});
                        tochange.push_back({x-1,y});
                    }
                    if(arr[x+1][y]=='O' && !check( make_pair(x+1,y) , parent[{x,y}] ) )
                    {
                        parent[{x+1,y}]={x,y};
                        q.push({x+1,y});
                        tochange.push_back({x+1,y});
                    }
                    if(arr[x][y-1]=='O' && !check( make_pair(x,y-1) , parent[{x,y}] ) )
                    {
                        parent[{x,y-1}]={x,y};
                        q.push({x,y-1});
                        tochange.push_back({x,y-1});
                    }
                    if(arr[x][y+1]=='O' && !check( make_pair(x,y+1) , parent[{x,y}] ) )
                    {
                        parent[{x,y+1}]={x,y};
                        q.push({x,y+1});
                        tochange.push_back({x,y+1});
                    }
                    
                    q.pop();
                }

                if(q.empty())
                {
                    for(auto i:tochange)
                    {
                        arr[i.first][i.second]='X';
                    }
                }
            }
        }
    }
    return;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*phle sare boundary O queue me rkhe diye aur unko visited kr diya , fir un sbhi pe dfs lga ke unse touch me jitne bhi O the unko sbko bhi visited kr diya 
fir arr pr traverse kiya aur jo bhi O visited nhi tha , usko X me badal diya */

#include<bits/stdc++.h>
using namespace std;

void replaceOWithX(char** arr, int n, int  m)
{
    vector<vector<int>> vis(n, vector<int> (m, 0));

    // stores {row, col}
    queue<pair<int,int>> q;
    // Push all the boundary 0's
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(arr[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};


	// exactly 4 neighbours i.e. Up, Right, Down, Left
        for(int i=0; i<4; i++){
        	// neighbouring row and column
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && arr[nrow][ncol]=='O'){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
            }
        }
    }

    // Traverse the grid again & check if there is a 'O' left that is not visited in vis[], mark them as 'X'.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='O' && vis[i][j]==0){
                arr[i][j] = 'X';
            }
        }
    }
}