class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        // simce general trend is largest to smallest - 
        for (int i = 0; i < s.length(); ++i) {
            // Check if current character is smaller than the next character
            if (i < s.length() - 1 && m[s[i]] < m[s[i + 1]]) {
                ans -= m[s[i]]; // Subtract the current value
            } else {
                ans += m[s[i]]; // Otherwise, add the current value
            }
        }
        return ans;
    }
};
