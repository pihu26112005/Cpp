// rotate array 
// ACCEPTED but beats only 10 % 


#include<iostream>
using namespace std;
int main()
{

// humne 2 new array bnae hai , 
  // ek me shuru ke le (n-k) elemenets kr liye 
    // dusri me last ke (k) elements kr liye 
      //fir arr2 + arr1 lo nums me store kr liya 
    int nums[7]={1,2,3,4,5,6,7};
    int n=7;
    int k=3;
    k = k % n;
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