class Solution {
private:
    void merge(vector<int>& nums, int l, int m, int r, int& rpc) {
        for (int i = l, j = m + 1; i <= m; i++) {
            while (j <= r && nums[i] > (long long)nums[j] * 2) {
                j++;
            }
            rpc += j - (m + 1);
        }

        vector<int> t(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                t[k++] = nums[i++];
            } else {
                t[k++] = nums[j++];
            }
        }

        while(i <= m) t[k++] = nums[i++];
        while(j <= r) t[k++] = nums[j++];

        for (int i = l; i <= r; i++) {
            nums[i] = t[i - l];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r, int& rpc) {
        if (l >= r) {
            return;
        }

        int m = (l + r) >> 1;

        mergeSort(nums, l, m, rpc);
        mergeSort(nums, m + 1, r, rpc);

        merge(nums, l, m, r, rpc);
    }
public:
    int reversePairs(vector<int>& nums) {
        int rpc = 0;
        mergeSort(nums, 0, nums.size() - 1, rpc);
        return rpc;
    }
};