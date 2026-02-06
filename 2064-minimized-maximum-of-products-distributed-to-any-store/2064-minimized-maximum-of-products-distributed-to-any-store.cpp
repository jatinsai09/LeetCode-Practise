class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int lo = 1, hi = 100000;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            int sum = 0;
            for (int a : quantities) {
                sum += (a + mid - 1) / mid;
            }
            if (sum > n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};