// using recusrsion , binary search

#include<iostream>
using namespace std;
//[ SIZE DEPENDENT ] 
bool binary_search(int arr[] ,int n, int key) // har step me array choti kr de rhe hai .
{
    int start = 0, end = n-1;
    int mid = start+ (end - start)/2;
    if (key == arr[mid])
    {
        return true;
    }
    if (key>arr[mid] && n!=1)
    {
        return binary_search(arr+mid+1, n-mid-1, key);
    }
    if (key<arr[mid]&& n!=1)
    {
        return binary_search(arr, mid +1, key);
    }
    else
    {
        return false;
    }
}

// or //

//[ SIZE IN-DEPENDENT ] 
bool binarySearch(int *arr, int s, int e , int k ) // har case me array same hai , bas start end khud de rhe hai 
{

    //base case

    //element not found
    if(s>e)
        return false;

    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k)
        return true;

    if(arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}

int main()
{
    int arr[5]={1,2,3,4,6};
    int key;
    cin>>key;
    cout<<binary_search(arr, 5,key)<<endl;
    
}