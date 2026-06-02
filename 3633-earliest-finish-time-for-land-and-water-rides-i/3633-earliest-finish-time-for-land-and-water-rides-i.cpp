class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int res = 4000, n = ls.size(), m = ws.size();

        int f1 = 4000, f2 = 4000;
        for (int i = 0; i < n; i++) {
            f1 = min(f1, ls[i] + ld[i]);
        }

        for (int i = 0; i < m; i++) {
            f2 = min(f2, ws[i] + wd[i]);
        }

        for (int i = 0; i < m; i++) {
            if (ws[i] > f1) {
                res = min(res, f1 + (ws[i] - f1) + wd[i]);
            }
            else {
                res = min(res, f1 + wd[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (ls[i] > f2) {
                res = min(res, f2 +  (ls[i] - f2) + ld[i]);
            }
            else {
                res = min(res, f2 + ld[i]);
            }
        }

        return res;
    }
};