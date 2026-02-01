class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mn1 = nums[1], mn2 = nums[2];

        for (int i = 2; i < n; i++) {
            if (nums[i] <= mn1) {
                mn2 = mn1;
                mn1 = nums[i];
            } else if (nums[i] < mn2) {
                mn2 = nums[i];
            }
        }

        return nums[0] + mn1 + mn2;
    }
};