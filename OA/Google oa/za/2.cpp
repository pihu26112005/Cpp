#include <bits/stdc++.h>
using namespace std;

long long solve(int N, vector<int> A, int M, vector<vector<int>> B)
{
    vector<int> p(N), rnk(N);
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
        rnk[i] = 0;
    }
    function<int(int)> find = &
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    };
    for (int i = 0; i < M; i++)
    {
        int u = B[i][0] - 1, v = B[i][1] - 1;
        int a = find(u), b = find(v);
        if (a != b)
        {
            if (rnk[a] < rnk[b])
                swap(a, b);
            p[b] = a;
            if (rnk[a] == rnk[b])
                rnk[a]++;
        }
    }
    vector<vector<int>> comps(N);
    for (int i = 0; i < N; i++)
    {
        comps[find(i)].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (comps[i].empty())
            continue;
        int sz = comps[i].size();
        vector<long long> vals(sz);
        int posCount = 0;
        for (int j = 0; j < sz; j++)
        {
            int idx = comps[i][j];
            vals[j] = A[idx];
            if ((idx + 1) % 2 == 1)
                posCount++;
        }
        sort(vals.begin(), vals.end());
        int negCount = sz - posCount;
        long long sumSmall = 0, sumLarge = 0;
        for (int j = 0; j < negCount; j++)
            sumSmall += vals[j];
        for (int j = sz - posCount; j < sz; j++)
            sumLarge += vals[j];
        ans += sumLarge - sumSmall;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }
        int M;
        cin >> M;
        vector<vector<int>> B(M, vector<int>(2));
        for (int i_B = 0; i_B < M; i_B++)
        {
            for (int j_B = 0; j_B < 2; j_B++)
            {
                cin >> B[i_B][j_B];
            }
        }
        long long out_ = solve(N, A, M, B);
        cout << out_ << "\n";
    }
    return 0;
}
