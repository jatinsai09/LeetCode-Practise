class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl,
                                             vector<vector<int>>& sl) {
        int n = fl.size(), m = sl.size();
        int i = 0, j = 0;

        vector<vector<int>> res;

        while (i < n && j < m) {
            int a_start = fl[i][0], a_end = fl[i][1];
            int b_start = sl[j][0], b_end = sl[j][1];

            if (a_start <= b_end && b_start <= a_end) {
                res.push_back({max(a_start, b_start), min(a_end, b_end)});
            }

            if (a_end <= b_end) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};