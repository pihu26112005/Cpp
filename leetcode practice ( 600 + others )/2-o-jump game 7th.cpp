// https://leetcode.com/problems/jump-game-vii/

#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int mx = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            for (int j = max(i + minJump, mx + 1); j <= min(i + maxJump, (int)s.size() - 1); ++j) {
                if (s[j] == '0') {
                    if (j == s.size() - 1) return true;
                    q.push(j);
                }
            }
            mx = i + maxJump;
        }
        return s.back() == '0' && s.size() == 1;  // handle edge case for single-char strings
    }
};

// jaise i ne let say i+2 se i+5 tak queue me daal diye 
// ab i+1 ayega, toh vo i+3 se i+6 dalne ka try krga 
// but i ne mx = i+5 set kr diya hoga 
// toh i+1 ke liye range - (i+3,i+6) ki jagah (i+6,1+6) hogi 