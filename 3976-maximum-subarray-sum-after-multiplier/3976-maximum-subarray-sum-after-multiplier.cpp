class Solution {
#define ll long long
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size(), res = INT_MIN;

        ll dp0 = 0, dp1 = 0, dpd = 0, dpm = 0;
        for (auto &it: nums) {
            ll i = 1LL * it;

            dp1 = max({dp1 + i, dpm + i, dpd + i});
            dpm = max({dpm + i * k, dp0 + i * k, i * k});
            dpd = max({dpd + i / k, dp0 + i / k, i / k});
            dp0 = max(dp0 + i, i);

            res = max({res, dp0, dpm, dpd, dp1});
        }

        return res; 
    }
};