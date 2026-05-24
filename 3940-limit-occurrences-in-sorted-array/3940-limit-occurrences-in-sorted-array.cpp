class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size(), c = 1;
        vector<int> res = {nums[0]};

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                c++;
            } else {
                c = 1;
            }

            if (c <= k) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};