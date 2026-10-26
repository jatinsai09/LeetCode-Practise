class Solution {
#define ll long long
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto isValid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        auto bfs = [&](int i, int j) -> int {
            long long sum = 0;
            queue<pair<int, int>> q;

            q.push({i, j});
            vis[i][j] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                sum += grid[x][y];

                for (auto& [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;

                    if (isValid(nx, ny) && !vis[nx][ny] && grid[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }   
            }
            return (sum % k == 0);
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j] || vis[i][j]) {
                    continue;
                }
                
                res += bfs(i, j);
            }
        }

        return res;
    }
};