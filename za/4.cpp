#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    int n;
    vector<int> f;
    BIT(int _n) : n(_n), f(n + 1, 0) {}
    void update(int i, int v)
    {
        for (i++; i <= n; i += i & -i)
            f[i] += v;
    }
    int query(int i) const
    {
        int s = 0;
        for (i++; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
    int range(int l, int r) const
    {
        if (l > r)
            return 0;
        return query(r) - (l ? query(l - 1) : 0);
    }
};

vector<int> solve(int N, vector<int> &A, int Q, vector<pair<int, int>> &queries)
{
    BIT b1(N), b2(N), b3(N);
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == 1)
        {
            b1.update(i, 1);
            c1++;
        }
        else if (A[i] == 2)
        {
            b2.update(i, 1);
            c2++;
        }
        else
        {
            b3.update(i, 1);
            c3++;
        }
    }

    vector<int> ans(Q);
    for (int qi = 0; qi < Q; qi++)
    {
        int idx = queries[qi].first;
        int v = queries[qi].second;
        int old = A[idx];
        if (old != v)
        {
            if (old == 1)
            {
                b1.update(idx, -1);
                c1--;
            }
            else if (old == 2)
            {
                b2.update(idx, -1);
                c2--;
            }
            else
            {
                b3.update(idx, -1);
                c3--;
            }

            if (v == 1)
            {
                b1.update(idx, 1);
                c1++;
            }
            else if (v == 2)
            {
                b2.update(idx, 1);
                c2++;
            }
            else
            {
                b3.update(idx, 1);
                c3++;
            }

            A[idx] = v;
        }
        int s1 = c1;
        int s2 = c2;
        long long x12 = b2.range(0, s1 - 1);
        long long x13 = b3.range(0, s1 - 1);
        long long x21 = b1.range(s1, s1 + s2 - 1);
        long long x23 = b3.range(s1, s1 + s2 - 1);
        long long x31 = b1.range(s1 + s2, N - 1);
        long long x32 = b2.range(s1 + s2, N - 1);
        long long D = min(x12, x21) + min(x13, x31) + min(x23, x32);
        long long M = x12 + x13 + x21 + x23 + x31 + x32;
        ans[qi] = D + 2 * ((M - 2 * D) / 3);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int Q;
        cin >> Q;
        vector<pair<int, int>> queries(Q);
        for (int i = 0; i < Q; i++)
        {
            cin >> queries[i].first >> queries[i].second;
        }

        vector<int> res = solve(N, A, Q, queries);
        for (int i = 0; i < Q; i++)
        {
            if (i)
                cout << ' ';
            cout << res[i];
        }
        cout << "\n";
    }

    return 0;
}
