// reverse the array 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr = {1,6,22,8,0,34};
//har round me each element ko uske agle se swap kr diya , 
  //toh hr round ke baad phla element last me pahuch jayega .
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr.size()-i; j++)
    //     {
    //         swap(arr[j],arr[j+1]);
    //     }
        
    // }

// OR


//fisrt ko last se swap 
  //second ko last second se swap 
    // if (arr.size()%2==0) 
    // {
    //     for (int i = 0; i < arr.size()/2; i++)
    //     {
    //         swap(arr[i],arr[arr.size()-(i+1)]);
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < (arr.size()-1)/2; i++)
    //     {
    //         swap(arr[i],arr[arr.size()-(i+1)]);

    //     }
        
    // }

// best approach
    int s=0,e=arr.size()-1;
    while (s<=e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    
    

    for (int i = 0; i < arr.size(); i++) // printing
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}