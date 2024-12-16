#include<iostream>
#include<math.h>
using  namespace std ;

int fibnocci(int n) 
 {
    if (n==1 || n==2)
        return 1 ;

    else
       {
         return fibnocci(n-1) + fibnocci(n-2) ;
       }
 }

int main()
{
 int m;
 cin>>m;
 int a=fibnocci(m) ;
 cout<<a ;
 return 0 ;

}

