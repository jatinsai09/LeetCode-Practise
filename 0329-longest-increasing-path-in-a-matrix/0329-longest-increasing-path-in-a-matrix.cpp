class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j]) {
                return dp[i][j];
            }

            int res = 1;
            for (auto& [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || nj < 0 || ni >= n || nj >= m ||
                    mat[ni][nj] <= mat[i][j]) {
                    continue;
                }

                int got = 1 + dfs(ni, nj);
                res = max(res, got);
            }
            return dp[i][j] = res;
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = dfs(i, j);
                res = max(res, len);
            }
        }

        return res;
    }
};