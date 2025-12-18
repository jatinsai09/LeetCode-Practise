class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<pair<int, int>> mvs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        function<bool(int, int)> isSafe = [&](int i, int j) -> bool {
            if (i < 0 || i >= n || j < 0 || j >= m) {
                return false;
            }
            return true;
        };

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (!isSafe(i, j) || grid[i][j] != '1') {
                return;
            }

            grid[i][j] = 'v';
            for (const auto& [di, dj] : mvs) {
                dfs(i + di, j + dj);
            }
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ++islands;
                    dfs(i, j);
                }
            }
        }

        return islands;
    }
};