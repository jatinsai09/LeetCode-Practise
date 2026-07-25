class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int l = 0, r = m - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;

            int row = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[row][mid]) {
                    row = i;
                }
            }

            int left = (mid ? mat[row][mid - 1] : -1);
            int right = (mid + 1 < m ? mat[row][mid + 1] : -1);

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return {-1, -1};
    }
};