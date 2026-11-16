class Solution {
#define ll long long int
public:
    ll n;
    vector<ll> dp;

    ll f(int i, auto& nums) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        ll take1 = LLONG_MIN, take2 = LLONG_MIN;

        take1 = nums[i];
        if (take1 % 3) {
            take1 += f(i + 1, nums);
        } else {
            take1 -= f(i + 1, nums);
        }

        if (i + 1 < n) {
            take2 = nums[i] + nums[i + 1];
            if (take2 % 3) {
                take2 += f(i + 2, nums);
            } else {
                take2 -= f(i + 2, nums);
            }
        }

        return dp[i] = max(take1, take2);
    }
    long long maxDifference(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        
        return f(0, nums);
    }
};