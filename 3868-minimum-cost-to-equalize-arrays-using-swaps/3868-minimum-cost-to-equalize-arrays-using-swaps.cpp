class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<int> f(1e5);
        for (auto &i: nums1) {
            f[i]++;
        } 
        for (auto &i: nums2) {
            f[i]--;
        }

        for (auto &i: nums1) {
            if (f[i] % 2) {
                return -1;
            }
        }

        for (auto &i: nums2) {
            if (f[i] & 1) {
                return -1;
            }
        }

        int res = 0;
        for (int i = 0; i < 1e5; i++) {
            if (f[i] > 0) {
                res += (f[i] >> 1);
            }
        }

        return res;
    }
};