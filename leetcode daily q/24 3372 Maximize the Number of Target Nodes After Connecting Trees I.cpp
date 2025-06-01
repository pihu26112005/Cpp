class Solution {
    public:
        int dfs(int node, int parent, unordered_map<int, vector<int>>& graph, int k) {
            if (k < 0) return 0;
            int count = 1;  // count self
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    count += dfs(neighbor, node, graph, k - 1);
                }
            }
            return count;
        }
    
        int h(int n, int i, unordered_map<int, vector<int>>& m, int k) {
            return dfs(i, -1, m, k);
        }
    
        vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
            unordered_map<int, vector<int>> m2;
            for (auto i : e2) {
                m2[i[0]].push_back(i[1]);
                m2[i[1]].push_back(i[0]);
            }
            unordered_map<int, vector<int>> m1;
            for (auto i : e1) {
                m1[i[0]].push_back(i[1]);
                m1[i[1]].push_back(i[0]);
            }
    
            int m = m2.size();
            vector<int> t2(m, 0);
            for (int i = 0; i < m; i++) {
                int t = h(m, i, m2, k - 1);
                t2[i] += t;
            }
    
            int n = m1.size();
            vector<int> t1(n, 0);
            for (int i = 0; i < n; i++) {
                int t = h(n, i, m1, k);
                t1[i] += t;
            }
    
            int maxi = 0;
            for (int i : t2)
                maxi = max(i, maxi);
    
            for (int i = 0; i < n; i++) {
                t1[i] += maxi;
            }
    
            return t1;
        }
    };
    