class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> smx(n);
        
        for (int i = n - 2; i >= 0; i--) {
            smx[i] = max(nums[i + 1], smx[i + 1]);
        }

        vector<int> res;
        int pmx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > pmx || nums[i] > smx[i]) {
                res.push_back(nums[i]);
                pmx = max(pmx, nums[i]);
            }
        }

        return res;
    }
};