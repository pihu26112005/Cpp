// move zeros 

#include<iostream>
using namespace std;
int main()
{
// check each element , if vo not zero toh age bd jao (i++) , other wise use last me pahuncha do . 
   // loop n tk nhi chalana hai kyokii last tk ate ate end me sbhi zeros aa ge honge toh vha loop infinfite ho jayega ,
      // kyoooki zero hone ke kearan i++ bhi nhi hoga , aur last me pahuch kr bhi uske jagah agla zero hi ayega 
    int arr[8]={1,0,4,2,0,3,7,0};
    int i=0;
    int n=8;
    int zero_count=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            zero_count++;
        }
    }
    while(i<n-zero_count)
    {
        if (arr[i]==0)
        {
            for ( int j=i; j < n-1; j++)
            {
                arr[j]=arr[j+1];
            }
            arr[n-1]=0;     
        }
        else
        {
            i++;
        }
        
    }
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}