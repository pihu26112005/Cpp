vector<long long int> twoOddNum(long long int Arr[], long long int N){
        
        // Step 1: Xor all the elements
        long xr = 0;
        for(int i=0; i<N; i++) xr = xr ^ Arr[i];
        
        // Step 2: Find the rightmost set bit
        int rightMost = (xr & xr - 1) ^ xr;
        
        // Step 3: Store elements with rightmost set bit set into b1 and 0 into b2
        long long int b1 = 0, b2 = 0;
        for(int i=0; i<N; i++){
            
            if(Arr[i] & rightMost) b1 ^= Arr[i];
            else b2 ^= Arr[i];
            
        }
        
        if(b1 > b2) return {b1, b2};
        
        return {b2, b1};
        
    }