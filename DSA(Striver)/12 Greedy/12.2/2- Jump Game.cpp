class Solution {
public:
    bool canJump(vector<int>& nums) {
    int maxIndex = 0;
    for(int i = 0; i < nums.size(); i++){
        if (i > maxIndex){
            return false;
        }
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
    }
};

// do chij maintain kro, ek max kitna jaa sakta hu and abhi vale se kitna ja sakta hu 
// nums[i] = 2 hai, toh hum 2 aur aage jaa sakte hai, 2-->1-->0 then jab vo -1 hoga , toh rukna hai usek age nhi ja payenge 
// but agar max jyada hai nums[i] se, toh hum aur aage ja sakte hai but nums[i] hi nhi le jaa paa rha toh kuch nhi kr sakte 