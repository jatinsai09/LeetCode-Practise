class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1},
                                       {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        vector<vector<int>> dist(n, vector<int>(n));

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1) {
                return dist[x][y];
            }

            for (auto& [dx, dy] : dir) {
                int nx = dx + x, ny = dy + y;
                if (min(nx, ny) >= 0 && max(nx, ny) < n && grid[nx][ny] == 0 &&
                    dist[nx][ny] == 0) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        return -1;
    }
};