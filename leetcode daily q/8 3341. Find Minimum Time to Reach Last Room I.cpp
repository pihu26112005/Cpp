#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0});  // {time, row, col}
        minTime[0][0] = 0;
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int t = current[0], i = current[1], j = current[2];
            
            if (i == n - 1 && j == m - 1) return t;
            
            for (auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    // int waitTime = max(0, moveTime[ni][nj] - (t + 1));
                    // int newTime = t + 1 + waitTime;
                    int newTime = max(moveTime[ni][nj]+1,t+1);
                    
                    if (newTime < minTime[ni][nj]) {
                        minTime[ni][nj] = newTime;
                        pq.push({newTime, ni, nj});
                    }
                }
            }
        }
        return -1;  
    }
};
