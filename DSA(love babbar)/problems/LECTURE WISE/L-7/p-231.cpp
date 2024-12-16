// power of two check krna hai 
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
// hum inter ki range me ane vali har 2 ki ppower calculate krke n se compare kr rhi hai 
  int n;
  cin>>n;

  int ans = 1 ;
  for (int i = 0; i <= 30; i++) // integer range --> [-2^31 , 2^31-1]
  {
    if (n==ans)
    {
      cout<<"yes";
    }
    if (ans<INT32_MAX/2)
    {
      ans = ans*2;
    }
  }

// bit manupulations se 
  // if (n & (n-1)) == 0 hia tbhi n 2  ki power ho skta hai 
     // jaise 4,3 - 100,011 ka & --> 000 
}