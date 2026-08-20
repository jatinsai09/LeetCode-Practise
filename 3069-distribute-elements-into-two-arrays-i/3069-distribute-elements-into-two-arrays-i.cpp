class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> a[2] = {
            {nums[0]},
            {nums[1]}
        };

        for (int i = 2; i < n; i++) {
            if (a[0].back() > a[1].back()) {
                a[0].push_back(nums[i]);
            } else {
                a[1].push_back(nums[i]);
            }
        }
        a[0].insert(a[0].end(), a[1].begin(), a[1].end());

        return a[0];
    }
};