#include<iostream>
#include<vector>
using namespace std;

https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// leetcode 
// https://leetcode.com/problems/partition-equal-subset-sum/
// https://leetcode.com/problems/target-sum/
// https://leetcode.com/problems/coin-change/
// https://leetcode.com/problems/coin-change-2/
/************************************************************************************************************************************************************************************************/
// bruteforec recursion 
int solve (int n , vector<int> weight , vector<int> cost , int w , int i)
{
    if(i>=n || w<0)
        return 0 ;

    int include = 0;
    if(weight[i]<=w)
        include = cost[i] + solve(n,weight,cost,w-weight[i],i+1);

    int exclude = 0 + solve(n,weight,cost,w,i+1);
    
    return max(include,exclude);
}

/************************************************************************************************************************************************************************************************/
// recursion + meoization
int solve1 (int n , vector<int> weight , vector<int> cost , int w , int i , vector<vector<int>> &dp)
{
    if(i>=n || w<0)
        return 0 ;
    if(dp[i][w]!=-1)
        return dp[i][w];

    int include = 0;
    if(weight[i]<=w)
        include = cost[i] + solve1(n,weight,cost,w-weight[i],i+1,dp);

    int exclude = 0 + solve1(n,weight,cost,w,i+1,dp);
    
    return (dp[i][w] = max(include,exclude));
}

int main()
{
    int w;
    int n;
    vector<vector<int>> dp(n,vector<int>(w+1.-1));
}

/************************************************************************************************************************************************************************************************/
// tubulation  TC = O(M*N)
int solve2 (int n , vector<int> weight , vector<int> cost , int w  )
{
    vector<vector<int>> dp(n,vector<int>(w+1.0));
    for (int j = weight[0]; j < w; j++)
    {
        if(weight[0]<=w)
            dp[0][j]=cost[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int weigh = 0; weigh <= w; weigh++)
        {
            int include = 0;
            if(weight[i]<=weigh)
                include = cost[i] + dp[i-1][weigh-weight[i]] ;

            int exclude = 0 + dp[i-1][weigh] ;

            dp[i][weigh] = max(include,exclude);  
        }
    }
    return dp[n-1][w];
}
/************************************************************************************************************************************************************************************************/
// space optimization  TC = O(N)                                                                                                                                        
int solve3 (int n , vector<int> weight , vector<int> cost , int w  )
{
    vector<int> prev(w+1.0);
    vector<int> curr(w+1.0);

    vector<vector<int>> dp(n,vector<int>(w+1.0));
    for (int j = weight[0]; j < w; j++)
    {
        if(weight[0]<=w)
            prev[j]=cost[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int weigh = 0; weigh <= w; weigh++)
        {
            int include = 0;
            if(weight[i]<=weigh)
                include = cost[i] + prev[weigh-weight[i]] ;

            int exclude = 0 + prev[weigh] ;

           curr[weigh] = max(include,exclude);  
        }
        prev = curr;
    }
    return dp[n-1][w];
}

// space optimization using single array TC = O(N)                                                                                                                                        
int solve3 (int n , vector<int> weight , vector<int> cost , int w  )
{
    vector<int> curr(w+1.0);

    vector<vector<int>> dp(n,vector<int>(w+1.0));
    for (int j = weight[0]; j < w; j++)
    {
        if(weight[0]<=w)
            curr[j]=cost[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int weigh = w; weigh >=0; weigh--)
        {
            int include = 0;
            if(weight[i]<=weigh)
                include = cost[i] + curr[weigh-weight[i]] ;

            int exclude = 0 + curr[weigh] ;

           curr[weigh] = max(include,exclude);  
        }
    }
    return dp[n-1][w];
}
