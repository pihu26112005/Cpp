#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> arr , int index , int sum , int &count )
    {
        if(sum==0)
        {
            count++;
        }
        if(index>=arr.size())
        {
            return ;
        }
        
        // exclude 
        solve(arr,index+1,sum,count);
        
        // include
        sum = sum + arr[index];
        solve(arr,index+1,sum,count);
        
        return ;
    }


int main()
{
    vector<int> arr = {0,0,5,5,0,0};
    int count =0 , sum=0 ;
    solve(arr,0,sum,count);
    cout<<count;
}