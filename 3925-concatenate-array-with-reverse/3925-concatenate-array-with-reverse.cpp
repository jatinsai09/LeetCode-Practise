class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (auto &i: nums) {
            res.push_back(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            res.push_back(nums[i]);
        }

        return res;
    }
};