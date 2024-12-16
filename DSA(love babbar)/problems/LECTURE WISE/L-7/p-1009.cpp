// compliment of base 10 : 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
// help bit bnae hai , fir n ke compliment ka uske sath and kr diya 
    int n;
    cin>>n;

    int temp = n;
    int help=0;
    if(n==0)
    {
        cout<<1<<endl;
    }
    while (temp!=0)
    {
        help = help<<1;
        help=help|1;
        temp = temp>>1;
    }
    int ans = ((~n)& help);
    
    cout<<ans;

}