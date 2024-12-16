#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(vector<int> baselow , vector<int> baseupper)
{
    if(baseupper[0]<=baselow[0] && baseupper[0]<=baselow[0] && baseupper[0]<=baselow[0])
        return true;
    return false;
}

int solve3(int n , vector<vector<int>> arr )  
{
    vector<int> next(n+1,0);
    vector<int> current(n+1,0);
    for (int curr = n-1 ; curr >=0; curr--)
    { 
        for (int prev = curr-1; prev >=-1; prev--)
        {
            int exclude = next[prev+1];
            int include;
            if(prev==-1 || comp(arr[curr],arr[prev]))
                include = arr[curr][2] + next[curr+1]; // arr[curr][2]--> height of new cuboid jo prev ke upar rkh rhe hai 
            else
                include = next[prev+1];
            
            current[prev+1]= max(include,exclude);
        }
        next = current;
    }
    return current[0];
}

int maxHeight(vector<vector<int>> cuboids)
{
    // sort all dimesnsion of each cuboid 
    for(auto &a:cuboids)
    {
        sort(a.begin(),a.end());
    }

    // sort all cuboids on basis of 1st element (l or w)
    sort(cuboids.begin(),cuboids.end());

    return solve3(cuboids.size() , cuboids);
}