class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n), diag(2 * n - 1), anti_diag(2 * n - 1);

        function<int(int)> give = [&](int r) -> int {
            int got = 0;
            if (r == n) {
                return 1;
            }

            for (int c = 0; c < n; c++) {
                if (col[c] || diag[r + c] || anti_diag[r - c + n - 1]) {
                    continue;
                }
                
                col[c] = diag[r + c] = anti_diag[r - c + n - 1] = 1;
                got += give(r + 1);
                col[c] = diag[r + c] = anti_diag[r - c + n - 1] = 0;
            }

            return got;
        };

        return give(0);
    }
};