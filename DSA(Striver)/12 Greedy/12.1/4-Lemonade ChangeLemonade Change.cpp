class Solution {
public:
     bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m; // Stores count of 5s and 10s
        m[5] = 0;
        m[10] = 0;

        for (int bill : bills) {
            if (bill == 5) {
                m[5]++;
            } else if (bill == 10) {
                if (m[5] > 0) {
                    m[5]--;
                    m[10]++;
                } else {
                    return false; // Cannot give change
                }
            } else { // bill == 20
                if (m[10] > 0 && m[5] > 0) { // Use one $10 and one $5
                    m[10]--;
                    m[5]--;
                } else if (m[5] >= 3) { // Use three $5s
                    m[5] -= 3;
                } else {
                    return false; // Cannot give change
                }
            }
        }
        return true;
    }
};