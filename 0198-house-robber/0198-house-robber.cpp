class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev2 = 0, prev = 0, cur;

        for (const auto& i: nums) {
            int pick = i + prev2, not_pick = prev;

            cur = max(pick, not_pick);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};