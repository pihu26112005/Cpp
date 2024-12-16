#include<iostream>
#include<vector>
using namespace std;

https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

/**********************************************************************************************************************************************************************************************************************************/
// recursive
int solve(int n , int x , int y , int z)
{
    if(n==0)
       return 0;
    if(n<0)
       return -12345678;

    int a = solve(n-x,x,y,z);
    int b = solve(n-y,x,y,z);
    int c = solve(n-z,x,y,z);
    int ans = max(a,max(b,c));
    
    return ans+1;

    // or 
    // int a = solve(n-x,x,y,z)+1;
    // int b = solve(n-y,x,y,z)+1;
    // int c = solve(n-z,x,y,z)+1;
    // int ans = max(a,max(b,c));
    
    // return ans;
}
int main()
{
    int amount = 7;
    cout<<solve(n,x,y,z)==-12345675 ? 0 : solve(n,x,y,z);
}

/**********************************************************************************************************************************************************************************************************************************/
// recursive +  meoization
int solve1(int n , int x , int y , int z , vector<int> &dp)
{
    if(n==0)
       return 0;
    if(n<0)
       return -12345678;
    if(dp[n]!=-1)
       return dp[n];

    int a = solve1(n-x,x,y,z,dp);
    int b = solve1(n-y,x,y,z,dp);
    int c = solve1(n-z,x,y,z,dp);
    dp[n] = max(a,max(b,c))+1;
    
    return dp[n];
}
int main()
{
    int amount = 7;
    vector<int> dp(amount+1,-1);
    cout<<solve1(amount,5,2,2,dp);
}

/**********************************************************************************************************************************************************************************************************************************/
// tabulation
int solve2(int n , int x , int y , int z )
{
    vector<int> dp(n+1,-12345678);
    dp[0]=0;
    for (int i = 1; i <=n; i++)
    {
        if(i-x > 0)
           dp[i]=max(dp[i],1+dp[i-x]);
        if(i-y > 0)
           dp[i]=max(dp[i],1+dp[i-y]);
        if(i-z > 0)
           dp[i]=max(dp[i],1+dp[i-z]);
    }
     
    if(dp[n]<0) // ho sakta hai x,y,z se kabhi bana hi na sako 
       return 0;
    return dp[n];
}
int main()
{
    int amount = 7;
    cout<<solve2(amount,5,2,2);
}

/**********************************************************************************************************************************************************************************************************************************/
// no space optimization 


 ◉ ○ ◌ ◍ ◎ ● ◐ ◑ ◒ ◓ ◔ ◕ ◖ ◗ ◘ ◙ ◚ ◛ ◜ ◝ ◞ ◟ ◠ ◡ ◢ ◣ ◤ ◥ ◦ ◧ ◨ ◩ ◪ ◫ ◬ ◭ ◮ ◯ ◰ ◱ ◲ ◳ ◴ ◵ ◶ ◷ ◸ ◹ ◺ ◻ ◼ ◽ ◾ ◿
✷
