class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1) {
            return 0;
        }

        vector<int> cur(m, 0);
        cur[0] = 1;
        for (int j = 1; j < m; j++) {
            cur[j] = (grid[0][j] == 1 ? 0 : cur[j - 1]);
        }

        for (int i = 1; i < n; i++) {
            if (grid[i][0]) {
                cur[0] = 0;
            }
            for (int j = 1; j < m; j++) {
                cur[j] += cur[j - 1];
                if (grid[i][j]) {
                    cur[j] = 0;
                }
            }
        }

        return cur[m - 1];
    }
};