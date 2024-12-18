class Solution {
public:
    string removeOuterParentheses(string s) {
        // funda ye hia ki jais ehi '(' dikhta hai iska corresponding ')' dhundo 
        // then in dono ke bich me jo kuch hai vo ans me chipka do , then age bad jao 
        string ans;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                i++;
                int j = i;
                int balance = 1;  // Keep track of the balance of parentheses
                while (j < s.length() && balance != 0) {
                    if (s[j] == '(') balance++;
                    else if (s[j] == ')') balance--;
                    j++;
                }
                // Append substring without the outermost parentheses
                ans += s.substr(i, j - i - 1);
                i = j;  // Move i to the next outermost '('
            } else {
                i++;
            }
        }
        return ans;
    }
};
