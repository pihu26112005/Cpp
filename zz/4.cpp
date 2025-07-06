#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int zoneIndex(int pos, int limit1, int limit2) {
    if (pos < limit1) return 1;
    if (pos < limit2) return 2;
    return 3;
}

int countSwaps(const vector<vector<int>>& placement) {
    int totalSwaps = 0;
    totalSwaps += min(placement[1][2], placement[2][1]);
    totalSwaps += min(placement[1][3], placement[3][1]);
    totalSwaps += min(placement[2][3], placement[3][2]);
    totalSwaps += 2 * abs(placement[1][2] - placement[2][1]);
    return totalSwaps;
}

vector<int> processQueries(int n, vector<int> values, int q, const vector<vector<int>>& queries) {
    vector<int> freq(4, 0);
    for (int v : values) freq[v]++;

    int limit1 = freq[1];
    int limit2 = freq[1] + freq[2];

    vector<vector<int>> counter(4, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) {
        int group = zoneIndex(i, limit1, limit2);
        counter[values[i]][group]++;
    }

    vector<int> answers;

    for (const auto& query : queries) {
        int index = query[0];
        int newValue = query[1];
        int oldValue = values[index];

        if (newValue != oldValue) {
            vector<int> newFreq = freq;
            newFreq[oldValue]--;
            newFreq[newValue]++;

            int oldLimit1 = freq[1];
            int oldLimit2 = freq[1] + freq[2];
            int newLimit1 = newFreq[1];
            int newLimit2 = newFreq[1] + newFreq[2];

            set<int> changedPositions = {index};
            if (oldLimit1 != newLimit1) {
                changedPositions.insert(min(oldLimit1, newLimit1));
            }
            if (oldLimit2 != newLimit2) {
                changedPositions.insert(min(oldLimit2, newLimit2));
            }

            for (int pos : changedPositions) {
                if (pos >= n) continue;
                int val = (pos == index) ? oldValue : values[pos];
                counter[val][zoneIndex(pos, oldLimit1, oldLimit2)]--;
            }

            values[index] = newValue;
            freq = newFreq;

            for (int pos : changedPositions) {
                if (pos >= n) continue;
                counter[values[pos]][zoneIndex(pos, newLimit1, newLimit2)]++;
            }
        }

        answers.push_back(countSwaps(counter));
    }

    return answers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        vector<int> inputArray(n);
        for (int& val : inputArray) cin >> val;

        int q;
        cin >> q;

        vector<vector<int>> queries(q, vector<int>(2));
        for (int i = 0; i < q; ++i) {
            cin >> queries[i][0] >> queries[i][1];
        }

        vector<int> result = processQueries(n, inputArray, q, queries);
        for (int val : result) cout << val;
        cout << '\n';
    }

    return 0;
}
