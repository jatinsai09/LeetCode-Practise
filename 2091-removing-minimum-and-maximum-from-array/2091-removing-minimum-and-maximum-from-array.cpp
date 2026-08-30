class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mxi = 0, mni = 0;
        for (int i = 0; i < n; i++) {
            if (nums[mni] > nums[i]) {
                mni = i;
            }
            if (nums[mxi] < nums[i]) {
                mxi = i;
            }
        }

        int l = min(mni, mxi), r = max(mni, mxi);

        return min({r + 1, n - l, (l + 1) + (n - r)});
    }
};