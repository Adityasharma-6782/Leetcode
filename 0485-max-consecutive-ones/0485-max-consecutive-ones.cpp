class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0;
        int ans=0;
        int count=0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right]!=1){
                count=0;
            } else {
                count++;
            }
            ans=max(ans, count);
        }
        return ans;
    }
};