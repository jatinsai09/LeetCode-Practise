class Solution {
#define ll long long int
public:
    ll n;
    vector<vector<ll>> dp;

    ll f(int i, int turn, auto& nums) {
        if (i == n) {
            return 0;
        }

        if (dp[i][turn] != -1) {
            return dp[i][turn];
        }

        ll take1 = LLONG_MIN, take2 = LLONG_MIN;

        take1 = nums[i];
        if (take1 % 3) {
            take1 += f(i + 1, 0, nums);
        } else {
            take1 += f(i + 1, 1, nums);
        }

        if (i + 1 < n) {
            take2 = nums[i] + nums[i + 1];
            if (take2 % 3) {
                take2 += f(i + 2, 0, nums);
            } else {
                take2 += f(i + 2, 1, nums);
            }
        }

        return dp[i][turn] = max(take1, take2) * (turn ? -1 : 1);
    }
    long long maxDifference(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<ll>(2, -1));
        
        return f(0, 0, nums);
    }
};