#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> m;

    RandomizedSet() {}

    bool insert(int val) {
        if (m.find(val) != m.end()) {  // Corrected existence check
            return false;
        }
        m[val] = v.size();
        v.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }

        int lastElement = v.back();
        int idx = m[val];

        v[idx] = lastElement;   // Swap the element with the last one
        m[lastElement] = idx;   // Update its index in the map

        v.pop_back();           // Remove the last element
        m.erase(val);           // Remove from map

        return true;
    }

    int getRandom() {
        if (v.empty()) return -1; // Handle edge case
        return v[rand() % v.size()];
    }
};
