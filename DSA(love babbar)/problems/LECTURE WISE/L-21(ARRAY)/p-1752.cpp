// Check if Array Is Sorted and Rotated
  // ya toh simple sort ho ya fir rotate krke sort ho jae toh true 
#include<iostream>
using namespace std;
int main()
{
// normol concept - array check krte hai ki sorted hai ya nhi 
  // if not , toh 1 element se rotate krke fir sorted check krte hai 
     // fir repeat krte hai for all element one by one 

// legenedary concept - mountain array kuch sochte hai 
    int nums[5]={3,4,5,1,2};
    int n=5;
    int i=0;
    while (i+1<n)
    {
        if (nums[i+1]>=nums[i])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    if (i+1==n)
    {
       cout<<"true"<<endl;
    }
    else
    {
        while (i+1<n)
        {
            i++;
            if ((nums[i+1]>=nums[i])&(nums[i]<=nums[0])&(nums[i+1]<=nums[0]))
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if (i+1==n)
        {
           cout<<"true"<<endl;
        }
    }
}