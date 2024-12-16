// EUCLID ALGORITHM : 
  // GCD(a,b)=GCD(a%b,b) if a>b 
          // or 
  // GCD(a,b)=GCD(a-b,b) if a>b

  #include<iostream>
  using namespace std;
  
  int GCD(int a , int b)
  {
    if (a==0)
    {
        return b;
    }
    if (b==0)
    {
        return a;
    }
    while (a!=b) // jab tk chlega jab tak same number na milemge 
    {
        if (a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
  }