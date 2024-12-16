#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is "<< ans << endl;

//case 1
    while(true) {
        int i = 5;
    }
    // har baar 'i' loop ke sath hi delet hota hai (kooki static hai : stack)
    // fir loop begin ke sath new create ho jata hai 
    
//case 2
    while(true) {
        int* ptr = new int;
    }
    // yha 'i' har baar delet nhi hota khud kyyooki dynamic hai : heap 
    // isliye infinite memory lag rhi hai

    return 0;
}