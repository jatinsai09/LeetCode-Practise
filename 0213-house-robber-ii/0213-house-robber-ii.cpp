class Solution {
public:
    int MaxNonAdjSum(vector<int>& nums) {
        int prev2 = 0, prev = nums[0], cur = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int pick = nums[i] + prev2, notpick = prev;

            cur = max(pick, notpick);

            prev2 = prev;
            prev = cur;
        }

        return cur;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> v1, v2;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                v1.push_back(nums[i]);
            }
            if (i != n - 1) {
                v2.push_back(nums[i]);
            }
        }

        return max(MaxNonAdjSum(v1), MaxNonAdjSum(v2));
    }
};