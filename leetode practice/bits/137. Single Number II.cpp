class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int result = 0;
    
            for (int i = 0; i < 32; ++i) {
                int bitSum = 0;
    
                for (int num : nums) {
                    if ((num >> i) & 1)
                        bitSum += 1;
                }
    
                if (bitSum % 3)
                    result |= (1 << i);
            }
            // ye har bit banane ka try kr rha hai 
    
            // Handle negative numbers
            if ((result >> 31) & 1)
                result -= (1LL << 32);
            
            // result me agar first bit jab banae hogi , toh agar vo 1 aa gayi hogi 
            // toh number negative hona chahiye as per cpp representation of singed integer 
            // negative number two complement ki form me represent hote hai 
            // so abhi jo 32 bits bani hai agar uski 31st bit 1 hue toh jab uska binar banayenge
            // toh vp 2^32  se bada ban jayega, representation sahi hai, but negative dorect binary me conver nhi hote pahle unko 2s complement lena hota hai fir jo number ata hai vo binary me convert hota hai 
            // isiliye isme se 2^32 minus kr diya kyokii last bit ki vajah se isme ek 2^32 extra add hua hoga vo hata diya 
    
            return result;
        }
    };
    