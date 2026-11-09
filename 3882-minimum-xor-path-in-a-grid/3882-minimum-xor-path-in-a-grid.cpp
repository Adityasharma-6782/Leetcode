class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        const int MAX_XOR = 1024;

        vector<bitset<1024>> dp(m * n);

        dp[0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int idx = i * n + j;
                int val = grid[i][j];

                // From top
                if (i > 0) {
                    int prev = (i - 1) * n + j;

                    for (int x = 0; x < MAX_XOR; x++) {
                        if (dp[prev][x]) {
                            dp[idx][x ^ val] = 1;
                        }
                    }
                }

                // From left
                if (j > 0) {
                    int prev = i * n + (j - 1);

                    for (int x = 0; x < MAX_XOR; x++) {
                        if (dp[prev][x]) {
                            dp[idx][x ^ val] = 1;
                        }
                    }
                }
            }
        }

        int last = (m - 1) * n + (n - 1);

        for (int x = 0; x < MAX_XOR; x++) {
            if (dp[last][x]) {
                return x;
            }
        }

        return -1;
    }
};
