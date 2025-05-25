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
        priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<>> pq;
        pq.push({0, 0, 0, true});  // {time, row, col, isOneSec}
        minTime[0][0] = 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [t, i, j, isOneSec] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1) return t;

            for (auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int moveCost = isOneSec ? 1 : 2;
                    int newTime = max(moveTime[ni][nj]+moveCost, t + moveCost);

                    if (newTime < minTime[ni][nj]) {
                        minTime[ni][nj] = newTime;
                        pq.push({newTime, ni, nj, !isOneSec});
                    }
                }
            }
        }
        return -1;
    }
};
