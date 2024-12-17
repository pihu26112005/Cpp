class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int m = nums[n-1];
        int ii = -1;
        for(int i=n-2;i>=0;i--) // ppiche se vo vala case kiya jisme agla pichle se chota hai 
        {
            // if(nums[i]<m)   
            if(nums[i]<nums[i+1])
            {
                ii = i;
                break;
            }
            m = max(m,nums[i]);
        }
        if(ii!=-1)
        {
            reverse(nums.begin()+ii+1,nums.end()) ; // reverse from ii+1 to last 

            int jg=100000000;
            int jgi = -1;
            for(int i=ii+1;i<n;i++) // just greater element dhunda 
            {
                if(nums[i]>nums[ii] && nums[i]<jg)
                    {
                        jg = nums[i];
                        jgi = i;
                    }
            }
            // for(int i=jgi;i>=ii+1;i--) // jg element tak sabko ek ek age shift kr diya 
            // {
            //     nums[i]=nums[i-1];
            // }
            // nums[ii]=jg; // jg ko us start me jo mila tha uski jagah rakh diya 
            int temp = nums[ii] ; // just greater and usko jo start me mila tha, replace kr diya ek dusre se 
            nums[ii] = nums[jgi] ;
            nums[jgi] = temp ;
        }
        else // jab akhir purmuatation ho, decreasing order me ho array 
        {
            int j=0;
            int k=n-1;
            while(j<k) // is case me reverse krna hia 
            {
                int t = nums[j];
                nums[j]=nums[k];
                nums[k]=t;
                j++;
                k--;
            }
        }
    }
};

// 16385 784