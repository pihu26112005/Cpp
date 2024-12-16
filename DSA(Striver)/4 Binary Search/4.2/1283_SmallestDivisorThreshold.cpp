/// pure copy 

class Solution {
public:
    bool issol(vector<int> arr, int mid,int t)
    {
        int c=0;
        for(auto val:arr)
        {
            c+=val/mid;
            if(val%mid!=0) c++;

            if(c>t) return false;
        }
        return c<=t;
    }       
    int smallestDivisor(vector<int>& arr, int t) {
        
        int s = 1;
        int e = *max_element(begin(arr), end(arr));
        int mid = s+(e-s)/2;
        int ans = -1;

        while(s<=e)
        {
            if(issol(arr,mid,t))
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