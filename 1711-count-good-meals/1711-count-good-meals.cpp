class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long count = 0;

        for (int x : deliciousness) {
            // Generate powers of 2 using left shift
            for (int power = 1; power <= (1 << 21); power <<= 1) {
                int complement = power - x;
                if (freq.count(complement)) {
                    count += freq[complement];
                }
            }
            freq[x]++;
        }
        return count % MOD;
    }
};