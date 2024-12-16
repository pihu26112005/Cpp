// tc: O(logn)
// sc: O(logn) due to recursion stack
// but we will reduce sc to O(1) 

// question --> you have to find peak element, array is sorted but except for peak elements            
                    // peak elements ke age vala bada honacahiye but vo chota hai usse 
                    // aur maine samgha ki array sorted nhi hai 

class Solution {
public:

    int solve(int s,int e,vector<int> arr,int n)
    {
        if (s > e) {
            return -1;
        }

        int m=s+(e-s)/2;
        if(m-1>=0 && m+1<n && arr[m]>arr[m-1] && arr[m]>arr[m+1])
            return m;
        if(m-1<0 && m+1<n && arr[m]>arr[m+1])
            return m;
        if(m-1>=0 && m+1>=n && arr[m]>arr[m-1])
            return m;

        int ans = -1;
        ans = solve(s,m-1,arr,n);
        if(ans!=-1)
            return ans;
        ans = solve(m+1,e,arr,n);
        if(ans!=-1)
            return ans;

        return -1;
    }

    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int s=0;
        int e=n-1;
        int m=s+(e-s)/2;

        if(n==1)
            return 0;
        
        return solve(s,e,arr,n);
        
    }
};