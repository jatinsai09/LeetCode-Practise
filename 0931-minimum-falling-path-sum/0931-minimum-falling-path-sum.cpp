class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> prev(begin(matrix[0]), end(matrix[0]));
        for (int i = 1; i < n; i++) {
            vector<int> cur(m);
            for (int j = 0; j < m; j++) {
                int dr = (j == m - 1 ? INT_MAX : prev[j + 1]);
                int dl = (!j ? INT_MAX : prev[j - 1]);
                int u = prev[j];

                cur[j] = matrix[i][j] + min({u, dl, dr});
            }
            prev = cur;
        }

        return *min_element(begin(prev), end(prev));
    }
};