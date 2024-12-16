#include<iostream>
#include<math.h>
using  namespace std ;

int findUnique(int *arr, int size)
{
     bool first = true;
    for (int i=0 ; i<size ; i++)
    {
        for (int j=0 ; j<size ; j++)
        {
            if( (arr[i]==arr[j]) && (i != j)) 
            {
                first = false;
                break;
            }
            else
            {
                first=true;
            }
        }
        if (first == true)
        {
            cout<<arr[i];
        }
    }
    return 0;
}

int main()
{
    int arr[10];
    for (int i=0 ; i<10 ; i++)
    {
        int n ; 
        cin>>n;
        arr[i]=n;
    
    }
    

    findUnique(arr,10);
}