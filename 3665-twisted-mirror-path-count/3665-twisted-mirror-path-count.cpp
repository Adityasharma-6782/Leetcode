class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        auto move = [&](int x, int y, int dir) {
            while (x < m && y < n && grid[x][y] == 1) {
                if (dir == 0) {
                    x++;       
                    dir = 1;
                } else {
                    y++;      
                    dir = 0;
                }
            }

            if (x >= m || y >= n) return pair<int,int>{-1,-1};
            return pair<int,int>{x,y};
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                auto [x1, y1] = move(i, j + 1, 0);
                if (x1 != -1)
                    dp[x1][y1] = (dp[x1][y1] + dp[i][j]) % MOD;

                auto [x2, y2] = move(i + 1, j, 1);
                if (x2 != -1)
                    dp[x2][y2] = (dp[x2][y2] + dp[i][j]) % MOD;
            }
        }

        return dp[m - 1][n - 1];
    }
};