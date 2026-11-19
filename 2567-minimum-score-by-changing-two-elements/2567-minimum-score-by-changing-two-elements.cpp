class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        if (n == 3) {
            return 0;
        }

        sort(begin(nums), end(nums));

        int r1 = nums[n - 1] - nums[2], r2 = nums[n - 3] - nums[0];
        int r3 = nums[n - 2] - nums[1];

        return min({r1, r2, r3});
    }
};