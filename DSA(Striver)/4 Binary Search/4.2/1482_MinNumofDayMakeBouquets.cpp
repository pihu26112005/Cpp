#include <algorithm> // for std::max_element  
#include <vector>
class Solution {
public:
    bool issol(vector<int> arr, int mid,int m, int k)
    {
        int day = 0, cnt = 0;
        for(auto val:arr)
        {
            if(val <= mid) cnt++;
            else cnt = 0;
            if(cnt == k) cnt = 0, day++;
        }
        return day >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        if ((long long)m * k > arr.size()) {    // aise likhne e tle nhi de rha tha
            return -1;
        }
        
        int s = 1;
        int e = *max_element(begin(arr), end(arr));
        int mid = s+(e-s)/2;
        int ans = -1;

        while(s<=e)
        {
            if(issol(arr,mid,m,k))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};