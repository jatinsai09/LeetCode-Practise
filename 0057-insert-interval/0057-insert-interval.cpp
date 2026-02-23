

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int s = newInterval[0], e = newInterval[1], f = 1;

        for (const auto& i : intervals) {
            if (i[1] < s) {
                res.push_back(i);
            } else if (i[0] > e) {
                if (f) {
                    res.push_back({s, e});
                    f = 0;
                }
                res.push_back(i);
            } else {
                s = min(s, i[0]);
                e = max(e, i[1]);
            }
        }
        if (f) {
            res.push_back({s, e});
        }
        return res;
    }
};