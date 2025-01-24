
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