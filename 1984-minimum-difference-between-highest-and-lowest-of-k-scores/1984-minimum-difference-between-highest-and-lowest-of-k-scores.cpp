class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size();
        if (n == 1) {
            return 0;
        }

        sort(begin(a), end(a));
        int res = a[k - 1] - a[0];
        for (int i = k; i < n; i++) {
            res = min(res, a[i] - a[i - k + 1]);
        }

        return res;
    }
};