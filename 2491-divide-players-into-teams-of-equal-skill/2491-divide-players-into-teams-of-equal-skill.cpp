class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        long long sum = 0;
        while(left<right){
            if((nums[left]-nums[left+1])!=(nums[right-1]-nums[right])) return -1;
            long long pro = nums[left]*nums[right];
            sum += pro;
            left++;
            right--;
        }
        return sum;
    }
};