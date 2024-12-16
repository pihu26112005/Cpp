// Check if Array Is Sorted and Rotated in non decreasing order
  // ya toh simple sort ho ya fir rotate krke sort ho jae toh - true 
     // MINE 
#include<iostream>
using namespace std;
int main()
{
// normol concept - array check krte hai ki sorted hai ya nhi 
  // if not , toh 1 element se rotate krke fir sorted check krte hai 
     // fir repeat krte hai for all element one by one 

// legenedary concept - mountain array kuch sochte hai 
    int nums[3]={6,10,6};
    int n=3;
    int i=0;
    bool firstiter = true;
    while (i+1<n)
    {
        if (nums[i+1]>=nums[i])
        {
            i++;
            firstiter = true;
        }
        else
        {
            firstiter = false;
            break;
        }
    }
    if (firstiter == true) // simple sorted array ka case 
    {
       cout<<"true"<<endl;
    }
    else
    {
        if(nums[i+1]<=nums[0]) //nums[i+1],nums[i] se toh chota hi hoga , tbhi else me aaya 
        {
            firstiter = true;
            i++;
            while (i+1<n) // checking for mountain array case
            {
                if ((nums[i+1]>=nums[i])&(nums[i]<=nums[0])&(nums[i+1]<=nums[0]))
                {
                    i++;
                    firstiter = true;
                }
                else
                {
                    firstiter = false;
                    break;
                }
            }
        }
    }
    if (firstiter == true) // mountain array ka case
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}