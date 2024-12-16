// Check if Array Is Sorted and Rotated in non decreasing order
  // ya toh simple sort ho ya fir rotate krke sort ho jae toh - true 
#include<iostream>
using namespace std;
int main()
{

//rotated ya rotated sorted array me (increasing order vali ) ek pair atta hai when arr[i+1]<arr[i]
  // aur if arrray constant hai toh 0 pair aata hai
    int nums[3]={1,3,2};
    int n=3;
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
    if (count<=1) 
    {
        cout<<"true"<<endl;
    }
    else 
    {
        cout<<"false"<<endl;
    }
}