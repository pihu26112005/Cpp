// L-113 DP same 

class Solution {
public:

    
// top down 

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

        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve1(n,days,cost,0,dp);
    }
};