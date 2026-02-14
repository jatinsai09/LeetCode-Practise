class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(1, poured);

        for (int i = 1; i <= query_row + 1; i++) {
            vector<double> next(i + 1);
            for (int j = 0; j < i; j++) {
                if (cur[j] >= 1) {
                    next[j] += (cur[j] - 1) / 2.0;
                    next[j + 1] += (cur[j] - 1) / 2.0;
                    cur[j] = 1;
                }
            }
            if (i <= query_row) cur = next;
        }

        return cur[query_glass];
    }
};