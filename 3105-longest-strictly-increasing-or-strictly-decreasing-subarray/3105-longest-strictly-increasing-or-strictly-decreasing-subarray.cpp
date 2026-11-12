class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), inc = 1, dec = 1, res = 1;

        for (int i = 1; i < n; i++) {
            inc = (nums[i] > nums[i - 1] ? inc + 1 : 1);
            dec = (nums[i] < nums[i - 1] ? dec + 1 : 1);

            res = max({res, inc, dec});
        }

        return res;
    }
};