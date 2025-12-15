class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> f;
        for (auto& i: nums) {
            f[i]++;
        }

        for (auto& i: nums) {
            if (f[i] > 1) {
                return true;
            }
        }

        return false;
    }
};