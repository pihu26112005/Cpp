// each element compared to previous elements strating from end to first 

#include<iostream>
using  namespace std ;
int main()
{
    int arr[6]={1,5,3,0,9,2};
    for (int i = 1; i < 6; i++)
    {
        int temp = arr[i];
        int j =i-1;
        for ( ; j>=0 ; j--)
        {
            if (arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
        for (int i = 0; i < 6; i++) // for printing array
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}