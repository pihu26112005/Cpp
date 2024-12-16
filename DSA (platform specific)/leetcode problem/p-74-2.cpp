#include<iostream>
using namespace std;

int main() 
{   int row = 4, col =4;
    int arr[row][col]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int size = row*col;
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int key;
    cin>>key;
    while(start <= end) 
    {
        if(arr[mid/col][mid%col] == key) 
        {
            cout<<"yes"<<endl;
        }
        if(key > arr[mid/col][mid%col]) 
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
