class Solution {
public:
    int longestMountain(vector<int> a) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = a.size(), res = 0;
        vector<int> dp1(n, 1), dp2(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                dp2[i] = dp2[i + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] > a[i - 1]) {
                dp1[i] = 1 + dp1[i - 1];
            }
            
            if (dp1[i] > 1 && dp2[i] > 1) {
                res = max(res, dp1[i] + dp2[i] - 1);
            }
        }

        return res;
    }
};