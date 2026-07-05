class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size(), c = 0;
        for (auto &i: nums) {
            c += (i == nums[n / 2]);
        }

        return c < 2;
    }
};