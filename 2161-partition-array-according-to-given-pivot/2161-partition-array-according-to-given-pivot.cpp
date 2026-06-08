class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l = 0, h = 0, g = 0, n = nums.size();

        for (auto &i : nums) {
            if (i < pivot) {
                ++l;
            } else if (i == pivot) {
                ++g;
            }
        }

        vector<int> res(n);
        h = l + g, g = l, l = 0;
        for (auto &i : nums) {
            if (i < pivot) {
                res[l++] = i;
            } else if (i > pivot) {
                res[h++] = i;
            } else {
                res[g++] = i;
            }
        }
        return res;
    }
};