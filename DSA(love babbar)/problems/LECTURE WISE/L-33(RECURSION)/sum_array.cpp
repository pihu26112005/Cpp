// using recusrsion sum all elements of array

#include<iostream>
using namespace std;
int sum_array(int arr[] ,int n)
{
    if (n==1)
    {
        return arr[0];
    }
    int sum = arr[0]+sum_array(arr+1, n-1);
    return sum;  
}

int main()
{
    int arr[5]={1,2,3,4,6};
    cout<<sum_array(arr, 5)<<endl;
    
}