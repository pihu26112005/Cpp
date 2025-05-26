class Solution {
    public:
        // Add cycle detection map
        unordered_map<int, bool> visiting;
    
        int h(unordered_map<int, vector<int>>& m, int node, string& colors, vector<vector<int>>& dp, unordered_map<int, bool>& visited) {
            if (visiting[node]) {
                // cycle detected
                return -1;
            }
    
            if (visited[node]) {
                // already computed
                int mx = 0;
                for (int c = 0; c < 26; ++c) {
                    mx = max(mx, dp[node][c]);
                }
                return mx;
            }
    
            visiting[node] = true;
            visited[node] = true;
    
            int clr = colors[node] - 'a';
            dp[node][clr] = 1;  // at least this node
    
            int res = 1;
    
            if (m.find(node) != m.end()) {
                for (int nei : m[node]) {
                    int t = h(m, nei, colors, dp, visited);
                    if (t == -1) return -1;  // propagate cycle detection
    
                    for (int c = 0; c < 26; ++c) {
                        int add = (c == clr) ? 1 : 0;
                        dp[node][c] = max(dp[node][c], dp[nei][c] + add);
                        res = max(res, dp[node][c]);
                    }
                }
            }
    
            visiting[node] = false;
            return res;
        }
    
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> m;
            int n = colors.size();
    
            for (auto& e : edges) {
                m[e[0]].push_back(e[1]);
            }
    
            vector<vector<int>> dp(n, vector<int>(26, 0));
            unordered_map<int, bool> visited;
    
            int ans = 0;
    
            for (int i = 0; i < n; ++i) {
                int t = h(m, i, colors, dp, visited);
                if (t == -1) return -1;  // cycle detected
                ans = max(ans, t);
            }
    
            return ans;
        }
    };
    
    // visited --> specific for that dfs call 
    // visiting --> pura ek overall visit maintain krne ke liye 
    // also visiting helps in ki hum for all nodes is function ko chala rhe hai na 
    // dp[node][color]: store the max count of each color (a to z) along all path which passes through node
    