class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;

        for (int i = 0; i < m; i++) {
            int c1 = 0;
            for (int j = 0; j < n; j++) {
                c1 += (grid[i][j]);
            }
            if (c1 > 1) {
                res += c1;
                for (int j = 0; j < n; j++) {
                    if (grid[i][j]) {
                        grid[i][j] = 2;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int c1 = 0, c2 = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 2) {
                    c2++;
                } else if (grid[i][j] == 1) {
                    c1++;
                }
            }

            if (c1 + c2 > 1) {
                res += c1;
            }
        }
        
        return res;
    }
};