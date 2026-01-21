class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size(), len = 1;
        vector<int> v;
        v.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (v.back() < nums[i]) {
                v.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[ind] = nums[i];
            }
        }
        return len;
    }
};