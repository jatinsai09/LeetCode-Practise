class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size(), c = 1;
        vector<int> res;

        for (int i = 1; i <= n; i++) {
            if (i < n && nums[i - 1] == nums[i]) {
                c++;
            } else {
                int f = min(k, c);
                while (f--) {
                    res.push_back(nums[i - 1]);
                }
                c = 1;
            }
        }
        return res;
    }
};