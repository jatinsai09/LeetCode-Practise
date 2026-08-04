class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        sort(begin(nums), end(nums));

        for (int i = 1; i < n; i++) {
            for  (int j = nums[i - 1] + 1; j < nums[i]; j++) {
                res.push_back(j);
            }
        }
        return res;
    }
};