class Solution {
    public:
        void h(int n, int k, int i, vector<int> &o, vector<vector<int>> &ans){
            if(o.size() == k){
                ans.push_back(o);
                return;
            }
            for(int j = i; j <= n; j++){
                o.push_back(j);
                h(n, k, j + 1, o, ans);
                o.pop_back();
            }
        }
    
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> o;
            h(n, k, 1, o, ans);
            return ans;
        }
    };
    
    
    // O(KC(N,K)) SC and TC