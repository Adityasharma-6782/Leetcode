class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int nodelete = nums[0];
        int onedelete = INT_MIN;
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;
            nodelete = max(nodelete+nums[i], nums[i]);
            int temp;
            if(prevonedelete == INT_MIN) temp = nums[i];
            else temp = prevonedelete+nums[i];
            onedelete = max(temp, prevnodelete);
            res = max(res, max(nodelete, onedelete));
        }
        return res;
    }
};