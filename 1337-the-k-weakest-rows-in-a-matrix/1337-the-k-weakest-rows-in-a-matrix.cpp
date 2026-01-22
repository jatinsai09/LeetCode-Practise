class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            mat[i].push_back(i);
        }
        sort(begin(mat), end(mat));

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(mat[i][m]);
        }

        return res;
    }
};