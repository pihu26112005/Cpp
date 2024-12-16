
#include<iostream>
#include<math.h>
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

double square_float(int n,long double s)
{
    for (int i = 1; i < 10 ; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            long double dec = (j/pow(10,i));
            long double dec2 = ((j+1)/pow(10,i));
            
            // cout<<"dec "<<dec<<endl;
            // cout<<"dec2 "<<dec2<<endl;
            // cout<<"s+dec"<<s+dec<<endl;
            // cout<<"s+dec ka sq"<<(pow(s+dec,2))<<endl<<endl;
            if ((pow(s+dec,2)<=n) & (pow(s+dec2,2)>n))
            {
                // cout<<"if dec "<<dec<<endl;
                // cout<<"if dec2 "<<dec2<<endl;
                // cout<<"s+dec "<<s+dec<<endl<<endl;
                s=s+dec;
            }
        }
    }
    return s ;
}

int main()
{
    int n;
    cin>>n;
    float a = squareroot(n);
    cout<<a<<endl;
    float b=square_float(n,a);
    cout<<b<<endl;
}
       
