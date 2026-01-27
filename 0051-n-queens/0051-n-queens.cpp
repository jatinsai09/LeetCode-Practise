class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> b(n, string(n, '.'));

        vector<int> c(n), md(2 * n - 1), od(2 * n - 1);

        function<void(int)> f = [&](int row) -> void {
            if (row == n) {
                res.push_back(b);
            }

            for (int col = 0; col < n; col++) {
                if (c[col] || md[row + col] || od[n - 1 + col - row]) {
                    continue;             
                }
                c[col] = 1;
                md[row + col] = 1;
                od[n - 1 + col - row] = 1;
                b[row][col] = 'Q';

                f(row + 1);

                c[col] = 0;
                md[row + col] = 0;
                od[n - 1 + col - row] = 0;
                b[row][col] = '.';       
            }
        };

        f(0);
        return res;
    }
};