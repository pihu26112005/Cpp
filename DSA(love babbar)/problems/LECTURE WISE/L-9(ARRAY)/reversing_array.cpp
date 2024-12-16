#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int array[4]={2,4,7,9};
    // cout<<array<<endl;
    int reverse_array[4]={};
    for (int i=0 ; i<4 ; i++)
    {
        // cout<<array[i]<<endl;
        reverse_array[3-i]=array[i];

    }
    for (int i=0 ; i<4 ; i++)
    {
        cout<<reverse_array[i]<<endl;
        // reverse_array[3-i]==array[i];
    }
    
}