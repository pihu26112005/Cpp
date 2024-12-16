// basically numbers of 1 = no. of counter set bit 

#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
int a;
cout<<"enter value";
cin>>a;
int i=0;
// last vali digit check kr rhe hai ki vo 1 hai ya nhi , agar 1 hai toh i++ kr dete hai
while (a!=0)
{
    int b=a&1;
    if(b==1)
    {
        i++;
    }
    a=a/2;
}
cout<<i;

}