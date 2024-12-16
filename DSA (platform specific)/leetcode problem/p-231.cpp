// power of two check krna hai 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int n;
    cin>>n;
    int i=0;
    while (n!=1)
    {
       int rem = n%2;
       if ((rem != 0) || (n==0))
       {
        i=0;
        cout<<"false";
        break;
       }
       else
       {
        n=n/2;
        i++;
       }
    }
    if(i!=0 || n==1)
    {
      cout<<"true";
    }
}