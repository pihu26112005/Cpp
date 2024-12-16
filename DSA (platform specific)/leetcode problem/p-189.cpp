// rotate array 
//TLE
#include<iostream>
using namespace std;
int main()
{
// hum phle ek ek element shift rk rhe hai , 
  // fir last vale element ko first position pe la rhe hai 
    int nums[7]={1,2,3,4,5,6,7};
    int n=7;
    int k = 3;
    k = k % n;
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