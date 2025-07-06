#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<long long> specialPalindromes;
bool generated = false;

vector<int> oddDigits = {1, 3, 5, 7, 9};
vector<int> evenDigits = {0, 2, 4, 6, 8};

// Function to build half-palindrome from digit frequencies
string buildHalf(const vector<pair<int, int>>& digits) {
    string result;
    for (const auto& entry : digits) {
        int digit = entry.first;
        int count = entry.second / 2;
        result.append(count, '0' + digit);
    }
    return result;
}

// Generate all valid palindromes based on constraints
void generatePalindromes() {
    for (int center : oddDigits) {
        for (int mask = 0; mask < 16; ++mask) {
            vector<pair<int, int>> freq;
            int total = center;

            if (center > 0) {
                freq.emplace_back(center, center);
            }

            for (int bit = 0; bit < 4; ++bit) {
                if (mask & (1 << bit)) {
                    int evenDigit = evenDigits[bit + 1]; // skip 0
                    total += evenDigit;
                    freq.emplace_back(evenDigit, evenDigit);
                }
            }

            if (total == 0 || total > 18)
                continue;

            sort(freq.begin(), freq.end());
            string left = buildHalf(freq);
            string right = left;
            reverse(right.begin(), right.end());

            string combined = left;
            if (center > 0)
                combined += (char)('0' + center);
            combined += right;

            specialPalindromes.push_back(stoll(combined));
        }
    }

    sort(specialPalindromes.begin(), specialPalindromes.end());
    specialPalindromes.erase(unique(specialPalindromes.begin(), specialPalindromes.end()), specialPalindromes.end());
    generated = true;
}

// Find the next special palindrome larger than input
long long findNextPalindrome(long long n) {
    if (!generated)
        generatePalindromes();

    auto it = upper_bound(specialPalindromes.begin(), specialPalindromes.end(), n);
    if (it != specialPalindromes.end()) {
        return *it;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long num;
        cin >> num;
        cout << findNextPalindrome(num) << '\n';
    }

    return 0;
}
