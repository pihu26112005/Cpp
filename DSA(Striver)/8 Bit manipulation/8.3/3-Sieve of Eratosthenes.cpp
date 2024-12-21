class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;

        vector<int> arr(n,1);
        arr[0] = 0;
        arr[1] = 0; // 0 and 1 are not primes

        for(int i=2;i*i<n;i++)
        {
            if(arr[i]==1)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    arr[j]=0;
                }
            }
        }
        int ans=0;
        for(int i:arr)
        {
            if(i==1)
                ans++;
        }
        return ans;
    }
};