class Solution {
#define ll long long
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<ll> f(n), b(n);

        for (int i = 1; i < n; i++) {
            if (i == 1 || nums[i] + nums[i - 2] < 2 * nums[i - 1]) {
                f[i] = f[i - 1] + 1;
            } else {
                f[i] = f[i - 1] + nums[i] - nums[i - 1];
            }
        }

        for (int i = 1; i < n; i++) {
            if (i == n - 1 || 2 * nums[i] <= nums[i + 1] + nums[i - 1]) {
                b[i] = b[i - 1] + 1;
            } else {
                b[i] = b[i - 1] + nums[i] - nums[i - 1];
            }
        }
        
        vector<int> res;
        for (auto &q: queries) {
            int st = q[0], en = q[1];
            if (st < en) {
                res.push_back(f[en] - f[st]);
            } else {
                res.push_back(b[st] - b[en]);
            }
        }

        return res;
    }
};