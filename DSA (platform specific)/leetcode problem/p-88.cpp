// merge 2 sorted array

// EFFICIENT BNANA HAI , (VIDEO KA SOLUTION HI HAI DEKHA YE JO LIKHA HAI)
#include<iostream>
using namespace std;
int main()
{

// first dono array ke elements compare kiye ek ek krek aur 
  //jb tk ek array(small vali) khatam na ho jae , tb tk compare krke arr3 me dalte rho , 
     //end me jo bigger array ke elements bache hai , unko dal diya   
    int arr1[8]={1,3,5,7,9,10,13,15};
    int arr2[5]={0,2,4,6,8};
    int arr3[13]={0};
    int a=0,b=0,c=0;
    int n=8,m=5;
    while (a<n & b<m)
    {
        if (arr1[a]<arr2[b])
        {
            arr3[c]=arr1[a];
            c++;
            a++;
        }
        else
        {
            arr3[c]=arr2[b];
            c++;
            b++;
        }
    }
    while (a<n)
    {
        arr3[c]=arr1[a];
        c++;
        a++;
    }
    while (b<m)
    {
        arr3[c]=arr2[b];
        c++;
        b++;
    }

    for (int i = 0; i < 13; i++) //printing mergerd array
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}