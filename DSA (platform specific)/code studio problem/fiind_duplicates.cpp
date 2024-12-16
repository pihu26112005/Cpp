// it only calukate which element is twice in the array 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int arr[4];
    for (int i=0 ; i<4 ; i++)
    {
        int n ; 
        cin>>n;
        arr[i]=n;
    
    }
        
    for (int i=0 ; i<4 ; i++)
    {
        for (int j = i+1 ; j<4 ; j++)
        {
            if( ( arr[i]^arr[j] ) == 0)
            {
               cout<<arr[i];
            }
            
        }
        
    }
}