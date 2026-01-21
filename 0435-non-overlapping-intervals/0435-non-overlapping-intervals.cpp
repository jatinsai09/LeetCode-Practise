class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = intervals.size(), res = 0;
        sort(intervals.begin(), intervals.end(),
             [&](auto& a, auto& b) { return a[1] < b[1]; });

        vector<int> prev = intervals[0];
        for (int i = 1; i < n; i++) {
            if (prev[1] > intervals[i][0]) {
                res++;
            } else {
                prev = intervals[i];
            }
        }
        return res;
    }
};