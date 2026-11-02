class Solution {
public:
    long long makePalindrome(long long prefix, int len) {
        string s = to_string(prefix);
        string p = s;

        int i = (len % 2 == 0) ? s.size() - 1 : s.size() - 2;

        while (i >= 0) {
            p += s[i--];
        }

        return stoll(p);
    }

    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long median = nums[n / 2];

        string s = to_string(median);
        int len = s.size();
        int prefixLen = (len + 1) / 2;

        long long prefix = stoll(s.substr(0, prefixLen));

        vector<long long> candidates;

        // Boundary palindromes
        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);

        // Nearby palindrome candidates
        for (long long p = prefix - 1; p <= prefix + 1; p++) {
            if (to_string(p).size() == prefixLen) {
                candidates.push_back(makePalindrome(p, len));
            }
        }

        long long ans = LLONG_MAX;

        for (long long target : candidates) {
            if (target <= 0) continue;

            long long cost = 0;

            for (int num : nums) {
                cost += abs((long long)num - target);
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};