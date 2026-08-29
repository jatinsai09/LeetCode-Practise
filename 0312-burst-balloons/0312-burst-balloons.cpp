#define ll long long int
class Solution {
public:
    // ll dpp[313][313];
    // ll help(int i, int j, vector<int>& nums) {
    //     if (i > j) {
    //         return 0;
    //     }
    //     if (dpp[i][j] != -1) {
    //         return dpp[i][j];
    //     }
    //     ll res = LLONG_MIN;

    //     for (int ind = i; ind <= j; ind++) {
    //         ll got = 1LL * nums[i - 1] * nums[ind] * nums[j + 1] +
    //                  help(i, ind - 1, nums) + help(ind + 1, j, nums);
    //         res = max(res, got);
    //     }
    //     return dpp[i][j] = res;
    // }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(begin(nums), 1);

        ll dp[n + 3][n + 3];
        memset(dp, 0LL, sizeof(dp));

        for (int i = n; i > 0; i--) {
            for (int j = i; j <= n; j++) {
                ll res = LLONG_MIN;

                for (int ind = i; ind <= j; ind++) {
                    ll got = 1LL * nums[i - 1] * nums[ind] * nums[j + 1] +
                             dp[i][ind - 1] + dp[ind + 1][j];
                    res = max(res, got);
                }
                dp[i][j] = res;
            }
        }

        return dp[1][n];
    }
};