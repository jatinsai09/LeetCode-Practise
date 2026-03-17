class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    mat[i][j] += mat[i - 1][j];
                } 
            }
        }

        int res = 0;
        for (auto &v: mat) {
            sort(rbegin(v), rend(v));
            for (int j = 0; j < m; j++) {
                res = max(res, (j + 1) * v[j]);
            }
        }
        
        return res;
    }
};