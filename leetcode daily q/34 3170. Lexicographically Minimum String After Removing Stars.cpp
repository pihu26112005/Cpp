class Solution {
    public:
        struct CustomCompare {
            bool operator()(const pair<char, int>& a,
                            const pair<char, int>& b) const {
                if (a.first != b.first)
                    return a.first > b.first; // min char first
                return a.second < b.second;   // larger index first
            }
        };
    
        string clearStars(string s) {
            int n = s.size();
            unordered_map<int, bool> removed;
            priority_queue<pair<char, int>, vector<pair<char, int>>, CustomCompare> pq;
    
            for (int i = 0; i < n; ++i) {
                if (s[i] != '*') {
                    pq.push({s[i], i});
                } else {
                    // while (!pq.empty() && removed[pq.top().second]) {
                    //     pq.pop(); 
                    // }
                    if (!pq.empty()) {
                        removed[pq.top().second] = true;
                        pq.pop();
                    }
                    removed[i] = true; 
                }
            }
    
            string ans = "";
            for (int i = 0; i < n; ++i) {
                if (!removed[i]) {
                    ans += s[i];
                }
            }
    
            return ans;
        }
    };
    