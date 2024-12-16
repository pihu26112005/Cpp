// count ways to reach nth steps 

// f(n)=kitne tarike honge nth step pe pahunchne ke (we are allowed to move 1 step or 2 step one time)
// base case - f(1)=1 , f(2)=2
//recursive relation - f(n) = f(n-1) + f(n-2)
                     // (why not added f(n-3) in recursive relation : since n-3th step se nth step pe direct 1 ya 2 step senhi pahunch skte )


#include<iostream>
using namespace std;
int count_ways(int n)
{
    if (n==1)
        return 1;
    if (n==2)
        return 2;

    return count_ways(n-1) + count_ways(n-2);
}

int climbingStaairs(int n, int i)
{
    if(i==n)
       return 1;
    if(i>n)
       return 0;
    
    return climbingStaairs(n,i+1)+climbingStaairs(n,i+2) ;
}

int main()
{
    int n;
    cin>>n;
    cout<<"no. of ways : "<<count_ways(n)<<endl;
}