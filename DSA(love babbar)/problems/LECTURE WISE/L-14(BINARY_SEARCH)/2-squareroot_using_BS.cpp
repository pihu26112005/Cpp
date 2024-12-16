// finding square root using binary search 
// thoda hint lekar 


#include<iostream>
using namespace std;
int squareroot(int n)
{
    
    if (n==1)
        {
        return 1;
        }
    else 
        {
			int s=0;
    	int e=n-1;
    	int m = s + (e-s)/2;
    	long long int sq=m*m;
    	int ans =0;
        while (s<=e)
            {
                if (sq==n)
                {
                    return m;
                }
                else if (sq>n)
                {
                    e=m-1;
                }
                else if (sq<n)
                {
                    ans = m;
                    s=m+1;
                }
                m = s + (e-s)/2;
                sq=m*m;
            }
        return ans;
        }
    }

int main()
{
    int n;
    cin>>n;
    int a = squareroot(n);
    cout<<a<<endl;
}
   