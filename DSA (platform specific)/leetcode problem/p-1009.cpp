// compliment of base 10 : 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int n;
    cin>>n;
    int  help=0;
    if(n==0)
    {
        cout<<1<<endl;
    }
    while (n!=0)
    {
        help = help<<1;
        help=help|1;
        n = n>>1;
        // cout<<help<<endl;
    }
    int ans = ((~n)& help);
    
    cout<<ans;

}