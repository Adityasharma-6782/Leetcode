class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int left = 0;
        int right = 3;

        while (right <= s.length()) {
            if (s[left] != s[left + 1] &&
                s[left + 1] != s[left + 2] &&
                s[left] != s[left + 2]) {
                count++;
            }
            left++;
            right++;
        }
        return count;
    }
};