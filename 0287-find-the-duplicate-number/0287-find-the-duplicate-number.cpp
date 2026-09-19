class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            if(ans[nums[i]-1]==1) return nums[i];
            else {
                ans[nums[i]-1]++;
            }
        }
        return -1;
    }
};