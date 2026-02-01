class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(begin(nums), end(nums));

        for (int l = 0, r = 1; r < n; r++) {
            if (nums[r] > nums[l]) {
                res++;
                l++;
            }
        } 

        return res;
    }
};