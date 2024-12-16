class Solution {
public:

    int helper(vector<vector<char>>& mat, int i, int j, int row, int col, int &maxi, vector<vector<int>> &dp){

        //base case...
        if(i >= row || j >= col){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j]; // memoization...
            

        char ch = '1';

        //yha galti hui thi ...

        int right = helper(mat, i , j + 1, row, col, maxi, dp);
        int diagonal = helper(mat, i + 1, j + 1, row, col, maxi, dp);
        int down = helper(mat, i + 1, j, row, col, maxi, dp);

        if(mat[i][j] == ch){

            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans);
            return dp[i][j] = ans;
        }
        else{
            return 0;
        }

    }
    int maximalSquare(vector<vector<char>>& mat) {
        // vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1)); // dp array for memoization...
        int i = 0;
        int j = 0;
        int row = mat.size();
        int col = mat[0].size();
        // int maxi = 0;

        // int ans = helper(mat, i, j, row, col, maxi, dp);

        int maxi = 0;

    vector<int> curr(mat[0].size()+1,0);  // --> dp[i][..]
    vector<int> next(mat[0].size()+1,0);  // --> dp[i+1][..]
        for (int i =  mat.size()-1; i>=0; i--)
        {
            for (int j = mat[0].size()-1; j >=0 ; j--)
            {

                    if(mat[i][j]=='0')
                        {
                            curr[j]=0;
                        }

                    else
                    {
                         int right =0 , digonal = 0 , down = 0;
                            if(j+1<mat[0].size())
                                right = curr[j+1];
                            if(i+1<mat.size() && j+1<mat[0].size())
                                digonal = next[j+1];
                            if(i+1<mat.size())
                                down = next[j];
                        curr[j] = 1 + min(right,min(digonal,down));
                        maxi = max(maxi,curr[j]);
                    }

            }
            next = curr;
        }
        // return dp[0][0]*dp[0][0];
        return maxi*maxi;
        
    }
};
