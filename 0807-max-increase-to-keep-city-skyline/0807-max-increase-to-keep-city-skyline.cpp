class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> l(n), d(n);

        for (int i = 0; i < n; i++) {
            int mx = grid[i][0];
            for (int j = 0; j < n; j++) {
                mx = max(mx, grid[i][j]);
            }

            l[i] = mx;
        }
        for (int j = 0; j < n; j++) {
            int mx = grid[0][j];
            for (int i = 0; i < n; i++) {
                mx = max(mx, grid[i][j]);
            }

            d[j] = mx;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min({l[i], d[j]}) - grid[i][j];
            }
        }

        return res;
    }
};