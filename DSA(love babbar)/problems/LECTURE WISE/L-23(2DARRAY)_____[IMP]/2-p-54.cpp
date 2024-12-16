// spiral printing

#include<iostream>
using namespace std;
int main()
{
    int row = 3, col = 3;
    int arr[row][col]={{1,2,3},{4,5,6},{7,8,9}};
    int start_row = 0;
    int end_row = 2;
    int start_column = 0;
    int end_column = 2;
    int count = 0, total = 9;   
    while (count<=total)
    {
        for (int j = start_column; count<=total && j <= end_column; j++)
        {
            cout<<arr[start_row][j]<<",";
            count++;
        }
        start_row++;
        // cout<<";";
        for (int j = start_row; count<=total && j <= end_row; j++)
        {
            cout<<arr[j][end_column]<<",";
            count++;
        }
        end_column--;
        // cout<<";";
        for (int j = end_column; count<=total && j >= start_column; j--)
        {
            cout<<arr[end_row][j]<<",";
            count++;
        }
        end_row--;
        // cout<<";";
        for (int j = end_row; count<=total && j >= start_row; j--)
        {
            cout<<arr[j][start_column]<<",";
            count++;
        }
        start_column++;
        // cout<<";";
    }
    
    
}