class Solution {
    public:
        bool can_assign(int k, vector<int>& tasks, vector<int>& workers, int pills,
                        int strength) {
            multiset<int> workersFree(workers.end() - k,
                                      workers.end()); // strongest k workers
            int usedPills = 0;
    
            for (int i = k - 1; i >= 0; --i) {// string task to weaker task y
                auto it = prev(workersFree.end()); // strongest available worker
    
                if (*it >= tasks[i]) {
                    // strongest worker can do task without pill
                    workersFree.erase(it);
                } else {
                    // find weakest worker who can do task with pill
                    it = workersFree.lower_bound(tasks[i] - strength);
                    if (it == workersFree.end()) {
                        return false; // no suitable worker even with pill
                    }
                    usedPills++;
                    if (usedPills > pills) {
                        return false; // pill limit exceeded
                    }
                    workersFree.erase(it);
                }
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                          int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int low = 0, high = min((int)tasks.size(), (int)workers.size()),
                result = 0;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (can_assign(mid, tasks, workers, pills, strength)) {
                    result = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
    
            return result;
        }
    };
    
    
    // | Feature              | multiset      | queue/deque                 |
    // | -------------------- | ------------- | --------------------------- |
    // | Keep sorted          | Always sorted | Need manual sorting         |
    // | Find lower\_bound    | O(log k)      | O(k) (linear scan)          |
    // | Erase arbitrary item | O(log k)      | Only front/back efficiently |
    // | Insert               | O(log k)      | O(1) at ends                |
    
    
    // | Feature                 | `set`                            | `multiset`                                   |
    // | ----------------------- | -------------------------------- | -------------------------------------------- |
    // | **Allows duplicates?**  | **No** — all elements are unique | **Yes** — allows multiple identical elements |
    // | **Order**               | Sorted (by default, ascending)   | Sorted (by default, ascending)               |
    // | **Insertion**           | O(log n)                         | O(log n)                                     |
    // | **Find / lower\_bound** | O(log n)                         | O(log n)                                     |
    // | **Erase**               | O(log n)                         | O(log n), can erase specific occurrence      |
    