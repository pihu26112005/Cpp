// 2 pointer approach .
#include<iostream>
#include<math.h>
using  namespace std ;
int main()
{
//CONCEPT-phle sare 0 shuru me lgado , fir sare 2 last me lgado , 1 apne aap hi lag jayenge ..

int arr[8]={1,2,0,1,2,2,1,0};
int n=8;
int right = 0 , left = n-1;
bool firstiter = true;

//jab tk chalo start se jb tk 0 na aajaye , jaise hi 0 aaye 1st position se swap krdo 
  //fir age chalo , jb bhi 0 mile 2nd position se swap
while (firstiter)
{
   int i=right;
   while (arr[i]!=0 && i<=n-1)
   {
      i++;
   }
   if(i<=n-1)
   {
      swap(arr[right],arr[i]);
      right++;
   }
   else
   {
      firstiter = false;
   }
}

//jab tk chalo last se jb tk 2 na aajaye , jaise hi 2 aaye last position se swap krdo 
  //fir age chalo , jb bhi 2 mile 2nd last position se swap
bool secoenditer = true;
while (secoenditer)
{
   int j=left;
   while (arr[j]!=2 && j>=0)
   {
      j--;
   }
   if(j>=0)
   {
      swap(arr[left],arr[j]);
      left--;
   }
   else
   {
      secoenditer = false;
   }
}
for (int i = 0; i < n; i++) //printing
{
   cout<<arr[i]<<" ";
}
cout<<endl;
    
}
