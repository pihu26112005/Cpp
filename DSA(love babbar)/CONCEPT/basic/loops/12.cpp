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
        while (j<(n-i))
        {
             cout<<" ";
             j=j+1;
        }

        int k=0;
        while (k<=i)
        {
             cout<<(k+1);
             k=k+1;
        }

        int l=i;
        while (l>0)
        {
             cout<<(l);
             l=l-1;
        }
        cout<<endl;
       
        i=i+1;
    }

}