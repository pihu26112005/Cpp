class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Flag to determine if the first row or first column should be zeroed out
        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: Mark the first row and first column if zero is found
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRowZero = true;
                    if (j == 0) firstColZero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Use the first row and first column to set rows and columns to zero
        for (int i = 1; i < m; ++i) {  // skip the first row
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; ++j) {  // skip the first column
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
