class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> allSubsets;
        vector<int> res;

        function<void(int, vector<int>)> f = [&](int i,
                                                 vector<int> res) -> void {
            if (i == n) {
                allSubsets.push_back(res);
                return;
            }

            // pick
            res.push_back(nums[i]);
            f(i + 1, res);

            // not pick
            res.pop_back();
            f(i + 1, res);
        };

        f(0, res);

        return allSubsets;
    }
};