class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev2 = 0, prev = nums[0], cur = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2, not_pick = prev;

            cur = max(pick, not_pick);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};