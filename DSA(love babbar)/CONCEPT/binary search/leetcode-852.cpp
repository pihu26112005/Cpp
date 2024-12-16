// error showw kr rha tha jab submit kiya toh : khta ki kisi kisi caes me return nhi kr rha 
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
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) 
        {
            return arr[mid];
        }

        else if(arr[mid]<arr[mid+1] ) 
        {
            start = mid + 1;
        }

        else if (arr[mid]>arr[mid+1] )
        { 
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
}

int main() 
{ 

    int even[4] = {0,2,1,0};
    int odd[4] = {0,10,5,2};

    int evenIndex = maxSearch(even, 4);

    cout << evenIndex << endl;

    int oddIndex = maxSearch(odd, 4);

    cout << oddIndex << endl;


    return 0;
}