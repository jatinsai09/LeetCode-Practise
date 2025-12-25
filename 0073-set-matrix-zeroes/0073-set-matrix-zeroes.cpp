class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool flag1 = false, flag2 = false;

        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) {
                flag1 = true;
            }
        }

        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 0) {
                flag2 = true;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[0][j] = mat[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (!mat[0][j] || !mat[i][0]) {
                    mat[i][j] = 0;
                }
            }
        }

        if (flag1) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }

        if (flag2) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = 0;
            }
        }
    }
};