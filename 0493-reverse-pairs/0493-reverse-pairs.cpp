class Solution {
private:
    int merge(vector<int>& nums, int l, int m, int r) {
        int rpc = 0;
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

        return rpc;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int m = (l + r) >> 1, res = 0;

        res += mergeSort(nums, l, m);
        res += mergeSort(nums, m + 1, r);

        res += merge(nums, l, m, r);

        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};