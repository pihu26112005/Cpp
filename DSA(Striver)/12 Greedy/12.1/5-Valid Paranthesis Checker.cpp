class Solution {
public:
    bool checkValidString(string st) {
        stack<int> open; // Stack to store indices of '('
        stack<int> star; // Stack to store indices of '*'

        for (int i = 0; i < st.size(); i++) {
            if (st[i] == '(') {
                open.push(i);
            } else if (st[i] == '*') {
                star.push(i);
            } else if (st[i] == ')') {
                if (!open.empty()) {
                    open.pop(); // Match ')' with '('
                } else if (!star.empty()) {
                    star.pop(); // Match ')' with '*'
                } else {
                    return false; // No '(' or '*' to match ')'
                }
            }
        }

        // Match remaining '(' with '*'
        while (!open.empty() && !star.empty()) {
            if (open.top() > star.top()) {
                return false; // A '(' cannot be matched with a '*' that appears before it
            }
            open.pop();
            star.pop();
        }

        return open.empty(); // Valid if no unmatched '(' remain
    }
};
