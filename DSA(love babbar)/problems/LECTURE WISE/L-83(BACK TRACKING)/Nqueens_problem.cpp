#include<iostream>
#include<vector>
using namespace std;

void addSolution (vector<vector<int>> board , vector<vector<int>> &ans , int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
        ans.push_back(temp);
    }
    return ;
}

bool isSafe (int row , int col , vector<vector<int>> board , int n)
{
    int x = row;
    int y = col;

    // same row 
    while(y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        y--;
    }

    // same column - ye ho hi nhi skta 

    // same left above diagonal 
    x = row ;
    y = col ;
    while (x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }

    // smae left down diagonal
    x = row ;
    y = col ;
    while(x<n && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x++;
        y--;
    }

    return true ;
}
void solve(int col, vector<vector<int>> &board , vector<vector<int>> &ans , int n)
{
    if(col == n)
    {
        addSolution(board,ans,n);
    }

    // solving for each row of particular column 
    for (int row = 0; row < n; row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col]=1; // queen place krdo us row of that col pe 
            solve(col+1,board,ans,n); // since ek col me ek hi queen ayegii so move to next col
            board[row][col]=0; // back track 
        }
    }
    
}