class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> bi, tri;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bi.insert(nums[i] ^ nums[j]);
            }
        }

        for (const auto& i : nums) {
            for (const auto& x : bi) {
                tri.insert(i ^ x);
            }
        }

        return tri.size();
    }
};