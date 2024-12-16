// 2 pointer approach .
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int array[8]={1,1,0,1,0,0,1,0};
    int right = 0 , left = 7;
while (right<left)
{
// agar shuru me 0 nhi toh age bdo , last me 1 nhi toh age bdo , jb tak shuru me 0 , last me 1 naa jaye
  // fir swap krdo
    while (array[right]==0 && right<left)
    {
        right++;
    }
    while (array[left]==1 && right<left)
    {
        left--;
    }
    swap(array[right],array[left]);
    right++;
    left--;
}

    
    for (int i = 0; i < 7; i++)
    {
        cout<<array[i]<<" ";
    }
    
}
