
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int ans = 0;
        int low = 0;
        unordered_map<int, int> f;

        for (int high = 0; high < fruits.size(); high++) {
            f[fruits[high]]++;
            while (f.size() > k) {
                f[fruits[low]]--;
                if (f[fruits[low]] == 0) f.erase(fruits[low]);
                low++;
            }
            ans = max(ans, high - low + 1);
        }
        return ans;
    }
};