class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves=0;
        for(int x : nums){
            moves += abs(x-nums[nums.size()-1]);
        }
        return moves;
    }
};