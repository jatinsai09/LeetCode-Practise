class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), largest = 0;
        vector<int> mvs = {0, -1, 0, 1, 0};

        function<bool(int, int)> isSafe = [&](int i, int j) -> bool {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (!isSafe(i, j) || grid[i][j] != 1) {
                return 0;
            }

            int got = 1;
            grid[i][j] = 2;
            for (int d = 1; d <= 4; d++) {
                got += dfs(i + mvs[d], j + mvs[d - 1]);
            }

            return got;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    largest = max(largest, dfs(i, j));
                }
            }
        }

        return largest;
    }
};