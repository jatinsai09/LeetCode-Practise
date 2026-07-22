class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        for (int i = 0; i < m; i++) {
            nums1[i + n] = nums2[i];
        }

        int gap = (n + m + 1) / 2;
        while (gap) { 
            int i = 0, j = gap;

            while (j < n + m) {
                if (nums1[i] > nums1[j]) {
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap + 1) / 2;
        }
    }
};