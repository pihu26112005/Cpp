#include<iostream>
#include<vector>
using namespace std;
// pichli baar f(n)=f(n-1)+f(n-2) // f(x) = x tk phumchne ke trike
// is barr f(0) = f(1)+f(2) // f(x) = x se nth stirs jane ke tarike 

https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbDc1UDVEcWNVWEpuRS0wdkQ2MnIzcG1iNThzZ3xBQ3Jtc0trSUVqXzdCY0U0WW5IUS1GUkM1RVdzbEtBSjZpRUpMNmNCUkktdHRJcmo1NEFsX1E5THZ0SEkwbE5mTVRta2VXZ0ZCUzY1WXpOcnhCMEE4a3hTUnRIcFRHbTY2dVdPaURUUVN6TTY5bTkxcjlweUVOMA&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fproblems%2Fcount-ways-to-reach-nth-stairs_798650%3FleftPanelTab%3D0%26utm_source%3Dyoutube%26utm_medium%3Daffiliate%26utm_campaign%3DLovebabbar&v=S31W3kohFDk
https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa2xrSVJPUlkzdXE4VjAwVWU4cEhEcThjVllSZ3xBQ3Jtc0ttNWVkdm85Y0pYanZtZ21VY1dLVzFHWFV6YXo2bXZhRjlVRllqOC10ZThudVV3M1dJT25SWU9nYV9NVGlrbmFqR0wwV0djM3M4eEhFVENmZ2Rsc1J5WUh3RVBTQ2xmWkNQZDB1Y3hwLWxIbVpZMnpCdw&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fmin-cost-climbing-stairs%2F&v=S31W3kohFDk


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int minCost(vector<int> cost , int n)
{
    if(n==0)
       return cost[0];
    if(n==1)
       return cost[1];

    return (min(minCost(cost,n-1),minCost(cost,n-2))+cost[n]);
}
int main()
{
    int n;
    vector<int> cost;
    int ans = min(minCost(cost,n-1),minCost(cost,n-2));
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// approach 2 --> top down 
int minCost2(vector<int> cost ,vector<int> minC, int n)
{
    if(n==0)
       return minC[0]=cost[0];
    if(n==1)
       return minC[1]=cost[1];
    if(minC[n)!=-1)
       return minC[n];

    return minC[n]=(min(minCost2(cost,minC,n-1),minCost2(cost,minC,n-2))+cost[n]);
}
int main()
{
    int n;
    vector<int> cost;
    vector<int> minC(n,-1);
    int ans = min(minCost2(cost,minC,n-1),minCost2(cost,minC,n-2));
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// approach 3 --> bottom up
int minCost3(vector<int> cost , int n)
{
    vector<int> minC;
    minC[0]=cost[0];
    minC[1]=cost[1];

    for (int i = 2; i < n; i++)
    {
        minC[i]=(min(minC[i-1],minC[i-2])+cost[n]);
    }

    return  min(minC[n-1],minC[n-2]) ;
}
int main()
{
    int n;
    vector<int> cost;
    int ans = minCost3(cost,n);
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// approach 4 --> space optimization
int minCost3(vector<int> cost , int n)
{
    vector<int> minC;
    int prev2=cost[0];
    int prev=cost[1];
    int curr;

    for (int i = 2; i < n; i++)
    {
        curr=(min(prev,prev2)+cost[n]);
        prev2 = prev;
        prev = curr;
    }

    return  min(prev,prev2) ;
}
int main()
{
    int n;
    vector<int> cost;
    int ans = minCost3(cost,n);
}