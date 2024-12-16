#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int arr[9];
    for (int i=0 ; i<9 ; i++)
    {
        int n ; 
        cin>>n;
        arr[i]=n;
    
    }
        int j=0;
    for (int i=0 ; i<9 ; i++)
    {
        j=(arr[i]^j);
    }
    cout<<j;
}