class Solution {
public:
    //k * mn >= mx
    int minRemoval(vector<int>& a, int k) {
        int n = a.size(), res = 1;
        sort(begin(a), end(a));

        for (int l = 0, r = 0; r < n; r++) {
            while (1LL * a[l] * k < a[r]) {
                l++;
            }
            res = max(res, r - l + 1);
        }

        return n - res;
    }
};