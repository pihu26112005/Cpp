#include<iostream>
#include<vector>
#include<queue>
using namespace std;

https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// leetcode 
// https://leetcode.com/problems/minimum-cost-for-tickets/

/**********************************************************************************************************************************************************************************************/
int solve(int n , vector<int> days , vector<int> cost , int index)
{
    if(index>=n)
        return 0;
    
    // 1 din ka paas lete hai
    int ekDin = cost[0] + solve(n,days,cost,index+1);

    // ek hfte vala 
    int i = index;
    while ( i<n && days[i]<days[index]+7)
    {
        i++;
    }
    int hfte = cost[1] + solve(n,days,cost,i);

    // ek mhine
    int j = index;
    while ( j<n && days[j]<days[index]+30)
    {
        j++;
    }
    int mhine = cost[2] + solve(n,days,cost,j);

    int ans = min(ekDin,min(hfte,mhine));
}

/**********************************************************************************************************************************************************************************************/
// recursion + memoization
int solve1(int n , vector<int> days , vector<int> cost , int index , vector<int> &dp)
{
    if(index>=n)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    
    // 1 din ka paas lete hai
    int ekDin = cost[0] + solve1(n,days,cost,index+1,dp);

    // ek hfte vala 
    int i = index;
    while ( i<n && days[i]<days[index]+7)
    {
        i++;
    }
    int hfte = cost[1] + solve1(n,days,cost,i,dp);

    // ek mhine
    int j = index;
    while ( j<n && days[j]<days[index]+30)
    {
        j++;
    }
    int mhine = cost[2] + solve1(n,days,cost,j,dp);

    dp[index] = min(ekDin,min(hfte,mhine));
}

/**********************************************************************************************************************************************************************************************/
// tabulation
int solve2(int n , vector<int> days , vector<int> cost)
{
    vector<int> dp(n+1,-1);
    dp[n]=0;
    for (int k = n-1; k >=0; k++)
    {
        // 1 din ka paas lete hai
        int ekDin = cost[0] + dp[k+1] ;

        // ek hfte vala 
        int i = k;
        while ( i<n && days[i]<days[k]+7)
        {
            i++;
        }
        int hfte = cost[1] + dp[i];

        // ek mhine
        int j = k;
        while ( j<n && days[j]<days[k]+30)
        {
            j++;
        }
        int mhine = cost[2] +dp[j];

        dp[k] = min(ekDin,min(hfte,mhine));
    }
    return dp[0];
}

/**********************************************************************************************************************************************************************************************/
// L-114 (DP SERIES) - SPACE OPTIMIZATION 
int solve3(int n , vector<int> days , vector<int> cost)
{
    int ans = 0;
    queue<pair<int,int>> week;  // pair<day,ab tk ki cost> ka 
    queue<pair<int,int>> month;

    for(int day : days)
    {
        while(!week.empty() && week.front().first + 7 < day)
            week.pop();
        while(!month.empty() && month.front().first + 30 < day)
            month.pop();

        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        ans = min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<int> d = {1,8,15,25,30,60};
    vector<int> m = {1,2,3};
    cout<<solve3(n,d,m);
}