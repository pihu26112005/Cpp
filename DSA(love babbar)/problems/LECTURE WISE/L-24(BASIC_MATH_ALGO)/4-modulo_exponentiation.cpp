// FAST EXPONENTIATION ALGORITHM : 
   // a^n = (a^(n/2))^2  - a ki power n/2 ka square : if n = even 
   // a^n = ((a^(n/2))^2)*a  - a ki multiply a ki power n/2 ka square se : if n = odd

// explanation - 'n' times 'a' ko khud se multiply krne se acha hai ki , 
               // har baar 'a*a' ko hi khud se multiply kra do aur 'n/2' kr do jab tak 'n' 0 na ho 

#include<iostream>
using namespace std;
int power (int a, int n)
{
    int res = 1;
    while (n>0)
    {
        if (n&1) // for odd
        {
            res = res*a; // odd nhi hoga toh end me bas 1 se multiply ho jayega , vrna toh a se hona hi hai 
        }
        a=a*a;
        n>>1;
    }
    return res;
} 

int main()
{
    int x = power(2,5);
    cout<<x<<endl;
}


// I THINK : TIME COMPLEXITY - O(LOG(n)to the base 2)