class Solution {
public:
    void setofsubsets(int i, vector<int>& v, vector<int>& nums,
                      vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(v);
            return;
        }
        // not pick
        setofsubsets(i + 1, v, nums, res);
        // pick
        v.push_back(nums[i]);
        setofsubsets(i + 1, v, nums, res);
        // backtrack
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        setofsubsets(0, v, nums, res);
        return res;
    }
};