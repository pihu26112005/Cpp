// no of occurence dekher 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int arr[5];
    for (int i=0 ; i<5 ; i++)
    {
        cout<<"enter the value "<< i <<endl ;
        int n ; 
        cin>>n;
        arr[i]=n;
    }

    int occurence[5];
    for (int i = 0; i < 5; i++)
    {
    occurence[i] = 1;
    }

    bool firstiter = false;

    for (int i=0 ; i<5 ; i++)
    {
        for (int j=0 ; j<i ; j++)
        {
            if ( ( arr[i]==arr[j] ) && ( i != 0) )
            {
                firstiter = false ;
                break;
            }
            else
            {
               firstiter = true;
            }
        }
        if ( firstiter == true )
        {
            int value = 1 ;
            for (int k=i+1 ; k<5 ; k++)
            {
                if (arr[i]==arr[k]) 
                {
                    value++ ;
                }
            }
            occurence[i] =  value  ;
        }

    }
    for (int i=0 ; i<5 ; i++)
    {
         cout<<occurence[i]<<" ";
    }
    
}