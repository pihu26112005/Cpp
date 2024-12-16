#include<iostream>
#include<vector>
using namespace std;

https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

/*****************************************************************************************************************************************************************************************************/
// my method - bruteforce
int solve(int n , int k , int j)
{
    if(n==0)
        return 1;
    
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if(i!=j)
        {
            ans = ans + solve(n-1,k,i);
            if(n>1)
                ans = ans + solve(n-2,k,i);
        }
    }
    return ans ;
}

int main()
{
    int ans = 0;
    int n = 3;
    int k = 2;
    for (int i = 0; i < k; i++)
    {
        ans = ans + solve(n-1,k,i);
        if(n>1)
                ans = ans + solve(n-2,k,i);
    }
    cout<<ans;
}
/*****************************************************************************************************************************************************************************************************/
// recursion
int solve(int n , int k)
{
    if(n==1)
        return k;
    if(n==2)
        return (k+k*(k-1));
    
    int same = (k-1)*solve(n-2,k);
    int diff = (k-1)*solve(n-1,k);

    return (same + diff);
}

/*****************************************************************************************************************************************************************************************************/
// recursion + memoization
int solve(int n , int k , vector<int> &dp)
{
    if(n==1)
        return k;
    if(n==2)
        return (k+k*(k-1));
    if(dp[n]!=-1)
        return dp[n];
    
    int same = (k-1)*solve(n-2,k);
    int diff = (k-1)*solve(n-1,k);
    dp[n]=same+diff;

    return dp[n];
}

/*****************************************************************************************************************************************************************************************************/
// tabulation
int solve(int n , int k )
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=k;
    dp[2]=(k+k*(k-1));
    for (int i = 3; i <=n; i++)
    {
        int same = (k-1)*dp[i-2];
        int diff = (k-1)*dp[i-1];
        dp[i]=same+diff;
    }

    return dp[n];
}

/*****************************************************************************************************************************************************************************************************/
// space optimization
int solve(int n , int k )
{
    int prev2 = k;
    int prev = (k+k*(k-1));
    for (int i = 3; i <=n; i++)
    {
        int same = (k-1)*prev2;
        int diff = (k-1)*prev;
        int curr=same+diff;
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}