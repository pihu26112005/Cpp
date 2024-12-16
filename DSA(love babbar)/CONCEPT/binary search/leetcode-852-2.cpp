// find maximum element in mountainn arrayy 

#include<iostream>
using namespace std;

int maxSearch(int arr[], int size) 
{
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    while(start < end) 
    {
        if(arr[mid]<arr[mid+1]) 
        {
            start = mid + 1;
        }

        else
        { 
            end = mid;
        }

        mid = start + (end-start)/2;
    }
    return start ;
}

int main() 
{ 

    int even[6] = {2,4,6,5,13,1};
    int odd[5] = {3, 8, 11,5,1};

    int evenIndex = maxSearch(even, 6);

    cout << evenIndex << endl;

    int oddIndex = maxSearch(odd, 5);

    cout << oddIndex << endl;


    return 0;
}