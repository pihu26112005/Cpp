// https://www.interviewbit.com/problems/seats/

#define MOD 10000003  // Use integer constant

int Solution::seats(string A) {
    vector<int> pos;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] == 'x') {
            pos.push_back(i);
        }
    }

    int n = pos.size();
    if(n == 0)
        return 0;

    int m = n / 2;
    int med = pos[m];

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans + abs(pos[i] - (med - m + i))) % MOD;
    }

    return ans % MOD;
}

// pos[i]: original position of the i-th 'x'.
// med = pos[m] and m=n/2
// med - m + i: target position we want to move them to.

// Person at pos[0] → should go to med - m.
// Person at pos[1] → should go to med - m + 1.
// ...
// Person at pos[m] (the median itself) → stays at med.