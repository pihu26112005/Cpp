// reversing the number : ex - 231 ke 132
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int x;
    cin>>  x ;
      int i=0;
      int num=0;
    while (x!=0)
    {
        if (x<pow(-2,31)  |  x>pow(2,31)+1 )
        {
            return 0;
        }
            
        else
        {
            int dig = x%10;
            if (num<(pow(-2,31)/10)  |  num>((pow(2,31)+1)/10) )
                return 0;
            else
                num = (10*num) + dig;
                x=x/10;
                i++;
        }
    }
    cout<<num;
    
}