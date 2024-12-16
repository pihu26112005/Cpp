// using recursion , array is sorted or not 

#include<iostream>
using namespace std;
bool is_sorted(int arr[] ,int n)
{
    if (n==1 || n==0)
    {
        return true;
    }
    if (arr[1]<arr[0])
    {
        return false;
    }
    else
    {
        return is_sorted(arr+1, n-1); // HUM AISE BHI PASS KR SKTE HAI !
    }
    
}

int main()
{
    int arr[5]={1,2,3,4,6};
    cout<<(arr+1)[0]<<endl;
    if (is_sorted(arr,5))
    {
        cout<<" ya !";
    }
    
}