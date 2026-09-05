class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        vector<int> mvs = {0, 1, 0, -1, 0};

        function<bool(int, int)> isSafe = [&](int i, int j) -> bool {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (!isSafe(i, j) || grid[i][j] != '1' || vis[i][j]) {
                return;
            }

            vis[i][j] = 1;
            for (int d = 1; d <= 4; d++) {
                dfs(i + mvs[d], j + mvs[d - 1]);
            }
        };

        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ++islands;
                    dfs(i, j);
                }
            }
        }

        return islands;
    }
};