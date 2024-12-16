#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int a[6]={1,2,3,4,5,2};
    int b[5]={1,4,2,8,2};
    int c[5];
    int x=0;
    for (int i = 0; i<6 ; i++)
    {
        for (int j = 0; j<5 ; j++)
        {
            if (a[i]==b[j])
            {
                c[x]=a[i];
                a[i]=0;
                b[j]=0;
                x++;
                break;

                for (int i = 0; i<6; i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<endl;
                
                for (int i = 0; i<5; i++)
                {
                    cout<<b[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    cout<<x;
    for (int i = 0; i<x; i++)
    {
        cout<<c[i]<<" ";
    } 
}