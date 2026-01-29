class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), mi = nums[0];

        for (int i = 0; i < n; i++) {
            if (mi >= n - 1) {
                return true;
            }

            if (nums[i] == 0 && mi == i) {
                return false;
            }

            mi = max(mi, i + nums[i]);
        }
        return true;
    }
};