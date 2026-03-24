class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pre(n, vector<int>(m)), suf(pre), res(pre);

        long long p = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }

        p = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suf[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long mul = pre[i][j] * suf[i][j];

                res[i][j] = mul % mod;
            }
        }
        
        return res;
    }
};