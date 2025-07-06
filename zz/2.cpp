#include <bits/stdc++.h>
using namespace std;

class UnionGroups {
    vector<int> leader, height;

public:
    UnionGroups(int size) {
        leader.resize(size);
        height.assign(size, 0);
        iota(leader.begin(), leader.end(), 0);
    }

    int getGroup(int node) {
        if (leader[node] != node)
            leader[node] = getGroup(leader[node]);
        return leader[node];
    }

    void connect(int u, int v) {
        int rootU = getGroup(u);
        int rootV = getGroup(v);
        if (rootU == rootV) return;

        if (height[rootU] < height[rootV])
            swap(rootU, rootV);

        leader[rootV] = rootU;
        if (height[rootU] == height[rootV])
            height[rootU]++;
    }

    vector<vector<int>> extractComponents(int size) {
        vector<vector<int>> groupings(size);
        for (int i = 0; i < size; ++i) {
            int root = getGroup(i);
            groupings[root].push_back(i);
        }
        return groupings;
    }
};

long long evaluateComponentContribution(const vector<int> &indices, const vector<int> &arr) {
    vector<int> elements;
    int oddPos = 0;

    for (int idx : indices) {
        elements.push_back(arr[idx]);
        if ((idx + 1) % 2 != 0) oddPos++;
    }

    sort(elements.begin(), elements.end());
    int evenPos = elements.size() - oddPos;

    long long sumEven = 0, sumOdd = 0;
    for (int i = 0; i < evenPos; ++i)
        sumEven += elements[i];
    for (int i = elements.size() - oddPos; i < elements.size(); ++i)
        sumOdd += elements[i];

    return sumOdd - sumEven;
}

long long processProblem(int n, const vector<int> &arr, int m, const vector<pair<int, int>> &connections) {
    UnionGroups uf(n);

    for (auto &[u, v] : connections)
        uf.connect(u - 1, v - 1); // convert to 0-based

    auto components = uf.extractComponents(n);

    long long total = 0;
    for (const auto &group : components) {
        if (!group.empty()) {
            total += evaluateComponentContribution(group, arr);
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;
        vector<int> data(n);
        for (int &x : data)
            cin >> x;

        int m;
        cin >> m;
        vector<pair<int, int>> links(m);
        for (auto &[a, b] : links)
            cin >> a >> b;

        cout << processProblem(n, data, m, links) << '\n';
    }

    return 0;
}
