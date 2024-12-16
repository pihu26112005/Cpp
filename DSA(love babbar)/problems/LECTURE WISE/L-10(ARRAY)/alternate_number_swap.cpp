#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
    int array[9]={2,4,7,9,1,3,8,0,6};
    for (int i=0 ; i<9 ; i=i+2)
    {
        int k = array[i];  
        array[i]=array[i+1];
        array[i+1]=k;
        // or we can use also swap inbuilt function

    }
    for (int i=0 ; i<9 ; i++)
    {
        cout<<array[i]<<" ";
    }



}