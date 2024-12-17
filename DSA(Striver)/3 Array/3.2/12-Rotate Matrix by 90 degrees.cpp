
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();

        // Step 1: Reflection along the main diagonal (top-left to bottom-right)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }
        }

        // Step 2: Reflection along the vertical axis (left-right)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int temp = m[i][j];
                m[i][j] = m[i][n - j - 1];
                m[i][n - j - 1] = temp;
            }
        }
    }
};
