#include <iostream>
#include <vector> // Include the vector header file
using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> arr; // Now this will work
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             arr.push_back(x);
//         }

//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int t = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 t += arr[i] ^ arr[j];
//             }
//             ans = max(ans, t);
//         }
//         cout << ans << endl;
//     }
// }



// For each bit position j (from 0 to 29):
// Let cnt[j] = number of elements in arr that have the j-th bit set.
// For a fixed a_k, the number of XORs that will have the j-th bit set is:
// cnt[j] if bit j in a_k is 0
// n - cnt[j] if bit j in a_k is 1
// So: Contribution at bit j for a_k =
// 2^𝑗 × (cnt or n-cnt)

// Time Complexity:
// Counting bits: O(n × 30)

// Processing each a_k: O(n × 30)
// Total: O(n × log(max(a[i]))), which is extremely efficient.


#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    int arr[n+1];
    vector<int> cnt(30, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        for (int j = 0; j < 30; j++) {
            cnt[j] += ((arr[i] >> j) & 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tot = 0;
        for (int j = 0; j < 30; j++) {
            bool f = ((arr[i] >> j) & 1);
            if (f) tot += (1 << j) * (n - cnt[j]);
            else tot += (1 << j) * cnt[j];
        }
        ans = max(ans, tot);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}