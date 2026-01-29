class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for (auto& i : nums) {
            xr ^= i;
        }

        int msk = 1;
        while(!(xr & msk)){
            msk <<= 1;
        }

        int a = 0;
        for (auto& i : nums) {
            if (i & msk) {
                a ^= i;
            }
        }
        return {a, a ^ xr};
    }
};