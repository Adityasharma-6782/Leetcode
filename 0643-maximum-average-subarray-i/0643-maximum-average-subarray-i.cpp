class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        long long maxSum = sum;
        int left = 0;
        int right = k;
        while (right < nums.size()) {
            sum = sum + nums[right] - nums[left];
            maxSum = max(maxSum, sum);
            left++;
            right++;
        }
        return (double)maxSum / k;
    }
};