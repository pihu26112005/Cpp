// permutation of string 
// video solution 
// tle de rha hai 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sort(vector<string>& random)
{
    int n = random.size();
    bool firstiter = true;
    for (int i = 1; i < n; i++) // for (n-1) rounds chalane ke liye
    {
        int x=0;
        firstiter = true;
        for (int j = 0; j < n-i; j++)  // us round ke hr element apas me bubble sort hote hai 
        {
            while (random[j][x]==random[j+1][x])
            {
                x++;
            }
            
            if(random[j][x]>random[j+1][x])
            {
                swap(random[j],random[j+1]);
                firstiter = false;
            }
        }
    if (firstiter == true )
    {
        break;
    }
    }
}

void permutation_calculation(vector<string>& ans, string arr, int index) // hum arr string me hi changes kr rhe hai
{
    if (index>=arr.size()) // base case
    {
        ans.push_back(arr);
        return ;
    }
    
// index abc me a,b,c ke liye hai 
    for (int i = index; i < arr.size(); i++) // i --> a,b,c ka khud se and age valo se swap krata hai
    {
        swap(arr[index],arr[i]);
        permutation_calculation(ans, arr, index+1);
        swap(arr[index],arr[i]); // backtracking --> taaki vapas ate vaqt vapis phle vaali string ban har step pe jab return ke baad vapas ayega
    }
}

int main()
{
    string arr = "zxcvbhsy";
    vector<string> ans;
    string output;
    int index =0;
    permutation_calculation(ans, arr, index);
    // sort(ans);
    sort(ans.begin(),ans.end());


    for (string i : ans)
    {
        cout<<i<<" ";
    }

}