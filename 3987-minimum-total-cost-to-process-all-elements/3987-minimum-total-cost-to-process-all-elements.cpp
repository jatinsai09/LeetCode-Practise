class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int minimumCost(vector<int>& nums, int k) {
        ll s = 0;
        for (auto &i: nums) {
            s += i;
        }

        ll m = (s + k - 1) / k % mod;

        return m * (m - 1) / 2 % mod;
    }
};