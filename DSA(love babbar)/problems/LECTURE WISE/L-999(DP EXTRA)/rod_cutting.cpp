
// it is different from cut rod into segments, and rod cutting problem

    // rod cutting --> prices ki array di ha, kitni bhi length me cut kr skte hai , prices[i] = price of cutting rod of length i, max cost batani hai, cut kitne bhi laga sakte  hai 
        // https://www.naukri.com/code360/problems/rod-cutting-problem_800284
        // https://www.geeksforgeeks.org/problems/rod-cutting0840/1
        // doa 

    // cut rod into segments --> ek rod hai, usko kuch segments me 
        // babbar L-107

    // Min cost to cut a stick -->  cuts array given hsi jisme bataya hai kaha cut laga sakte ha 
        // https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// rod cutting problem
int f1(vector<int>& p, int n, int cl, int rl) {
        if (rl == 0)
            return 0;
        if (cl - 1 == n)
            return INT_MIN;

        int ex = f1(p, n, cl + 1, rl);
        int inc = INT_MIN;
        if (cl <= rl) {
            int nextValue = f1(p, n, cl, rl - cl);
            inc = (nextValue != INT_MIN) ? p[cl - 1] + nextValue : INT_MIN;
        }
        
        return max(ex, inc);
    }


int f2(vector<vector<int>>& dp, vector<int>& p, int n, int cl, int rl) {
        if (rl == 0)
            return 0;

        if (cl - 1 == n)
            return INT_MIN;

        if (dp[cl - 1][rl] != -1)
            return dp[cl - 1][rl];

        int ex = f2(dp, p, n, cl + 1, rl);

        int inc = INT_MIN;
        if (cl <= rl) {
            int nextValue = f2(dp, p, n, cl, rl - cl);
            inc = (nextValue != INT_MIN) ? p[cl - 1] + nextValue : INT_MIN;
        }
        
        return dp[cl - 1][rl] = max(ex, inc);
    }

int cutRod(vector<int> &p, int n)
{
	// Write your code here.
	// return f1(p, n, 1, n);
	vector<vector<int>> dp(p.size()+1,vector<int> (p.size()+1,-1));
	return f2(dp, p, n, 1, n);
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Min cost to cut a stick

lic:
    // int h(int n, vector<int> c, int s, int e, int rs, int re)
    // {
    //     if(s>e)
    //         return 0;
    //     if(rs>=re)
    //         return 0;
    //     int m = (s+(e-s)/2);
    //     int idx = c[m];
    //     int cost = n;
    //     int left = h(m-rs,c,s,m-1,rs,m);
    //     int right = h(re-m,c,m+1,e,m,re);
    //     return cost + left + right;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     return h(n,cuts,0,cuts.size()-1,0,n);
    // }

    // maine socha tha kki har rod length pe bich me cut marte hi taaki aage jab unke left anf right parts me cut maare toh choti length consider krni pade 
    // but eg - c = [1,2,3] , n = 100
    // isme m = 2 aayega pahle, first hum 100 consider krenge ,a nd then 2 pe cut kke fir right part consider krenge 
    // but agar 3 pe cur krte toh 100 sirf ek hi baar consider krna padta , baar baar nhi 

    int h(int n, vector<int>& cuts, int s, int e, int rs, int re, vector<vector<int>> &dp) {
        if (s > e) 
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];

        int minCost = INT_MAX; 

        for (int i = s; i <= e; ++i) {
            int idx = cuts[i]; 
            int cost = (re - rs); 
            int left = h(n, cuts, s, i - 1, rs, idx,dp); // Left segment [rs, idx]
            int right = h(n, cuts, i + 1, e, idx, re,dp); // Right segment [idx, re]

            minCost = min(minCost, cost + left + right);
        }
        dp[s][e] = minCost;

        return minCost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int> (cuts.size()+1,-1));
        return h(n, cuts, 0, cuts.size() - 1, 0, n,dp);
    }