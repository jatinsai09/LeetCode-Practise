class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();
        unordered_set<int> vis(begin(a), end(a));

        int ps = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1] + 1) {
                ps += a[i];
            } else {
                break;
            }
        }

        while (vis.count(ps)) {
            ps++;
        }
        return ps;
    }
};