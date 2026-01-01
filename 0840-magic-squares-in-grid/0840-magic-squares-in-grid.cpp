class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;

        auto isMagicSquare = [&](int r, int c) -> bool {
            int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
            unordered_set<int> st;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = grid[r + i][c + j];
                    if (num < 1 || num > 9 || st.count(num)) {
                        return false;
                    }
                    st.insert(num);
                }
            }

            for (int k = 0; k < 3; k++) {
                if (grid[r][c + k] + grid[r + 1][c + k] + grid[r + 2][c + k] !=
                    sum) {
                    return false;
                }
                if (grid[r + k][c] + grid[r + k][c + 1] + grid[r + k][c + 2] !=
                    sum) {
                    return false;
                }
            }

            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum) {
                return false;
            }
            if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum) {
                return false;
            }

            return true;
        };

        for (int r = 0; r + 2 < m; r++) {
            for (int c = 0; c + 2 < n; c++) {
                if (isMagicSquare(r, c))
                    cnt++;
            }
        }
        return cnt;
    }
};