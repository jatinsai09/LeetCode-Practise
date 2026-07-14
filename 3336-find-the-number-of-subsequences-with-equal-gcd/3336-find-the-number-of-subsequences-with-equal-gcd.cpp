class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int dp[201][201][201];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> find = [&](int i, int g1, int g2) -> int {
            if (i == n) {
                return (g1 && g1 == g2);
            }

            int &res = dp[i][g1][g2];
            if (res != -1) {
                return res;
            }

            res = find(i + 1, g1, g2);

            int ng1 = __gcd(g1, nums[i]);
            res = (res + find(i + 1, ng1, g2)) % mod;

            int ng2 = __gcd(g2, nums[i]);
            res = (res + find(i + 1, g1, ng2)) % mod;

            return res;
        };

        return find(0, 0, 0);
    }
};