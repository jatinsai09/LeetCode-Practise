class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bitset<250006> vis;
        vector<int> dir = {-1, 0, 1, 0, -1};

        function<bool(int, int, int, int)> dfs = [&](int r, int c, int pr, int pc) -> bool {
            vis[r * m + c] = 1;

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k], nc = c + dir[k + 1];

                if (nr == pr && nc == pc) {
                    continue;
                }

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }

                if (grid[r][c] != grid[nr][nc]) {
                    continue;
                } 

                if (vis[nr * m + nc] || dfs(nr, nc, r, c)) {
                    return true;
                }
            }

            return false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i * m + j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};