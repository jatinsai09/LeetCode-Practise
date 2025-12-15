class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for (const auto& num: nums) {
            xr ^= num;
        }

        return xr;
    }
};