// video solution 
// thoda alag - har taraf jaa skte hai , and hume path print krna hai 
// n*n matrix hai

#include<iostream>
#include<vector>
using namespace std;

bool is_safe(int arr[4][4], int n, int i, int j, int visited[4][4])
{
    if (arr[i][j]==1 && visited[i][j]==0 && (i>0 && i<n) && (j>0 && j<n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void possible_ways(int arr[4][4], int n, int visited[4][4], string path, vector<string>& ans, int i, int j)
{
    int rows = n;
    int columns = n;

    if (arr[0][0]==0 || arr[rows-1][columns-1]==0) //  basic 
    {
        return ;
    }
    

    if (i == rows - 1 && j == columns - 1) // base case
    {
        ans.push_back(path);
        return;
    }

    visited[i][j]=1;

    // down 
    int upcoming_i = i;
    int upcoming_j = j+1;
    if (is_safe(arr ,n ,i ,j , visited))
    {
        path.push_back('D');
        possible_ways(arr, n, visited, path, ans, upcoming_i, upcoming_j);
        path.pop_back();
    }
    
        // left
    upcoming_i = i-1;
    upcoming_j = j;
    if (is_safe(arr ,n ,i ,j , visited))
    {
        path.push_back('L');
        possible_ways(arr, n, visited, path, ans, upcoming_i, upcoming_j);
        path.pop_back();
    }

        // right 
    upcoming_i = i+1;
    upcoming_j = j;
    if (is_safe(arr ,n ,i ,j , visited))
    {
        path.push_back('R');
        possible_ways(arr, n, visited, path, ans, upcoming_i, upcoming_j);
        path.pop_back();
    }

        // up
    upcoming_i = i;
    upcoming_j = j-1;
    if (is_safe(arr ,n ,i ,j , visited))
    {
        path.push_back('U');
        possible_ways(arr, n, visited, path, ans, upcoming_i, upcoming_j);
        path.pop_back();
    }

    visited[i][j]=0;
}

int main()
{
    int arr[4][4] = {{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    int n=4;
    int visited_arr[4][4]={0};
    string path ="";
    vector<string> ans;
    int i=0, j=0 ;

    possible_ways(arr, n, visited_arr, path, ans, i, j);

    for(string z: ans)
    {
        cout<<z<<" ";
    }
}
