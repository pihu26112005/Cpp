class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // 2 case possible hia 

    // ek ki sara nums2 nums1 ke age lag gaya, tab b zero ho jayega , a nhi hoga 
    // but tab koi dikkat nhi agar hum b ke zero hone pe ruk jaye, snce nums1 sorted hai 

    // and aage nums1 jake lag gaya pahle end me , toh hame bas nums2 ko start me copy krna hai 
    // means baar baar sirf else me jana hai 
       int a = m-1;
       int b = n-1;
       int c = m+n-1;
       while(b>=0) 
       {
        if( a>=0 && nums1[a]>nums2[b])
        {
            nums1[c]=nums1[a];
            a--;
            c--;
        }
        else
        {
            nums1[c]=nums2[b];
            c--;
            b--;
        }
       }
    }
};