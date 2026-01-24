class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size(), res = 0;

        for (int i = 0; i < (n >> 1); i++) {
            res = max(res, nums[n - 1 - i] + nums[i]);
        }

        return res;
    }
};