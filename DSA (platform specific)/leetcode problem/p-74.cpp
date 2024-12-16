// search in a 2d matrix 
// using binary search in 2d array 

#include<iostream>
using namespace std;
int main()
{   int element ; 
    cin>>element;
    int row = 4, col = 4;
    int arr[row][col]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int beg_row = 0,end_row = row-1;
    int beg_col = 0,end_col = col-1;
    int mid_row = beg_row + (end_row-beg_row)/2;
    int mid_col = beg_col + (end_col-beg_col)/2;
    bool firstiter = true;
    while (beg_row<=end_row && beg_col<=end_col)
    {
        if (element == arr[mid_row][mid_col] || element == arr[mid_row][0] || element == arr[mid_row][end_col])
        {
            cout<<"yes 1"<<endl;
            break;
        }
        else if (element > arr[mid_row][0] && element > arr[mid_row][end_col])
        {
            beg_row = mid_row+1;
        }
        else if (element < arr[mid_row][0])
        {
            end_row = mid_row-1;
        }
        else
        {
            beg_row = mid_row;
            end_row = mid_row;
        }
        if (beg_row == end_row)
        {
            int start = 0;
            int end = col-1;
            int mid = start + (end-start)/2;
            while(start <= end) 
            {
                if(arr[beg_row][mid] == element) 
                {
                    cout<<"yes 2"<<endl;
                    firstiter = false;
                    break;
                }
                if(element > arr[beg_row][mid]) 
                {
                    start = mid + 1;
                }
                else
                { 
                    end = mid - 1;
                }

                mid = start + (end-start)/2;
            }   
        }
        if (firstiter == false)
        {
            break;
        }
        mid_row = beg_row + (end_row-beg_row)/2;
        mid_col = beg_col + (end_col-beg_col)/2;
    }
    
}