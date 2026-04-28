class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int res = 0;
        vector<int> v;
        for (const auto& row : grid) {
            v.insert(end(v), begin(row), end(row));
        }

        int n = v.size();
        nth_element(begin(v), begin(v) + n / 2, end(v));

        for (int i = 0; i < n; i++) {
            if (abs(v[n / 2] - v[i]) % x) {
                return -1;
            } else {
                res += abs(v[n / 2] - v[i]) / x;
            }
        }
        return res;
    }
};