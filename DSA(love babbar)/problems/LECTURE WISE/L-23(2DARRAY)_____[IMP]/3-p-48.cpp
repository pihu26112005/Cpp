// rotate images 

#include<iostream>
using namespace std;
int main()
{
    int row = 4, col =4;
    int arr[row][col]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int size = row*col;
    int ans[row][col]={0};
    int temp_row = 0 , temp_col = col-1;
    while (temp_row<row &&  temp_col >=0 )
    {
        int i = 0, j = 0;
        while (i < col &&  j < row)
        {
            ans[j][temp_col] = arr[temp_row][i];
            i++;
            j++;
        }
        temp_row++;
        temp_col--;
    }
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}