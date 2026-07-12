class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, 1);
        int res = 1;

        for (int b = 0; b < m; b++) {
            for (int a = b - 1; a >= 0; a--) {
                if (dp[a] + 1 > dp[b]) {
                    bool yes = true;
                    for (int i = 0; i < n && yes; i++) {
                        yes &= (abs(grid[i][b] - grid[i][a]) <= limit);
                    }

                    if (yes) {
                        dp[b] = dp[a] + 1;
                    }
                }
            }
            res = max(res, dp[b]);
        }

        return res;
    }
};