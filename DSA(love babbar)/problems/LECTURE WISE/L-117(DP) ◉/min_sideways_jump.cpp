#include<iostream>
#include<vector>
using namespace std;
/**********************************************************************************************************************************************************************************************/
// recursion
int solve (vector<int> obstacle , int currLane , int currPos)
{
   if(currPos==obstacle.size()-1)
        return 0;
    if(obstacle[currPos+1]!=currLane)
        return solve(obstacle,currLane,currPos+1);
    else
    {
        int ans = 10000;
        for (int i = 1; i < 4; i++)
        {
            if (i!=currLane && obstacle[currPos]!=i)
            {
                ans = min (ans , 1+solve(obstacle,i,currPos));
            }
            
        }
        return ans;
    }
}

/**********************************************************************************************************************************************************************************************/
// recursion + memoization
int solve1 (vector<int> obstacle , int currLane , int currPos , vector<vector<int>> &dp)
{
   if(currPos==obstacle.size()-1)
        return 0;
    if(dp[currLane][currPos]!=-1)
        return dp[currLane][currPos];

    if(obstacle[currPos+1]!=currLane)
        return solve(obstacle,currLane,currPos+1);
    else
    {
        int ans = 10000;
        for (int i = 1; i < 4; i++)
        {
            if (i!=currLane && obstacle[currPos]!=i)
            {
                ans = min (ans , 1+solve(obstacle,i,currPos));
            }
            
        }
        return  dp[currLane][currPos]=ans;
    }
}

/**********************************************************************************************************************************************************************************************/
// tubulation
int solve2(vector<int> obstacle )
{
    vector<vector<int>> dp(4,vector<int> (obstacle.size(),10000));
    dp[0][obstacle.size()-1]=0;
    dp[1][obstacle.size()-1]=0;
    dp[2][obstacle.size()-1]=0;
    dp[3][obstacle.size()-1]=0;
    for (int pos = obstacle.size()-2; pos >=0; pos--)
    {
        for (int lane = 1; lane <=3; lane++)
        {
            if(obstacle[pos+1]!=lane)
                dp[lane][pos]=dp[lane][pos+1];
            else
            {
                int ans = 10000;
                for (int i = 1; i < 4; i++)
                {
                    if (i!=lane && obstacle[pos]!=i)
                    {
                        ans = min (ans , 1+dp[i][pos+1]);
                    }
                    
                }
                dp[lane][pos] = ans;
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    
}
/**********************************************************************************************************************************************************************************************/
// space optimization
int solve3(vector<int> obstacle )
{
    vector<int> curr(4,1000); //--> dp[pos]
    vector<int> next(4,1000); //-->dp[pos+1]
    next[0]=0;
    next[1]=0;
    next[2]=0;
    next[3]=0;
    for (int pos = obstacle.size()-2; pos >=0; pos--)
    {
        for (int lane = 1; lane <=3; lane++)
        {
            if(obstacle[pos+1]!=lane)
                curr[lane]=next[lane];
            else
            {
                int ans = 10000;
                for (int i = 1; i < 4; i++)
                {
                    if (i!=lane && obstacle[pos]!=i)
                    {
                        ans = min (ans , 1+next[i]);
                    }
                    
                }
                curr[lane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2],min(1+next[1],1+next[3]));
}
