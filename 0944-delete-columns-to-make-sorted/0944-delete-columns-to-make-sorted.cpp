class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), res = 0;

        for (int j = 0; j < m; j++) {
            int f = 0;
            for (int i = 1; i < n && !f; i++) {
                f |= (strs[i][j] < strs[i - 1][j]);
            }
            res += f;
        }

        return res;
    }
};