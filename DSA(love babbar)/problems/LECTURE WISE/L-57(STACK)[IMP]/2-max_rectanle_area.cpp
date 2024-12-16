#include<iostream>
using namespace std;
#include<vector>
#include<stack>   

// is baar ans , s dono index ke liye hai , pichle question me values ke liye the 
// value compare toh kari hai but ans , s me index hi store vgera kiya hai 
vector<int> nextSmallerElement_index(vector<int> arr, int n) {
        stack<int> s; 
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
vector<int> prevSmallerElement_index(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
 int largestRectangleArea_hist(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement_index(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement_index(heights, n);
        
        int area = -1;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

int largestRectangleArea_matrix(vector<vector<int>> mat)
{
    int area = largestRectangleArea_hist(mat[0]);
    for (int i = 1; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j]!=0)
            {
                mat[i][j]=mat[i][j]+mat[i-1][j];
            }
        }
        int newarea = largestRectangleArea_hist(mat[i]);
        area = max(area,newarea);
   }
   return area ;
}

int main() 
{
    vector<vector<int>> matrix = 
    {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    int max_area = largestRectangleArea_matrix(matrix);
    cout<<max_area;
}