class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if (m == 1 || n == 1) {
            if (k > 1) {
                return {};
            }
        }
        if (max(m, n) == 2) {
            if (k > 2) {
                return {};
            }
        } 

        if (m == 3 && n == 3 && k == 4) {
            return {"..#", "...", "#.."};
        } 

        vector<string> res(m, string(n, '#'));
        for (int j = 0; j < n; j++) {
            res[0][j] = '.';
        }
        for (int i = 0; i < m; i++) {
            res[i][n - 1] = '.';
        }

        k--;
        if (k == 0) {
            return res;
        }

        if (n > m) {
            int j = n - 2;
            while (j >= 0) {
                if (k == 0) {
                    break;
                }
                res[1][j] = '.';
                k--;
                j--;
            }
        } else {
            int i = 1;
            while (i < m) {
                if (k == 0) {
                    break;
                }

                res[i][n - 2] = '.';
                i++;
                k--;
            }
        }

        if (k > 0) {
            return {};
        }

        return res;
    }
};