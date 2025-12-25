class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        int mc, lc = 0, rc = c - 1;

        while (lc <= rc) {
            mc = lc + (rc - lc) / 2;
            int mr = 0;
            for (int i = 0; i < r; i++) {
                if (mat[mr][mc] < mat[i][mc]) {
                    mr = i;
                }
            }

            bool left = mc - 1 >= 0 && mat[mr][mc - 1] > mat[mr][mc];
            bool right = mc + 1 < c && mat[mr][mc + 1] > mat[mr][mc];

            if (!left && !right) {
                return vector<int>{mr, mc};
            }

            if (left) {
                rc = mc - 1;
            } else {
                lc = mc + 1;
            }
        }
        return vector<int>{-1, -1};
    }
};