class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m), cur(m);

        prev[0] = grid[0][0];
        for (int j = 1; j < m; j++) {
            prev[j] = grid[0][j] + prev[j - 1];
        }

        for (int i = 1; i < n; i++) {
            cur[0] = grid[i][0] + prev[0];
            for (int j = 1; j < m; j++) {
                int up = prev[j];
                int left = cur[j - 1];

                cur[j] = min(left, up) + grid[i][j];
            }
            prev = cur;
        }
        return prev[m - 1];
    }
};