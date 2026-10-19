class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size(), cs = 0, cg = 0;
        for (auto &i: nums) {
            cs += (i < target);
            cg += (i > target);
        }

        int f = n - (cs + cg);
        vector<int> res;
        for (int i = 0; i < f; i++) {
            res.push_back(cs + i);
        }

        return res;
    }
};