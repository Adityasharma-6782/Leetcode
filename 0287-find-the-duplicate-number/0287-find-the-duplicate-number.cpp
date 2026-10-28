class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int count=0;
        while(count<nums.size()){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow==fast){
                slow = 0;
                while(slow!=fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
            count++;
        }
        return -1;
    }
};