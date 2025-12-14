class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int n = nums.size(), ss = 0, sl = 0;
        for (int i = 0; i < k; i++) {
            ss += nums[i];
            sl += nums[n - i - 1];
        }
        return sl - ss;
    }
};