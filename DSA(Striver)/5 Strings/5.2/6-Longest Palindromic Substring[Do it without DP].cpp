class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string sans = "";
        for (int i = 0; i < s.length(); i++) {
            // Check for even-length palindrome
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                int l = i;
                int r = i + 1;
                int len = 0;

                while (l >= 0 && r < s.length() && s[l] == s[r]) {
                    l--;
                    r++;
                    len += 2; // Increase length by 2 for even palindrome
                }
                if (len > ans) {
                    sans = s.substr(l + 1, r - l - 1); // Fix substring calculation
                    ans = len;
                }
            }

            // Check for odd-length palindrome
            int l = i;
            int r = i;
            int len = 0; // Start with 1 for the center character

            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
                len += 2; // Increase length by 2 for odd palindrome
            }
            len--;
            if (len > ans) {
                sans = s.substr(l + 1, r - l - 1); // Fix substring calculation
                ans = len;
            }
        }
        return sans;
    }
};
