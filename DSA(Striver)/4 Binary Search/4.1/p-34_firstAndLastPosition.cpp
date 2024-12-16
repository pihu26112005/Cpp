

class Solution {
public:
    int indexfirst(vector<int> arr , int n , int key)
{
  int start = 0 , end = n-1;
  int ans = -1 ;
  int mid = start + ((end - start)/2);
  while (start <= end )
  {
    if (key > arr[mid])
    {
        start = mid + 1;
    }
    else if (key < arr[mid])
    {
        end = mid - 1 ;
    }
    else 
    {
        ans = mid;
        end = mid-1;
    }
    mid = start + ((end - start)/2);

  }
  return ans ;
}

int indexlast(vector<int> arr , int n , int key)
{
  int start = 0 , end = n-1;
  int ans = -1 ;
  int mid = start + ((end - start)/2);
  while (start <= end )
  {
    if (key > arr[mid])
    {
        start = mid + 1;
    }
    else if (key < arr[mid])
    {
        end = mid - 1 ;
    }
    else 
    {
        ans = mid;
       start = mid+1;
    }
     mid = start + (end-start)/2;
  }
  return ans ;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(indexfirst(nums,nums.size(),target));
        ans.push_back(indexlast(nums,nums.size(),target));

        return ans;
    }
};

