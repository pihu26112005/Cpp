 vector<int> findPrimeFactors(int n) {

        // seive of errrrr jisse isprime(i) O(1)  me ho sakta hai 
        vector<int> arr(n+1,1);
        arr[0] = 0;
        arr[1] = 0; // 0 and 1 are not primes

        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    arr[j]=0;
                }
            }
        }
        
        
        vector<int> ans;
        for(int i=2;i<=n;i++)
        {
            if(n%i == 0)
            {
                // if(arr[i]==1)
                    // ans.push_back(i);
                while(n%i == 0)
                {
                    ans.push_back(i);
                    n = n/i;
                }
            }
        }
        return ans;
        
    }