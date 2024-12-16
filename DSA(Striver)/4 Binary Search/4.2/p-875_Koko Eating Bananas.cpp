class Solution {
public:
//     bool issolution(vector<int> arr, int book, int student, int m)       // TLE
// {
//     int pages = 0;
//     int student_count =0;
//     int i=0;
//     while(i<book)
//     {
//         if (arr[i] <= m)
//         {
//             student_count++;
//             i++;
//             if (student_count > student)
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             student_count++;
//             arr[i]=arr[i]-m;
//             if (student_count > student)
//             {
//                 return false;
//             }
//             pages = arr[i];
//         }
//         if(student_count > student)
//         {
//             return false;
//         }
//     }
//     cout<<endl;
//     return true;
// }


    // hum ek arr[i] ko letsay 4 baar me devide krte, toh upar hum 4 baar while loop chalate, but niche vo ek step me ho rha hai 
    int issolution(vector<int>& piles,int n, int h,int mid){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            if(ans > INT_MAX - (piles[i]/mid))
                return false;
            ans+=(piles[i]/mid);
            if(piles[i]%mid!=0){
                ans++;
            }
        }
        return ans<=h;
    }

int bookallocate(vector<int> arr, int n, int m) {
    // return -1;
    int s=1;
    int sum=0;
    sort(arr.begin(),arr.end());
    // for (int i = 0; i < n; i++)
    // {
    //     sum = sum + arr[i];
    // }
    int e = arr[n-1];
    int ans = -1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        // if(m>n)
        // {
        //     return ans;
        // }
        if (issolution( arr,n,m, mid ))
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
    int minEatingSpeed(vector<int>& arr, int h) {
            int a=bookallocate(arr,arr.size(),h);
            return a;
    }
};