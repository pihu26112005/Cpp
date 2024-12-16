// # variables 2 type ke ho skte hai 
//           1. global variables 
//           2. each block ke pakne khud ke variables 
// precedence power : each block > global 


#include<iostream>
using  namespace std ;
int main()
{
 int i=0;
 cout<<i<<endl;

 if(1)
 {
   int i =1;
   cout<<i<<endl;

 }

 for (int i=2;i<3;i++)
 {
    cout<<i<<endl;

 }

 for (;i<1;i++)
  cout<<i<<endl;


}