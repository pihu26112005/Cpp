// 2 pointers approach  ; chala nhi yha pta nhi kyo 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int a[6]={1,2,3,4,5,2};
    int b[5]={1,4,2,8,2};
    int c[5];
    int x=0,i=0,j=0;
    while (i<6 && j<5)
    {
        if (a[i]==b[j])
        {
            c[x]=a[i];
            x++;
        }
        else if (a[i]>b[j])
        {
            j++;
        }
        else if (a[i]<b[j])
        {
            i++;
        }
    }
    cout<<x;
    for (int i = 0; i<x; i++)
    {
        cout<<c[i]<<" ";
    } 

}