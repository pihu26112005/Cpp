// rat in a maze problem 
// all possible solution end tk pahunchne ke 
// sirf age hi bd skte hai 

#include<iostream>
using namespace std;

void possible_ways(int arr[4][4], int i, int j, int& possible_path)
{
    int rows = 4;
    int columns = 4;

    if (arr[0][0]==0 || arr[rows-1][columns-1]==0)
    {
        return ;
    }
    

    if (i == rows - 1 && j == columns - 1) // base case
    {
        possible_path++;
        return;
    }
    if (i < rows - 1 && arr[i + 1][j] == 1)
    {
        possible_ways(arr, i + 1, j, possible_path);
    }
    if (j < columns - 1 && arr[i][j + 1] == 1)
    {
        possible_ways(arr, i, j + 1, possible_path);
    }
}

int main()
{
    int arr[4][4] = {{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    int possible_path = 0;
    possible_ways(arr, 0, 0, possible_path);
    cout << possible_path << endl;
}


// MY METHOD : 

    // if (arr[i+1][j]==1 && arr[i][j+1]==0 && (i<rows-1 || j < colummns-1))
    // {
    //     possible_ways(arr, i+1, j, possible_path);
    // }
    // if (arr[i+1][j]==0 && arr[i][j+1]==1 && (i< rows-1 ||j <  colummns-1))
    // {
    //     possible_ways(arr, i, j+1, possible_path);
    // }
    // // if (arr[i+1][j]==0 && arr[i][j+1]==0 && i<rows-1 && j < colummns-1)
    // // {
    // //     firstiter = false;
    // // }    
    // if (arr[i+1][j]==1 && arr[i][j+1]==1 && (i<rows-1 || j < colummns-1))
    // {
    //     possible_ways(arr, i+1, j, possible_path);
    //     possible_ways(arr, i, j+1, possible_path);
    // }

// WHY NOT WORKING : 
                // jab niche boundary pe check krne ayenge toh , side me toh elements honge but niche nhi honge 
                // so , koi si bhi condition if ki satisfy nhi hogi , kyooki sab me age and niche 'both' check kiye hai 
                // so kabhi bhi base case tak pahunch hi nhi payega 