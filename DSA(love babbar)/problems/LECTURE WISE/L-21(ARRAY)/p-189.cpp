// rotate array 
//TLE
#include<iostream>
using namespace std;
int main()
{
    int nums[7]={1,2,3,4,5,6,7};
    int n=7;
    int k = k % n;
    for (int i = 0; i < k; i++)
    {
        int temp = nums[n-1];
        for (int j = n-1; j >0; j--)
        {
            nums[j]=nums[j-1];
        }
        nums[0]=temp;
    }
        for (int i = 0; i < n; i++) // printing 
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
}