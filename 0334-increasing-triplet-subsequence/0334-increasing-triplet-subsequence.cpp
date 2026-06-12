class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), mn1 = INT_MAX, mn2 = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mn1) {
                mn1 = nums[i];
            } else if (nums[i] <= mn2) {
                mn2 = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};