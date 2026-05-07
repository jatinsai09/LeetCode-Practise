class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> smn(n), pmx(n), res(n);
        smn[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            smn[i] = min(smn[i + 1], nums[i]);
        }
        pmx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pmx[i] = max(pmx[i - 1], nums[i]);
        }

        res[n - 1] = pmx[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            res[i] = pmx[i];
            if (pmx[i] > smn[i + 1]) {
                res[i] = res[i + 1];
            }
        }
        return res;
    }
};