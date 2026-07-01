class Solution {
#define pii pair<int, int>
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<int> dir = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<pair<int, pii>> pq;
        vector<vector<int>> vis(n, vector<int>(n));

        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = 1;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int sf = it.first, r = it.second.first, c = it.second.second;
            if (r == n - 1 && c == n - 1) {
                return sf;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc]) {
                    int nsf = min(sf, dist[nr][nc]);
                    vis[nr][nc] = 1;
                    pq.push({nsf, {nr, nc}});
                }
            }
        }

        return -1;
    }
};