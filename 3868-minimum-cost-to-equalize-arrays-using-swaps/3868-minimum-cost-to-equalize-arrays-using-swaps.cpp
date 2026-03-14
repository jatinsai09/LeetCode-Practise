class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<int> f1(1e5), f2(1e5);
        for (auto &i: nums1) {
            f1[i]++;
        } 
        for (auto &i: nums2) {
            f2[i]++;
        }

        for (auto &i: nums1) {
            if ((f1[i] + f2[i]) % 2) {
                return -1;
            }
        }

        for (auto &i: nums2) {
            if ((f1[i] + f2[i]) % 2) {
                return -1;
            }
        }

        int c1 = 0, c2 = 0;
        for (int i = 0; i < 1e5; i++) {
            if (f1[i] > f2[i]) {
                c1 += (f1[i] - f2[i]) / 2;
            } else {
                c2 += (f2[i] - f1[i]) / 2;
            }
        }

        return c1 + c2 - min(c1, c2);
    }
};