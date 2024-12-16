#include<iostream>
#include<vector>
using namespace std ;

bool isSafe(int row , int col , vector<vector<int>> suduko , int val)
{
    for (int i = 0; i < suduko.size(); i++)
    {
        if(suduko[i][col]==val)
        {
            return false ;
        }
        if(suduko[row][i]==val)
        {
            return false;
        }
        if(suduko[3*(row/3)+i/3][3*(col/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> suduko)
{
    int n = suduko.size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if(suduko[row][col]==0)
            {
                for (int i = 1; i <=9; i++)
                {
                    if(isSafe(row,col,suduko,i)) // check
                    {
                        suduko[row][col]=i; /// value rkhdo
                        if(solve(suduko)) /// recusrsion
                        {
                            return true;
                        }
                        else
                        {
                            suduko[row][col]=0; // backtrack
                        }
                    }
                }
                return false;
            }
        }
        
    }
    return true ;
}