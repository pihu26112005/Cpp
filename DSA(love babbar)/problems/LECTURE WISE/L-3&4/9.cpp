#include<iostream>
using  namespace std ;
int main()
{
    int n;
    cin >> n;
    int i=0;
    while (i<n)
    {
        int j=0;
        while (j<(n-i-1))
        {
             cout<<" ";
             j=j+1;
        }

        int k=0;
        while (k<i+1)
        {
             cout<<"*";
             k=k+1;
        }
        cout<<endl;
       
        i=i+1;
    }

}