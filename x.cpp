#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int h(int &n, vector<int> &A, int i, int p, int s){
    if(i>=n) return 1;

    // include 
    int include = 0;
    int currParity = A[i] % 2;
    if(p==-1){
        include = h(n, A, i+1, currParity, s+1)% MOD;
    }
    else if(currParity == p && s < 2){
        include = h(n, A, i+1, currParity, s+1)% MOD;
    }
    else if(currParity != p){
        include = h(n, A, i+1, currParity, 1)% MOD;
    }
    // else we cant include this element

    // exclude
    int exclude = h(n, A, i+1, p, s);

    return (include + exclude) % MOD;
}

int solve(int n, vector<int> A) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    return h(n, A, 0, -1, 0)-1; // -1 to exclude the empty subsequence
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cout << solve(n, a) << "\n";
    }
    return 0;
}