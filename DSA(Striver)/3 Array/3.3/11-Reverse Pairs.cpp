class Solution {
public:
    int merge(int low, int mid, int high, vector<int>& a) {
        vector<int> temp;
        int c = 0;
        int left = low;
        int right = mid + 1;

        // Count reverse pairs
        int j = mid + 1;
        // for (int j = mid + 1; j <= high; j++) {
        //     int i = low;
        //     while (i <= mid && a[i] <= 2LL * a[j]) {
        //         i++;
        //     }
        //     c += (mid - i + 1); // Count valid pairs
        // }

        for (int i = low; i <= mid; i++) {
            while (j <= high && a[i] > 2LL * a[j]) {
                j++;
            }
            c += (j - (mid + 1));
        }

        // Merge the two halves
        left = low;
        right = mid + 1;
        while (left <= mid && right <= high) {
            if (a[left] <= a[right]) {
                temp.push_back(a[left++]);
            } else {
                temp.push_back(a[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(a[left++]);
        }
        while (right <= high) {
            temp.push_back(a[right++]);
        }

        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }

        return c;
    }

    int ci(int low, int high, vector<int>& a) {
        int cnt = 0;
        if (low >= high)
            return cnt;

        int mid = (high + low) / 2;
        cnt += ci(low, mid, a);
        cnt += ci(mid + 1, high, a);
        cnt += merge(low, mid, high, a);

        return cnt;
    }

    int reversePairs(vector<int>& a) {
        int n = a.size();
        return ci(0, n - 1, a);
    }
};
