class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            boundary;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            boundary.push({heightMap[i][0], i, 0});
            boundary.push({heightMap[i][m - 1], i, m - 1});
            vis[i][0] = vis[i][m - 1] = 1;
        }

        for (int j = 1; j < m - 1; j++) {
            boundary.push({heightMap[0][j], 0, j});
            boundary.push({heightMap[n - 1][j], n - 1, j});
            vis[0][j] = vis[n - 1][j] = 1;
        }

        int total = 0;
        while (!boundary.empty()) {
            auto cur = boundary.top();
            boundary.pop();
            int minBH = cur[0], i = cur[1], j = cur[2];

            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj]) {
                    continue;
                }

                int n_height = heightMap[ni][nj];
                if (n_height < minBH) {
                    total += (minBH - n_height);
                }
                vis[ni][nj] = 1;
                boundary.push({max(minBH, n_height), ni, nj});
            }
        }
        return total;
    }
};