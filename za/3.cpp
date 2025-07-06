#include <bits/stdc++.h>
using namespace std;

static vector<long long> cands;
static bool cands_inited = false;

void init_cands()
{
    vector<int> odd_digits = {0, 1, 3, 5, 7, 9};
    vector<int> even_digits = {2, 4, 6, 8};
    for (int odd : odd_digits)
    {
        for (int mask = 0; mask < 16; ++mask)
        {
            int sum = 0;
            vector<pair<int, int>> cnt;
            if (odd)
            {
                sum += odd;
                cnt.emplace_back(odd, odd);
            }
            for (int i = 0; i < 4; ++i)
            {
                if (mask & (1 << i))
                {
                    int d = even_digits[i];
                    sum += d;
                    cnt.emplace_back(d, d);
                }
            }
            if (sum == 0 || sum > 18)
                continue;
            sort(cnt.begin(), cnt.end());
            string left;
            for (auto &p : cnt)
                left.append(p.second / 2, char('0' + p.first));
            string s = left;
            if (odd)
                s.push_back(char('0' + odd));
            for (int i = (int)left.size() - 1; i >= 0; --i)
                s.push_back(left[i]);
            cands.push_back(stoll(s));
        }
    }
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());
    cands_inited = true;
}

long long solve(long long N)
{
    if (!cands_inited)
        init_cands();
    auto it = upper_bound(cands.begin(), cands.end(), N);
    return it != cands.end() ? *it : -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        cout << solve(N) << '\n';
    }
    return 0;
}
