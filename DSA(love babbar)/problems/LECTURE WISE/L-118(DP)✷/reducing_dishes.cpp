#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/reducing-dishes/description/
// https://www.naukri.com/code360/problems/minimum-dishes_2280380

/**********************************************************************************************************************************************************************************************/
// recursion
int solve(vector<int> dishes , int index , int time)  // initial time should be 1 
{
    if(index>=dishes.size())
        return 0;

    int include = dishes[index]*time + solve(dishes,index+1,time+1);
    int exclude = 0 + solve(dishes,index+1,time);
    return max(include,exclude);
}
int main()
{
    vector<int> dishes;
    // sort(dishes.begin(),dishes.end());
    solve(dishes,0,1);
}

/**********************************************************************************************************************************************************************************************/
// recursion + memoization
// dp[index][time] --> us time se shuru kre and us index se shuru kre toh max total satisfaction coeff kya hoga 
int solve1 (vector<int> dishes , int index , int time , vector<vector<int>> &dp)
{
    if(index>=dishes.size())
        return 0;
    if(dp[index][time]!=-1)
        return dp[index][time];

    int include = dishes[index]*time + solve(dishes,index+1,time+1);
    int exclude = 0 + solve(dishes,index+1,time);
    return dp[index][time]=max(include,exclude);
}

/**********************************************************************************************************************************************************************************************/
// tubulation
int solve2(vector<int> dishes )
{
    vector<vector<int>> dp(dishes.size()+1,vector<int> (dishes.size()+1,0)); // last vali row phle se ready hai 
    for (int index = s.size()-1; index >=0; index--)
        {
            // index position pe , agar pichli sari dishes exclude kr de , toh time minimum zero ho skta hia, and agar sab ko include kr le toh maximum "index" ho sakta hai, 
            // and yaha hum index position ke liye sare possible time nikal rhe hai  
            for (int time = index; time >=0; time--)
            {
                // time+1 --> kyokii time 0 se nhi 1 se shuru hai 
                int include = s[index]*(time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];
                dp[index][time]=max(include,exclude);
            }
        }
        return dp[0][0];
}
/**********************************************************************************************************************************************************************************************/
// space optimization
int solve3(vector<int> dishes )
{
    vector<int> next(dishes.size()+1,0); //--> dp[index+1][..]
    vector<int> curr(dishes.size()+1,0); //--> dp[index][..]
    for (int index = dishes.size()-1; index >=0; index--)
    {
        for (int time = dishes.size()-1; time >=0; time--)
        {
            int include = dishes[index]*time + next[time+1];
            int exclude = 0 + next[time];
            curr[time]=max(include,exclude);
        }
        next = curr;
    }
    return next[0];
}

// i g 
int solve3(vector<int> dishes )
{
    vector<int> curr(dishes.size()+1,0); //--> dp[index][..]
    for (int index = dishes.size()-1; index >=0; index--)
    {
        for (int time = 0; time <=dishes.size(); time++)
        {
            int include = dishes[index]*time + curr[time+1];
            int exclude = 0 + curr[time];
            curr[time]=max(include,exclude);
        }
    }
    return curr[0];
}