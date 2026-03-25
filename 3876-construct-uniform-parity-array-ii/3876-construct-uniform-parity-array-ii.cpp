class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size(), pe = 0, po = 0;

        for (auto &i: nums1) {
            po += (i % 2);
        }
        pe = n - po;

        if (po == n || pe == n) {
            return true;
        }

        sort(begin(nums1), end(nums1));

        return nums1[0] % 2 == 1;
    }
};