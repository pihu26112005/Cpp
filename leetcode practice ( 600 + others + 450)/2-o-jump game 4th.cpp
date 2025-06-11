// https://leetcode.com/problems/jump-game-iv/description/

class Solution {
    public:
        int minJumps(vector<int>& arr) {
            unordered_map<int, vector<int>> m;
            for (int i = 0; i < arr.size(); i++) {
                m[arr[i]].push_back(i);
            }
    
            queue<pair<int, int>> q;
            q.push({0, 0});
            vector<int> vis(arr.size(),0);
            vis[0]=1;
            while (!q.empty()) {
                int s = q.size();
                for (int i = 0; i < s; i++) {
                    auto p = q.front();
                    q.pop();
    
                    int idx = p.first;
                    int lvl = p.second;
    
                    if (idx == arr.size() - 1)
                        return lvl;
    
                    if (idx + 1 < arr.size() && vis[idx+1]==0){
                        q.push({idx + 1, lvl + 1});
                        vis[idx+1]=1;
                    }
                    if (idx - 1 >= 0 && vis[idx-1]==0){
                        q.push({idx - 1, lvl + 1});
                        vis[idx-1]=1;
                    }
                    for (int n : m[arr[idx]]) {
                        if (n != idx && vis[n]==0) {
                            q.push({n, lvl + 1});
                            vis[n]=1;
                        }
                    }
                    m[arr[idx]].clear(); // 🚀 clear after processing all same-value jumps
                }
            }
            return -1;
        }
    };
    
    // A BAHUT GEHRA POINT 
    // Although my vis array make sure i dont hit same index agin and agian
    // but let say 100 is appearing 5 times 
    // then in first 100 i loop over 5 times and push remaining 4 100 in qeuue 
    // next time when i get another 2nd 100, i dont call for any 100 since all are set vis = 1 when 1st 100 push them in queue
    // but still this time i still loop over atleast 5 times, in each loop i check vis and found 1 already so i back off 
    // but atleast i looped over which increaes time complexity 
    // so once i push all remaining 100 in queueu by 1st 100, i should delet it from map m 
    // so next time 2nd 100 or any other 100 dont iterate over any 100 since iterate krenge bhi toh vo daal toh sakte hi nhi toh bekar me iteratee kyo reknge 