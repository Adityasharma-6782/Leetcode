class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // for(int i=0; i<nums.size(); i++){
        //     int leftSum=0;
        //     for(int j=0; j<i; j++) leftSum += nums[j];
        //     int rightSum=0;
        //     for(int k=i+1; k<nums.size(); k++) rightSum += nums[k];
        //     if(leftSum == rightSum) return i;
        // }
        // return -1;

        if(nums.size()==1) return 0;
        int sum=0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        int leftSum=0;
        int rightSum=sum;
        for(int i=0; i<nums.size(); i++){
            rightSum -= nums[i];
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};