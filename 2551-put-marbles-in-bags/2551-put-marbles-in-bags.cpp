class Solution {
public:
    long long putMarbles(vector<int>& wts, int k) {
        int n = wts.size();
        if (k == 1 || k == n) {
            return 0;
        }

        vector<int> v;
        for (int i = 0; i < n - 1; i++) {
            v.push_back(wts[i] + wts[i + 1]);
        }
        sort(begin(v), end(v));
        
        long long int mn = 0, mx = 0;
        for (int i = 0; i < k - 1; i++) {
            mn += v[i];
            mx += v[n - 2 - i];
        }
        return mx - mn;
    }
};