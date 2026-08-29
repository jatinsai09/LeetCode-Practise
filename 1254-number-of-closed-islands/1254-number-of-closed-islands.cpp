class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));

        vector<int> dir = {1, 0, -1, 0, 1};

        function<void(int, int)> dfs = [&](int x, int y) -> void {
            vis[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                if (!vis[nx][ny] && grid[nx][ny] == 0) {
                    dfs(nx, ny);
                } 
            }

            return;
        };

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                dfs(i, 0);
            }
            if (grid[i][m - 1] == 0) {
                dfs(i, m - 1);
            } 
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) {
                dfs(0, j);
            }
            if (grid[n - 1][j] == 0) {
                dfs(n - 1, j);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    res++;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};