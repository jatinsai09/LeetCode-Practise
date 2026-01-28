class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> allSubsets;
        vector<int> res;

        function<void(int)> f = [&](int i) -> void {
            if (i == n) {
                allSubsets.push_back(res);
                return;
            }

            // pick
            res.push_back(nums[i]);
            f(i + 1);

            // not pick
            res.pop_back();
            f(i + 1);
        };

        f(0);
        return allSubsets;
    }
};