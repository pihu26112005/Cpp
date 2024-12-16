// print like a wave 

#include<iostream>
using namespace std;
int main()
{
    int row = 2, col = 3;
    int arr[row][col]={{1,2,3},{4,5,6}};
    
    for (int i = 0; i < col; i++)
    {
        if (i&1)
        {
            for (int j = 0; j < row; j++)
            {
                cout<<arr[row-(j+1)][i]<<" ";
            }
        }
        else
        {
            for (int j = 0; j < row; j++)
            {
                cout<<arr[j][i]<<" ";
            }
        }
        cout<<",";
    }
}