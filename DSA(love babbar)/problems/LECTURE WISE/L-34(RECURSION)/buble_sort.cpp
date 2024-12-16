// using recursion , bubble sort 

#include<iostream>
using namespace std;
// yaha bubble sort function ne apni khud ke liye arr creat kiya hoga jisme a store hogi 
// toh fir arr me change krne se a me kaise change ho gya 
// hum normalli int vgera ke liye int& krke refernce variable pass krte hai taki usme bhi change aa jae 
// but yha int& arr krne se error aa rha hai 

void bubble_sort(int arr[], int n )
{
    if (n==1) // base case (kab rukna hai)
    {
        return ;
    }
    
    for (int i = 0; i+1 < n; i++)
    {
        if (arr[i+1]<arr[i])
        {
            swap(arr[i+1],arr[i]);
        }
    }
    return bubble_sort(arr, n-1);
}

int main()
{
    int a[5]={1,6,7,3,9};
    bubble_sort(a,5);
    
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    
}