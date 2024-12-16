class Solution 
{
public:
    bool check(vector<int>& nums) 
{
//rotated ya rotated sorted array me (increasing order vali ) ek pair atta hai when arr[i+1]<arr[i]
  // aur if arrray constant hai toh 0 pair aata hai
    int n=nums.size();
    int count=0;
    for (int i = 0; i+1 < n; i++)
    {
        if (nums[i+1]<nums[i]) // rotated sorted array case (usme bich me aata hai ye pair)
        {
            count++;
        }
    }
    if (nums[0]<nums[n-1])
    {
        count++;
    }
    return count<=1;
}
};