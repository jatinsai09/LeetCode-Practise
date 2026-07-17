class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dir = {1, 0, -1, 0, 1};
        vector<vector<int>> vis(n, vector<int>(n));

        int mid, l = 0, r = n * n;
        function<void()> dfs = [&]() -> void {
            if (grid[0][0] > mid) {
                return;
            }

            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = 1;
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k], nj = j + dir[k + 1];

                    if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
                        continue;
                    }

                    if (!vis[ni][nj] && grid[ni][nj] <= mid) {
                        q.push({ni, nj});
                        vis[ni][nj] = 1;
                    }
                }
            }
        };

        while (l <= r) {
            mid = l + (r - l) / 2;

            vis = vector<vector<int>>(n, vector<int>(m, 0));
            dfs();
            if (vis[n - 1][m - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};