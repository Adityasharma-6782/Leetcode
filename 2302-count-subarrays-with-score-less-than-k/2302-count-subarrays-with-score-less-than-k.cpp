class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long count = 0;
        int left = 0;
        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            while(sum*(right-left+1)>=k){
                sum -= nums[left];
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
};