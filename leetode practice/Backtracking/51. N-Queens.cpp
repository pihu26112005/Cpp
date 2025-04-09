class Solution {
    public:
        void addSolution(vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
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
                if (board[x][y] == 1) return false;
                y--;
            }
    
            // Check upper-left diagonal
            x = row; y = col;
            while (x >= 0 && y >= 0) {
                if (board[x][y] == 1) return false;
                x--; y--;
            }
    
            // Check lower-left diagonal
            x = row; y = col;
            while (x < n && y >= 0) {
                if (board[x][y] == 1) return false;
                x++; y--;
            }
    
            return true;
        }
    
        void solve(int col, vector<vector<int>>& board, vector<vector<string>>& ans, int n) {
            if (col == n) {
                addSolution(board, ans, n);
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
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<int>> board(n, vector<int>(n, 0));
            vector<vector<string>> ans;
            solve(0, board, ans, n);
            return ans;
        }
    };



// 💾 Total Space Complexity = O(n^2 + n × n!)
// 🕒 Total Time Complexity = O(n!) × O(n) = O(n × n!)



// ------------------------------------------------------------------------------------------------------------------
// optimized  n queen -- CHAL NHI RHA 

// using 3 maps in place of 3 for loops for checking is safe 
//o(n) --> o(1)



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
    
        void solve(int col, vector<vector<int>>& board, vector<vector<string>>& ans,
                   int n, vector<int> &leftRow, vector<int> &upperDiagonal,
                   vector<int> &lowerDiagonal) {
            if (col == n) {
                addSolution(board, ans, n);
                return;
            }
    
            for (int row = 0; row < n; row++) {
                // if (isSafe(row, col, board, n)) {
                //     board[row][col] = 1;
                //     solve(col + 1, board, ans, n);
                //     board[row][col] = 0; // backtrack
                // }
    
                if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                    upperDiagonal[n - 1 + col - row] == 0) {
    
                    // place queen
                    board[row][col] = 1;
                    leftRow[row] = 1;
                    lowerDiagonal[row + col] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;
    
                    // recurse
                    solve(col + 1, board, ans, n, leftRow, lowerDiagonal,
                          upperDiagonal);
    
                    // backtrack
                    board[row][col] = 0;
                    leftRow[row] = 0;
                    lowerDiagonal[row + col] = 0;
                    upperDiagonal[n - 1 + col - row] = 0;
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<int>> board(n, vector<int>(n, 0));
            vector<vector<string>> ans;
            vector<int> leftRow(n, 0);               // size n
            vector<int> upperDiagonal(2 * n - 1, 0); // (n - 1 + col - row)
            vector<int> lowerDiagonal(2 * n - 1, 0); // (row + col)
            solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
            return ans;
        }
    };
    
    // 💾 Total Space Complexity = O(n^2 + n!)
    // 🕒 Total Time Complexity = O(n!) × O(n) = O(n!)
    