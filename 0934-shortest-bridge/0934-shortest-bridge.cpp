class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> dir = {1, 0, -1, 0, 1};
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;

        function<void(int, int)> dfs = [&](int x, int y) -> void {
            q.push({x, y});
            vis[x][y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1];

                if (nx < 0 || ny < 0 | nx >= n || ny >= m) {
                    continue;
                }

                if (!vis[nx][ny] && grid[nx][ny] == 1) {
                    dfs(nx, ny);
                }
            }
        };

        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                    break;
                }
            }
        }

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i], ny = y + dir[i + 1];

                    if (nx < 0 || ny < 0 | nx >= n || ny >= m) {
                        continue;
                    }

                    if (!vis[nx][ny]) {
                        if (grid[nx][ny]) {
                            return steps;
                        }
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};