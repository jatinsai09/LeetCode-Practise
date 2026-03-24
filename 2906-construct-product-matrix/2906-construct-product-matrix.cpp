class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        long long pre = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = pre;

                pre *= grid[i][j];
                pre %= mod;
            }
        }

        long long suf = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = (res[i][j] * suf) % mod;

                suf *= grid[i][j];
                suf %= mod;
            }
        }

        return res;
    }
};