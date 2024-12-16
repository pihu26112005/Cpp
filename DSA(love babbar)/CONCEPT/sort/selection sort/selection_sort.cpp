#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int arr[5]={9,5,4,2,9};
    int n = 5;
    for (int i = 0; i < n-1; i++)
    {
        int least_index = i;
        for (int j = i+1; j < n-1; j++)
        {
            if((arr[j]<arr[i]) & (arr[j]<arr[least_index]))
            {
                least_index = j;
            }
        }
        swap(arr[i],arr[least_index]);
    }
}