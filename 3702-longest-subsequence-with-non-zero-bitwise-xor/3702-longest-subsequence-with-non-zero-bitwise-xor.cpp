class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int f = 0, xr = 0, n = nums.size();

        for (auto& i : nums) {
            f |= (i > 0);
            xr ^= i;
        }

        return f * (xr ? n : n - 1);
    }
};