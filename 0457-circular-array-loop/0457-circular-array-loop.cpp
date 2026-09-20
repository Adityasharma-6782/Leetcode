class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) return false;

        vector<int> ans(n, 0);

        for (int start = 0; start < n; start++) {

            if (ans[start] == 2) continue;

            int index = start;
            int direction = nums[start] > 0 ? 1 : -1;

            while (true) {
                if ((direction == 1 && nums[index] < 0) ||
                    (direction == -1 && nums[index] > 0)) {
                    break;
                }
                if (ans[index] == 1) return true;
                if (ans[index] == 2) break;

                ans[index] = 1;
                int next = (index + nums[index]) % n;
                if (next < 0)
                    next += n;

                if (next == index) {
                    break;
                }
                index = next;
            }
            index = start;

            while (ans[index] == 1) {
                ans[index] = 2;
                int next = (index + nums[index]) % n;
                if (next < 0)
                    next += n;
                if (next == index)
                    break;

                index = next;
            }
        }
        return false;
    }
};