#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int solve(int N, vector<int> A) {
    long long dp0 = 1, dp1 = 0, dp2 = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] % 2 == 0) {
            long long sum = (dp0 + dp1 + dp2) % MOD;
            dp0 = (dp0 + sum) % MOD;
        } else {
            long long old_dp1 = dp1;
            dp1 = (dp1 + dp0) % MOD;
            dp2 = (dp2 + old_dp1) % MOD;
        }
    }
    long long res = (dp0 + dp1 + dp2 - 1 + MOD) % MOD;
    return (int)res;
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