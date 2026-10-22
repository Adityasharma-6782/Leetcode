
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long windowSum = 0;
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];
            mp[nums[right]]++;

            if (right - left + 1 > k) {
                windowSum -= nums[left];
                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            if (right - left + 1 == k && mp.size() == k) {
                ans = max(ans, windowSum);
            }
        }

        return ans;
    }
};
