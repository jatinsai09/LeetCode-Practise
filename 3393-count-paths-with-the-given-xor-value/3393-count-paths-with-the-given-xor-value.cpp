class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int mod = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(16)));

        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 16; k++) {
                    if (i - 1 >= 0) {
                        dp[i][j][k] =
                            (dp[i][j][k] + dp[i - 1][j][k ^ grid[i][j]]) % mod;
                    }
                    if (j - 1 >= 0) {
                        dp[i][j][k] =
                            (dp[i][j][k] + dp[i][j - 1][k ^ grid[i][j]]) % mod;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][k];
    }
};