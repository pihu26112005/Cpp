
// #include<iostream>
// #include<math.h>
// using  namespace std ;
// int main()
// {
//     int n ;
//     cin>>n;
//     int i=0;
//     int ans =0;
//     while (n!=0)
//     {  
//         int bit = 0;
//         bit = n%2;
//         ans = bit*(pow(10,i)) + ans;
//         cout<<"bit"<<bit<<" pow"<<pow(10,i)<<" ans"<<ans<<endl;
//         n=n/2;
//         i++;
//     }
//     cout<<ans;
// }



#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int n ;
    cin>>n;
    int i=0;
    int ans =0;
    while (n!=0)
    {  
        // int bit = 0;
        int bit = n&1;
        ans = bit*(pow(10,i)) + ans;
        cout<<"bit"<<bit<<" pow"<<pow(10,i)<<" ans"<<ans<<endl;
        n=n>>1;
        i++;
    }
    cout<<ans;
}