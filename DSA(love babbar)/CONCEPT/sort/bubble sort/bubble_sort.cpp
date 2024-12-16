#include<iostream>
using  namespace std ;
int main()
{
    int arr[5]={8,5,9,4,2};
    int n = 5;
    bool firstiter = true;
    for (int i = 1; i < n; i++) // for (n-1) rounds chalane ke liye
    {
        firstiter = true;
        for (int j = 0; j < n-i; j++)  // us round ke hr element apas me bubble sort hote hai 
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                firstiter = false;
            }
        }
        
    if (firstiter == true )
    {
        break;
    }
    }
}