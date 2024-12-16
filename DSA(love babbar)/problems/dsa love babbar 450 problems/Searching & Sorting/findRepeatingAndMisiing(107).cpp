#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> findRepeatingAndMissingNumbers(vector<int> nums)

{   int n=nums.size();

    sort(nums.begin(),nums.end());

    vector<int> vc;

    for(int i=0;i<nums.size();i++){

        if(nums[i]==nums[i-1]){

            vc.push_back(nums[i]);

            nums.erase(nums.begin()+i);break;

        }

    }

    int sum1=0;
    int sum2=0;
    for(int i=0;i<nums.size();i++){

            sum1 = sum1+nums[i];

    }
    for(int i=1;i<=n;i++){

            sum2 = sum2+i;

    }

    // sum2 = (n*(n-1))/2;
    vc.push_back(sum2-sum1);

    return vc;

}