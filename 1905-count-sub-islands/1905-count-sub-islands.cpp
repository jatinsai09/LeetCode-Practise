class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), yes = 0;
        vector<vector<bool>> vis(n, vector<bool>(m));

        vector<int> dir = {1, 0, -1, 0, 1};
        function<void(int, int)> dfs = [&](int r, int c) -> void {
            if (!grid1[r][c]) {
                yes = 0;
            }

            vis[r][c] = 1;
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid2[nr][nc] && !vis[nr][nc]) {
                    dfs(nr, nc);
                }
            }
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid2[i][j]) {
                    continue;
                }

                yes = 1;
                if (!vis[i][j]) {
                    dfs(i, j);
                    res += yes;
                }
                yes = 0;
            }
        }

        return res;
    }
};