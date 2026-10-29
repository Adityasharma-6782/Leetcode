class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxEnd = nums[0];
        int minEnd = nums[0];

        for(int i=1; i<nums.size(); i++){
            int v1 = nums[i];
            int v2 = maxEnd*nums[i];
            int v3 = minEnd*nums[i];

            maxEnd = max(v1, max(v2, v3));
            minEnd = min(v1, min(v2, v3));
            res = max(res, max(maxEnd, minEnd));
        }
        return res;
    }
};