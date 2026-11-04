class Solution {
    multiset<long long> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void rebalance() {
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            long long val = *it;
            lo.erase(it);
            sumLo -= val;

            hi.insert(val);
            sumHi += val;
        }

        while (lo.size() < hi.size()) {
            auto it = hi.begin();
            long long val = *it;
            hi.erase(it);
            sumHi -= val;

            lo.insert(val);
            sumLo += val;
        }
    }

    void add(long long val) {
        if (lo.empty() || val <= *lo.rbegin()) {
            lo.insert(val);
            sumLo += val;
        } else {
            hi.insert(val);
            sumHi += val;
        }

        rebalance();
    }

    void remove(long long val) {
        auto it = lo.find(val);

        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= val;
        } else {
            it = hi.find(val);
            hi.erase(it);
            sumHi -= val;
        }

        rebalance();
    }

    long long getCost() {
        long long median = *lo.rbegin();

        return median * (long long)lo.size() - sumLo
             + sumHi - median * (long long)hi.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Cost of every window of size x
        vector<long long> cost(n - x + 1);

        lo.clear();
        hi.clear();
        sumLo = sumHi = 0;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const long long INF = LLONG_MAX / 4;

        // prev[i]: minimum cost for previous number
        // of subarrays using first i elements
        vector<long long> prev(n + 1, 0);
        vector<long long> cur(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element
                cur[i] = cur[i - 1];

                // Select a window of size x ending at i-1
                if (i >= x && prev[i - x] != INF) {
                    cur[i] = min(
                        cur[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(cur);
        }

        return prev[n];
    }
};