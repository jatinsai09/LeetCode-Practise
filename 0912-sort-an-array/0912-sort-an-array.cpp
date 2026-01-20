class Solution {
public:
    void quick_sort(auto& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int pivot = nums[l + rand() % (r - l + 1)], i = l, j = r;
        while (i <= j) {
            while (nums[i] < pivot) {
                i++;
            }
            while (nums[j] > pivot) {
                j--;
            }
            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        quick_sort(nums, l, j);
        quick_sort(nums, i, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);

        return nums;
    }
};