class NumArray {
public:
    vector<int> nums;
    vector<int> ans;
    NumArray(vector<int>& arr) {
        nums = arr;
        ans.resize(nums.size() + 1, 0);
        for(int i=0; i<nums.size(); i++) {
            ans[i+1] = ans[i]+nums[i];
        }
    }
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        for (int i=index+1; i<ans.size(); i++) {
            ans[i] += diff;
        }
    }
    int sumRange(int left, int right) {
        return ans[right+1]-ans[left];
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */