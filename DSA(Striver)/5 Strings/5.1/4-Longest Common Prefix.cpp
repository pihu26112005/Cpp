class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.empty()) return "";
        
        string ans = s[0];

        for (int i = 1; i < s.size(); i++) {
            string current = s[i];
            int j = 0;

            while (j < ans.length() && j < current.length() && ans[j] == current[j]) {
                j++;
            }

            ans = ans.substr(0, j);

            if (ans.empty()) {
                return "";
            }
        }

        return ans;
    }
};
