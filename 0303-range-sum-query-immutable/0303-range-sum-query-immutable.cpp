class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) {
        ans.resize(nums.size()+1);
        ans[0]=0;

        for(int i=0; i<nums.size(); i++){
            ans[i+1] = ans[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return ans[right+1]-ans[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */