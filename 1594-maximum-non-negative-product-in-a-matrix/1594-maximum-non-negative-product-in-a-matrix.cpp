class Solution {
#define ll long long int
const int mod = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> dp1(n, vector<ll>(m, 0)); // max
        vector<vector<ll>> dp2(n, vector<ll>(m, 0)); // min

        dp1[0][0] = dp2[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp1[i][0] = dp2[i][0] = dp1[i - 1][0] * grid[i][0];
        }

        for (int j = 1; j < m; j++) {
            dp1[0][j] = dp2[0][j] = dp1[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                ll u1 = dp1[i - 1][j] * grid[i][j];
                ll u2 = dp2[i - 1][j] * grid[i][j];
                ll l1 = dp1[i][j - 1] * grid[i][j];
                ll l2 = dp2[i][j - 1] * grid[i][j];

                dp1[i][j] = max({u1, u2, l1, l2});
                dp2[i][j] = min({u1, u2, l1, l2});
            }
        }

        if (dp1[n - 1][m - 1] < 0) {
            return -1;
        }

        return dp1[n - 1][m - 1] % mod;
    }
};