// finding square root using binary search 
// made by me 
// submitted 

#include<iostream>
using namespace std;
int squareroot(int n)
{
    int s=0;
    int e=n/2;
    int m = s + (e-s)/2;
   if (n==1)
      {
         return 1;
      }
   else 
     {
      while (s<=e)
         {
            if (((m)<=n/m)&(((m+1))>n/(m+1)))
            {
            return m;
            }
            else if (((m)<n/m)&(((m+1))>=n/(m+1)))
            {
            return m+1;
            }
            else if (((m)<n/m)&(((m+1)))<n/(m+1))
            {
               s=m+1;
            }
            else
            {
            e=m;
            }
            m = s + (e-s)/2;
         }
         return 0;
     }

}
int main()
{
    int n;
    cin>>n;
    int a = squareroot(n);
    cout<<a<<endl;
}
       
