// search element in a rotated sorted array 
// yad rhe ye bhi ho skta hai ki rotated array na ho  - (l2)

#include<iostream>
using namespace std;
int binarySearch(int arr[], int s , int e , int key) 
{

    int start = s;
    int end = e;
    int mid = start + (end-start)/2;
    while(start <= end) {

        if(arr[mid] == key) {
            cout<<mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}
int main()
{
    int arr[10]={6,7,8,9,0,1,2,3,4,5};
    int n=10;
    int k = 9;
    int s=0,start =0;
    int e=n-1,end = n-1;
    int mid = start + (end-start)/2;
    // to find pivot element 
    while (start<end)
    {
        if (arr[mid]>=arr[0])
        {
            start=mid+1;
        }
        else
        {
            end=mid;
        }
        mid = start + (end-start)/2;
    }

    if(start!=(n-1))  // due to (l2)
    {
        if (k > arr[n-1])
        {
            binarySearch(arr , s , start-1 , k);
        }
        else
        {
            binarySearch(arr,start,e,k);
        }
    }
    else
    {
        binarySearch(arr,s,e,k);
    }
}

