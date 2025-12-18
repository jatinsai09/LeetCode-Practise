class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<int> mvs = {0, 1, 0, -1, 0};

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
            for (int d = 1; d <= 4; d++) {
                dfs(i + mvs[d - 1], j + mvs[d]);
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