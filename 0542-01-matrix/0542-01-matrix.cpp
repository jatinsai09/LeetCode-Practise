class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = grid.size(), m = grid[0].size(), maxi = n + m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                int top = maxi, left = maxi;
                if (i - 1 >= 0) {
                    top = grid[i - 1][j];
                }
                if (j - 1 >= 0) {
                    left = grid[i][j - 1];
                }
                grid[i][j] = min(top, left) + 1;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    continue;
                }

                int bottom = maxi, right = maxi;
                if (i + 1 < n) {
                    bottom = grid[i + 1][j];
                }
                if (j + 1 < m) {
                    right = grid[i][j + 1];
                }
                grid[i][j] = min({bottom + 1, right + 1, grid[i][j]});
            }
        }
        return grid;
    }
};