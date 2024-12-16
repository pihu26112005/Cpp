// L-103 dp

class Solution {
public:
int minCost3(vector<int> cost , int n)
{
    vector<int> minC(n,-1);
    minC[0]=cost[0];
    minC[1]=cost[1];

    for (int i = 2; i < n; i++)
    {
        minC[i]=(min(minC[i-1],minC[i-2])+cost[i]);
    }

    return  min(minC[n-1],minC[n-2]) ;
}

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = minCost3(cost,n);
        return ans;
    }
};