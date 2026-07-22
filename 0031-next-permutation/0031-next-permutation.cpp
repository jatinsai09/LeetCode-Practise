class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());

        int n = nums.size(), ind = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            int i = 0, j= n - 1;
            while (i < j) {
                swap(nums[i++], nums[j--]);
            }
            return;
        }

        for (int i = nums.size() - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        
        int i = ind + 1, j = n - 1;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};