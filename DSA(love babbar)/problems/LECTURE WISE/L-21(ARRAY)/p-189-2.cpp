// rotate array 

#include<iostream>
using namespace std;
int main()
{
    int nums[7]={1,2,3,4,5,6,7};
    int n=7;
    int k=3;
    int arr1[n-k]={0};
    int arr2[k]={0};
    for (int i = 0; i < n-k; i++)
    {
        arr1[i]=nums[i];
    }

    for (int j = 0; j < k; j++)
    {
        arr2[j]=nums[n-k+j];
    }


    for (int i = 0; i < k; i++)
    {
        nums[i]=arr2[i];
    }
    for (int i = 0; i < n-k; i++)
    {
        nums[k+i]=arr1[i];
    }
    
    
    for (int i = 0; i < n; i++) // printing 
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}