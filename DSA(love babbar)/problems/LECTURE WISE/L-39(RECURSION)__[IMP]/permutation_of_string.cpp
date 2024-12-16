// permutation of string 

#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;

void sort(vector<string>& random)
{
    int n = random.size();
    bool firstiter = true;
    for (int i = 1; i < n; i++) // for (n-1) rounds chalane ke liye
    {
        firstiter = true;
        for (int j = 0; j < n-i; j++)  // us round ke hr element apas me bubble sort hote hai 
        {
        int x=0;
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

void permutation_calc(vector<string>& ans, vector<string> arr, string output, int index, int size)
{
    if (index>=arr.size()) // base case // index abc,bca,cab ke liye chal rha hai
    {
        ans.push_back(output);
        return ;
    }
    
    string x;
    x = arr[index]; // arr me abc,bca,cab hai 

    for (int i = 0; i < size; i++)  // i abc me a,b,c ke liye chal rha hai
    {
        bool firstiter = true;
        for (char j : output) // each combination ex - abc me same toh nhi hai ye chcek kr rha hai
        {
            if (j==x[i])
            {
                firstiter = false;
            }
        }
        if (firstiter)
        {
            output.push_back(x[i]);
            permutation_calc(ans, arr, output, index+1, size);
            output.pop_back();
        }
    }
    // sort(ans.begin(),ans.end());
    sort(ans);
}

int main()
{
    string s = "xyz";
    vector<string> arr;

    for (int j = 0; j < s.length(); j++)
    {
        arr.push_back(s);
        char temp = s[0];
        for (int i= 0; i+1 < s.length(); i++)
        {
            s[i]=s[i+1];
        }
        s[s.length()-1]=temp;
    }

    vector<string> ans; // variables
    string output;
    int index =0;
    int size = s.length();

    permutation_calc(ans, arr, output, index, size);

    for(string j : ans)// prinintg answer
    {
        cout<<j<<" ";
    }
}