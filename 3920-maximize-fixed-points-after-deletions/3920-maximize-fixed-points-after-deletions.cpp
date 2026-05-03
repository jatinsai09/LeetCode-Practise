class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;

        for (int i = 0; i < n; i++) {
            int d = i - nums[i];
            if (d >= 0) {
                v.push_back({d, nums[i]});
            }
        }
        sort(begin(v), end(v));

        vector<int> lis;
        for (auto &p: v) {
            int el = p[1];
            auto it = lower_bound(begin(lis), end(lis), el);
            if (it == lis.end()) {
                lis.push_back(el);
            } else {
                *it = el;
            }
        }

        return lis.size();
    }
};