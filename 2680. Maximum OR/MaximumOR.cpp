#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n);
        vector<long long> suffix(n);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] | nums[i];
        }

        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }

        long long max_or = 0;

        for (int i = 0; i < n; i++) {
            long long current = 0;

            if (i > 0)
                current |= prefix[i - 1];

            long long shifted = (long long)nums[i] << k;

            current |= shifted;

            if (i < n - 1)
                current |= suffix[i + 1];

            max_or = max(max_or, current);
        }

        return max_or;
    }
};