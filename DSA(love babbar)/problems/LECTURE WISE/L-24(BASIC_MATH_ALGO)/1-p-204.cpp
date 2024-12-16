// count primes  - p-204

// NORMOL SOLUTION - 2 for loop ka use krke 

// OPTIMIZED SOLUTION  - SEIVE OF ERATOSTHENES 

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n]={0};
    int count=0;
    for (int i = 2; i < n; i++)
    {
        if (arr[i]==0)
        {
            count++;
            for (int j = 2*i; j < n; j=j+i)
            {
                arr[j]=1;
            }
        }
    }
    cout<<count<<endl;
}




// TIME COMPLEXITY - 
  // O( n/2 + n/3 + n/5 + n/7 + ....)
  // O(n(the sum of this harmonic progression using taylor series))
  // O(nlog(log(n)))