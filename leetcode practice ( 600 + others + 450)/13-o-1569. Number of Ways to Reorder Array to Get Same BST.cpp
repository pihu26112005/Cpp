class Solution {
    public:
        // table using pascal identity
        // C(n,r)=C(n−1,r−1)+C(n−1,r)
        int numOfWays(vector<int>& nums) {
            int m = nums.size();
            // table.resize(m + 1);
            // for (int i = 0; i < m + 1; ++i) {
            //     table[i] = vector<long long>(i + 1, 1);
            //     for (int j = 1; j < i; ++j) {
            //         table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            //     }
            // }
            pre();
            return (dfs(nums) - 1) % mod;
        }
    
    private:
        // vector<vector<long long>> table;
        long long mod = 1e9 + 7;
        const int MAXN = 1005;
        // int f[MAXN], invf[MAXN], dp[MAXN];
        vector<int> f, invf, dp;
    
        int p(int x, int n) {
            int res = 1;
            x %= mod;
            while (n > 0) {
                if (n & 1)
                    res = (1LL * res * x) % mod;
                x = (1LL * x * x) % mod;
                n >>= 1;
            }
            return res;
        }
        void pre() {
            f.resize(MAXN); invf.resize(MAXN); dp.resize(MAXN);
            f[0] = invf[0] = 1;
            for (int i = 1; i < MAXN; i++) {
                f[i] = (1LL * f[i - 1] * i) % mod;
                invf[i] = p(f[i], mod - 2); // use modular inverse
            }
        }
        int c(int n, int r) {
            if (r < 0 || n < r)
                return 0;
            if (r == 0)
                return 1;
            return (1LL * f[n] * invf[r] % mod * invf[n - r] % mod) % mod;
        }
    
        long long dfs(vector<int>& nums) {
            int m = nums.size();
            if (m < 3)
                return 1;
    
            vector<int> ln, rn;
            for (int i = 1; i < m; ++i) {
                if (nums[i] < nums[0]) {
                    ln.push_back(nums[i]);
                } else {
                    rn.push_back(nums[i]);
                }
            }
    
            long long l = dfs(ln) % mod;
            long long r = dfs(rn) % mod;
    
            // return (((l * r) % mod) * table[m - 1][ln.size()]) % mod;
            return ( ( (l * r) % mod) * c(m-1,ln.size()) ) % mod;
        }
    };
    
    // recusrsively call for left and right part
    // left part --> nodes < curr, right me greater than
    // after let say there are 10 nodes, and 4 are in left, 5 are in right
    // now we need to select 4 out of 9 positions for our left nodes elements
    // multiply -  leftans * rightans * C(position,left number count)
    // C(n, r) = table[n][r]


    // similar to - https://www.interviewbit.com/problems/ways-to-form-max-heap/