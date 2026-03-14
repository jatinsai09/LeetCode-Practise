class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> f;
        for (auto &i: nums) {
            f[i]++;
        }

        for (auto &i: nums) {
            if (i % 2 == 0 && f[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};