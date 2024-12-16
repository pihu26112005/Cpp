//// copy 


class Solution {
public:
    bool issolution(vector<int> arr, int book, int k, int m)
{
    int pages = 0;
    int k_count =1;
    for (int i = 0; i < book; i++)
    {
        if (pages + arr[i] <= m)
        {
            pages = pages + arr[i];
        }
        else
        {
            k_count++;
            if ((k_count > k) || (arr[i] > m))
            {
                return false;
            }
            pages = arr[i];
        }
        if(k_count > k)
        {
            return false;
        }
    }
    return true;
}

    int splitArray(vector<int>& arr, int k) {
    int n = arr.size();
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        if(k>n)
        {
            return ans;
        }
        if (issolution( arr,n,k, mid ))
        {
            ans = mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans ;
    }
};