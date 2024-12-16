// search element || 

#include<iostream>
using namespace std;
int main()
{
    int element ; 
    cin>>element;
    int row = 5, col = 5;
    int temp_col = col-1;
    int matrix[row][col] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    bool firstiter = true;
    while (temp_col>=0)
    {
        if (element==matrix[0][temp_col])
        {
            cout<<"yes"<<endl;
            break;
        }
        else if (element>matrix[0][temp_col])
        {
            int start = 0;
            int end = row-1;
            int mid = start  + (end - start)/2;
            while (start <= end)
            {
                if (element==matrix[mid][temp_col])
                {
                    cout<<"yes"<<endl;
                    firstiter = false;
                    break;
                }
                else if (element>matrix[mid][temp_col])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
                mid = start  + (end - start)/2;
            }
            if (firstiter == false)
            {
                break;
            }
            else
            {
                temp_col--;
            }
        }
        else
        {
            temp_col--;
        }
    }
    
}