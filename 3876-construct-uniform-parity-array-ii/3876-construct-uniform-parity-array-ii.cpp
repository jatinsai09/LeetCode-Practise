class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mn = nums1[0], co = 0;
        for (const auto& i: nums1) {
            co += (i & 1);
            mn = min(mn, i);
        }

        return !co || co == n || mn % 2;
    }
};