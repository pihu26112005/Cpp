#include<iostream>
#include<vector>
using namespace std;

https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

/************************************************************************************************************************************************************************************************/
int solve(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;

    return ((n-1)*(solve(n-1)+solve(n-2))); 
}
/************************************************************************************************************************************************************************************************/
// recursion+memoization
int solve2(int n , vector<int> &dp)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(dp[n]!=-1)
        return dp[n];

    return (dp[n] = (n-1)*(solve2(n-1,dp)+solve2(n-2,dp))); 
}

/************************************************************************************************************************************************************************************************/
// tabulation
int solve2(int n )
{
    vector<int> dp;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for (int i = 3; i < n; i++)
    {
        dp[i]=(i-1)*(solve2(i-1,dp)+solve2(i-2,dp));
    }
    
    return dp[n];
}

/************************************************************************************************************************************************************************************************/
// space optimization
int solve2(int n )
{
    int prev2=0;
    int prev=1;
    for (int i = 3; i < n; i++)
    {
        int curr = (i-1)*(prev+prev2);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}