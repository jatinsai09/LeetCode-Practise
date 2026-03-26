class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m, n;
        long long t = 0;

        for (auto& vec : grid) {
            for (auto& i : vec) {
                t += i;
            }
        }

        auto rotate = [&]() {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> res(n, vector<int>(m));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[j][m - i - 1] = grid[i][j];
                }
            }

            grid = res;
        };

        for (int k = 0; k < 4; k++) {
            m = grid.size(), n = grid[0].size();

            if (m == 1) {
                rotate();
                continue;
            }

            if (n == 1) {
                long long got = 0;
                for (int i = 0; i + 1 < m; i++) {
                    got += grid[i][0];
                    long long del = 2 * got - t;

                    if (del == 0 || del == grid[i][0] || del == grid[0][0]) {
                        return true;
                    }
                }
                rotate();
                continue;
            }

            long long got = 0;
            unordered_set<long long> st;
            for (int i = 0; i + 1 < m; i++) {
                for (int j = 0; j < n; j++) {
                    got += grid[i][j];
                    st.insert(grid[i][j]);
                }
                long long del = 2 * got - t;
                if (del == 0) {
                    return true;
                }
                if (i == 0) {
                    if (del == grid[0][0] || del == grid[0][n - 1]) {
                        return true;
                    }
                } else {
                    if (st.count(del)) {
                        return true;
                    }
                }
            }
            rotate();
        }

        return false;
    }
};