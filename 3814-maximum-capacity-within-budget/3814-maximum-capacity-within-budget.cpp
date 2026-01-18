class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size(), res = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({costs[i], capacity[i]});
            if (costs[i] < budget) {
                res = max(res, capacity[i]);
            }
        }
        sort(begin(v), end(v));

        vector<int> pmx(n);
        pmx[0] = v[0].second;

        for (int i = 1; i < n; i++) {
            pmx[i] = max(pmx[i - 1], v[i].second);
        }

        for (int i = 1; i < n; i++) {
            int rem = budget - v[i].first;
            if (rem <= 0) {
                continue;
            }

            int l = 0, r = i - 1, m, j = -1;
            while (l <= r) {
                m = (l + r) / 2;

                if (v[m].first < rem) {
                    j = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (j == -1) {
                continue;
            }

            res = max(res, v[i].second + pmx[j]);
        }

        return res;
    }
};