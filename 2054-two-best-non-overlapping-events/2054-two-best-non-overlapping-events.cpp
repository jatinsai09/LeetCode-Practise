class Solution {
#define info tuple<int, int, int>
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = events.size(), res = 0, maxi = 0;
        vector<info> v(2 * n);
        for (int i = 0; i < n; i++) {
            int s = events[i][0], e = events[i][1], val = events[i][2];
            v[2 * i] = {s, 1, val};
            v[2 * i + 1] = {e + 1, 0, val};
        }

        sort(begin(v), end(v));

        for (auto& [t, isStart, val] : v) {
            if (isStart)
                res = max(res, maxi + val);
            else {
                maxi = max(maxi, val);
            }
        }
        return res;
    }
};