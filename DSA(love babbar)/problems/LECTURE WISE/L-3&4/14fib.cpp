#include<iostream>
using  namespace std ;
int main()
{
cout<<"hi"<<endl;
int a=0,b=1;
int n;
cin>> n;
cout << endl;
cout<<a<<endl;
cout<<b<<endl;
for (int i=0;i<n;i++)
{
   int j=a+b;
    cout<<j<<endl;
    a=b;
    b=j;

}

}