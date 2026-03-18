class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i + 1][j + 1] =
                    grid[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
                res += (pre[i + 1][j + 1] <= k);
            }
        }
        return res;
    }
};