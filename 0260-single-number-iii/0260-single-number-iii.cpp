class Solution {
#define ll long long
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll xr = 0;
        for (auto& i : nums) {
            xr ^= i;
        }

        ll msk = xr ^ (xr & (xr - 1));

        ll a = 0;
        for (auto& i : nums) {
            if (i & msk) {
                a ^= i;
            }
        }
        return {(int)a, (int)(a ^ xr)};
    }
};