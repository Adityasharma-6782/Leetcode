class Solution {

int maxSum(vector<int>& nums){
    int best = nums[0];
    int ans = nums[0];
    for(int i=1; i<nums.size(); i++){
        int v1 = nums[i];
        int v2 = best+nums[i];
        best = max(v1, v2);
        ans = max(ans, best);
    }
    return ans;
}

int minSum(vector<int>& nums){
    int best = nums[0];
    int ans = nums[0];
    for(int i=1; i<nums.size(); i++){
        int v1 = nums[i];
        int v2 = best+nums[i];
        best = min(v1, v2);
        ans = min(ans, best);
    }
    return ans;
}

public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = maxSum(nums);
        int mini = minSum(nums);
        return max(abs(maxi), abs(mini));
    }
};