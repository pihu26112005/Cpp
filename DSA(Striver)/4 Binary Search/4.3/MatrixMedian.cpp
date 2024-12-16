// concept --> mdedian ke left and right side me total elements barabar hote hai
// s = lowest element , e = largest element 
// mid median hai ya nhi --> by checking no. of smaller elements 

#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>

int countsmall(vector<vector<int>> &arr, int n, int m, int mid)
{

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        cnt += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        // upper bound iterator pointer deta hai , jo ki us element ko point krega which is the first element strictly greater than mid;
    }

    return cnt;
}

int median(vector<vector<int>> &arr, int n, int m)
{

    int low = INT_MIN;

    int high = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        low = min(arr[i][0], low);

        high = max(arr[i][m - 1], high);
    }

    int req = (n * m) / 2;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        int small = countsmall(arr, n, m, mid);

        if (small <= req)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return low;
}