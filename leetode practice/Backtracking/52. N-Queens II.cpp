class Solution {
    public:
        void addSolution(vector<vector<int>>& board, vector<vector<string>>& ans,
                         int n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string row = "";
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1)
                        row += "Q";
                    else
                        row += ".";
                }
                temp.push_back(row);
            }
            ans.push_back(temp);
        }
    
        bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
            int x = row, y = col;
    
            // Check left side of current row
            while (y >= 0) {
                if (board[x][y] == 1)
                    return false;
                y--;
            }
    
            // Check upper-left diagonal
            x = row;
            y = col;
            while (x >= 0 && y >= 0) {
                if (board[x][y] == 1)
                    return false;
                x--;
                y--;
            }
    
            // Check lower-left diagonal
            x = row;
            y = col;
            while (x < n && y >= 0) {
                if (board[x][y] == 1)
                    return false;
                x++;
                y--;
            }
    
            return true;
        }
    
        void solve(int col, vector<vector<int>>& board, int &ans, int n) {
            if (col == n) {
                // addSolution(board, ans, n);
                ans++;
                return;
            }
    
            for (int row = 0; row < n; row++) {
                if (isSafe(row, col, board, n)) {
                    board[row][col] = 1;
                    solve(col + 1, board, ans, n);
                    board[row][col] = 0; // backtrack
                }
            }
        }
    
        int totalNQueens(int n) {
            vector<vector<int>> board(n, vector<int>(n, 0));
            // vector<vector<string>> ans;
            int ans = 0;
            solve(0, board, ans, n);
            return ans;
        }
    };