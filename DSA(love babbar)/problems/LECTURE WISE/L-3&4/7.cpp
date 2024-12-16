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
        while (j<=i)
        {
            char ch='A'+(i+j);
             cout<<(ch);
             j=j+1;
        }
        cout <<endl;
        i=i+1;
    }

}