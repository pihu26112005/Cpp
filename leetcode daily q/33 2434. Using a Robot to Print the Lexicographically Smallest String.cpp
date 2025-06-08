class Solution {
    public:
        string robotWithString(string s) {
            int n = s.size();
            vector<char> minSuffix(n);  
    
            minSuffix[n - 1] = s[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                minSuffix[i] = min(s[i], minSuffix[i + 1]);
            }
    
            string result = "";
            stack<char> t;
    
            for (int i = 0; i < n; ++i) {
                t.push(s[i]);
    
                while (!t.empty() && (i == n - 1 || t.top() <= minSuffix[i + 1])) {
                    result += t.top();
                    t.pop();
                }
            }
    
            return result;
        }
    };
    
    
    // class Solution {
    // public:
    //     string robotWithString(string s) {
    //         if (s.empty()) return "";
    //         char mn = 'z';
    //         for (char c : s) {
    //             mn = min(mn, c);
    //         }
    //         vector<int> idx;
    //         for (int i = 0; i < s.length(); i++) {
    //             if (s[i] == mn) {
    //                 idx.push_back(i);
    //             }
    //         }
    //         int last = idx.back();
    //         string prefix = "";
    //         for (int i = 0; i <= last; i++) {
    //             if (s[i] != mn) {
    //                 prefix += s[i];
    //             }
    //         }
    //         reverse(prefix.begin(), prefix.end());
    //         string rest = robotWithString(s.substr(last + 1));
    //         string merged;
    //         if(prefix<rest)
    //             merged = prefix+rest;
    //         else
    //             merged = rest+prefix;
    //         return string(idx.size(), mn) + merged;
    //     }
    // };
    