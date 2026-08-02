class Solution {
#define ll long long int
public:
    long long maxPairStrength(vector<int>& nums) {
        ll n = nums.size(), res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll g = __gcd(nums[i], nums[j]);
                g *= g;

                ll mul = 1LL * nums[i] * nums[j];

                res = max(res, mul / g);
            }
        }
        return res;
    }
};