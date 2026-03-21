class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), cur = 0, maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            cur += nums[i];
            maxi = max(maxi, cur);
            if (cur < 0) {
                cur = 0;
            }
        }
        return maxi;
    }
};