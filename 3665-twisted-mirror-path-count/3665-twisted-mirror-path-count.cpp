class Solution {
public:
    const int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        dp[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if ((i == n - 1 && j == m - 1) || grid[i][j]) {
                    continue;
                }

                int right = 0, down = 0;
                int curi = i, curj = j + 1, d = 1;
                while (curi < n && curj < m) {
                    if (!grid[curi][curj]) {
                        right = dp[curi][curj];
                        break;
                    }
                    if (d) {
                        curi++;
                    } else {
                        curj++;
                    }
                    d ^= 1;
                }
                curi = i + 1, curj = j, d = 0;
                while (curi < n && curj < m) {
                    if (!grid[curi][curj]) {
                        down = dp[curi][curj];
                        break;
                    }
                    if (d) {
                        curi++;
                    } else {
                        curj++;
                    }
                    d ^= 1;
                }
                dp[i][j] = (right + down) % mod;
            }
        }
        return dp[0][0];
    }
};