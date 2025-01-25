#include<iostream>
#include<vector>
using namespace std;

// Recursion me bhi kara tha - 

https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
// lletcode 
// https://leetcode.com/problems/maximal-square/

/********************************************************************************************************************************************************************************************/
// brute force 
// har elment pe jakar dekh rhe hai max kitna bda square bnega , har baar ek new column,ek new roe ko check krek extend kr rhe hai
void extend(int i0 , int j0 , vector<vector<int>> mat , int i , int j , int &maxi)
{
    if(i>=mat.size() || j>=mat[0].size())
        return ;
    if(mat[i+1][j+1]==0)
        return ;
    for (int p = i0; p < i+1; p++)
    {
        if(mat[p][j+1]==0)
            return ;
    }
    for (int p = j0; p < j+1; p++)
    {
        if(mat[i+1][p]==0)
            return ;
    }
    maxi++;
    extend(i0,j0,mat,i+1,j+1,maxi);
    return ;
}
int main()
{
    vector<vector<int>> mat ;
    int ans;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if(mat[i][j]==1)
                extend(i,j,mat,i,j,ans);
        }
        
    }
}
/********************************************************************************************************************************************************************************************/
// recursion 
int solve(vector<vector<int>> mat , int i , int j , int &maxi)
{
    if(i>=mat.size() || j>=mat[0].size())
        return 0;
    if(mat[i][j]==0)
        return 0;
    
    int right = solve(mat,i,j+1,maxi);
    int digonal = solve(mat,i+1,j+1,maxi);
    int down = solve(mat,i+1,j,maxi);
    int ans = 1 + min(right,min(digonal,down));
    maxi = max(maxi,ans);
    return ans;
}

/********************************************************************************************************************************************************************************************/
// recursion  + memoization  TC=O(M*N) SC=O(M*N)
 int helper(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi, vector<vector<int>> &dp){

        //base case...
        if(i >= row || j >= col){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j]; // memoization...
            

        char ch = '1';

        //yha galti hui thi ...

        int right = helper(matrix, i , j + 1, row, col, maxi, dp);
        int diagonal = helper(matrix, i + 1, j + 1, row, col, maxi, dp);
        int down = helper(matrix, i + 1, j, row, col, maxi, dp);

        if(matrix[i][j] == ch){

            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans);
            return dp[i][j] = ans;
        }
        else{
            return 0;
        }

    }

/********************************************************************************************************************************************************************************************/
// tubulation TC=O(M*N) SC=O(M*N)
int solve2(vector<vector<int>> mat)

{
	int maxi=0;
    vector<vector<int>> dp(mat.size(), vector<int> (mat[0].size(),0));
    for (int i =  mat.size()-1; i>=0; i--)
        {
            for (int j = mat[0].size()-1; j >=0 ; j--)
            {
                    int right =0 , digonal = 0 , down = 0;
                    if(j+1<mat[0].size())
                        right = dp[i][j+1];
                    if(i+1<mat.size() && j+1<mat[0].size())
                        digonal = dp[i+1][j+1];
                    if(i+1<mat.size())
                        down = dp[i+1][j];

                    if(mat[i][j]=='0')
		        {
		            dp[i][j] = 0;
		        }

                    else
		    {
		        dp[i][j] = 1 + min(right,min(digonal,down));
		    }

	            maxi = max(maxi,dp[i][j]);
            }
        }
        // return dp[0][0]*dp[0][0];
        return maxi*maxi;

}

/********************************************************************************************************************************************************************************************/
// space optimization TC=O(M*N) SC=O(N)
int solve2(vector<vector<int>> mat)
{
    vector<int> curr(mat[0].size()+1,0);  // --> dp[i][..]
    vector<int> next(mat[0].size()+1,0);  // --> dp[i+1][..]
     for (int j = mat[0].size()-1; j >=0 ; j--)
            {

                    if(mat[i][j]=='0')
                        {
                            curr[j]=0;
                        }

                    else
                    {
                         int right =0 , digonal = 0 , down = 0;
                            if(j+1<mat[0].size())
                                right = curr[j+1];
                            if(i+1<mat.size() && j+1<mat[0].size())
                                digonal = next[j+1];
                            if(i+1<mat.size())
                                down = next[j];
                        curr[j] = 1 + min(right,min(digonal,down));
                        maxi = max(maxi,curr[j]);
                    }

            }
            next = curr;
}

// isko o(1) sc me kro HW
