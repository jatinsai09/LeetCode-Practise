class Solution {
#define ll long long int
public:
    long long maxRatings(vector<vector<int>>& units) {
        ll m = units.size(), n = units[0].size();
        if (m == 1) {
            return *min_element(begin(units[0]), end(units[0]));
        }
        if (n == 1) {
            ll res = 0;
            for (int i = 0; i < m; i++) {
                res += units[i][0];
            }
            return res;
        }

        ll mn = units[0][0], sum = 0, res = 0;
        for (int i = 0; i < m; i++) {
            sort(begin(units[i]), end(units[i]));
            sum += units[i][1];
            mn = min(mn, 1LL * units[i][0]);
        }

        for (int i = 0; i < m; i++) {
            res = max(res, sum - units[i][1] + mn);
        }

        return res;
    }
};