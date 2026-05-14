class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for (auto &i: nums) {
            mx = max(mx, i);
        }
        if (mx != n - 1) {
            return false;
        }

        vector<int> f(n);
        int d = 0;
        for (auto &i: nums) {
            d += (++f[i] == 1);
        }

        return d == n - 1 && f[n - 1] == 2;
    }
};