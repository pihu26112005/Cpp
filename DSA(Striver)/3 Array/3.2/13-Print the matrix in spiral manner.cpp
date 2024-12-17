class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        
    int start_row = 0;
    int end_row = arr.size()-1;
    int start_column = 0;
    int end_column = arr[0].size()-1;
    int count = 0, total = arr.size()*arr[0].size();   
    while (count<total)
    {
        for (int j = start_column; count<total && j <= end_column; j++)
        {
            ans.push_back(arr[start_row][j]);
            count++;
        }
        start_row++;
        // cout<<";";
        for (int j = start_row; count<total && j <= end_row; j++)
        {
            ans.push_back(arr[j][end_column]);
            count++;
        }
        end_column--;
        // cout<<";";
        for (int j = end_column; count<total && j >= start_column; j--)
        {
            ans.push_back(arr[end_row][j]);
            count++;
        }
        end_row--;
        // cout<<";";
        for (int j = end_row; count<total && j >= start_row; j--)
        {
            ans.push_back(arr[j][start_column]);
            count++;
        }
        start_column++;
    }
    return ans;
    }
};