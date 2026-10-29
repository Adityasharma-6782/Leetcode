class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int best=nums[0];

        for(int i=1; i<nums.size(); i++){
            int x = ans+nums[i];
            int y = nums[i];
            ans = max(x,y);
            best = max(best, ans);
        }
        return best;
    }
};