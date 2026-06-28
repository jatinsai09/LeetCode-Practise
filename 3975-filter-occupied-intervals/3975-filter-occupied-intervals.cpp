class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(begin(occupiedIntervals), end(occupiedIntervals));

        vector<int> prev = occupiedIntervals[0];
        vector<vector<int>> mi;
        for (auto &it: occupiedIntervals) {
            if (it[0] <= prev[1] + 1) {
                prev[1] = max(prev[1], it[1]);
            } else {
                mi.push_back(prev);
                prev = it;
            }
        }
        mi.push_back(prev);

        vector<vector<int>> res;
        for (auto &it: mi) {
            if (it[1] < freeStart || it[0] > freeEnd) {
                res.push_back(it);
                continue;
            }

            if (it[0] < freeStart) {
                res.push_back({it[0], freeStart - 1});
            } 
            if (it[1] > freeEnd) {
                res.push_back({freeEnd + 1, it[1]});
            }
        }

        return res;
    }
};