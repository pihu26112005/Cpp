class Solution {
    public:
        bool h(vector<vector<char>>& board, string word, int i, int j, int idx) {
            if (idx == word.length())
                return true;
    
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
                board[i][j] != word[idx])
                return false;
    
            char temp = board[i][j];
            board[i][j] = '#'; // mark visited
    
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
    
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (h(board, word, ni, nj, idx + 1))
                    return true;
            }
    
            board[i][j] = temp; // unmark
            return false;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == word[0]) {
                        if (h(board, word, i, j, 0))
                            return true;
                    }
                }
            }
            return false;
        }
    };
    

    // TC - O(m * n * 4^L)
    // SC - O(L)
    // where m is the number of rows, n is the number of columns, and L is the length of the word.