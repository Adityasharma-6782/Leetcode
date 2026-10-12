class Solution {
public:
    vector<vector<int>> res;
    vector<int> A;
    int n;
    void util(int index, vector<int>& comb) {
        if (index == n) {
            res.push_back(comb);
            return;
        }
        util(index + 1, comb);
        comb.push_back(A[index]);
        util(index + 1, comb);
        comb.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        A = nums;
        n = A.size();
        vector<int> comb;
        util(0, comb);
        return res;
    }
};