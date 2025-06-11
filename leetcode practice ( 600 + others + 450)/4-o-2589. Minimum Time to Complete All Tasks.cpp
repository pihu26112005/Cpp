// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/

class Solution {
    public:
        int findMinimumTime(vector<vector<int>>& tasks) {
            sort(tasks.begin(), tasks.end(), [](const vector<int>& A, const vector<int>& B) {
                return A[1] < B[1];
            });
    
            vector<int> t(2001, 0);
            for (auto i : tasks) {
                int time = i[2];
                // checkin preassignes ude kr sake ?
                for (int j = i[0]; j <= i[1]; j++) {
                    if (t[j] == 1 && time > 0) {
                        time--;
                    }
                }
                // ab agar koi time bacha ho toh use allocate end me 
                if (time > 0) {
                    for (int j = i[1]; j >= i[0]; j--) {
                        if (t[j] == 0 && time > 0) {
                            t[j] = 1;
                            time--;
                        }
                    }
                }
            }
    
            int ans = 0;
            for (int i = 1; i < 2001; i++) {
                if (t[i] == 1) ans++;
            }
            return ans;
        }
    };
    
    // sort by end time jaruri hai 
    // jaise - [[3,5,2],[1,4,3]] , agar humne pahke late end hone vale ko process kr diya letsay , toh hum usko end se time allocate krenge 
    // and then usek baad usse pahle end hone vale ko process krenge , and usko bhi end se time allocate krenge 
    // toh isse overlap hone ke chnaces kam ho jayenge 