class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> f;
        f[0] = 1;

        int p = 0;
        for (const auto& num: nums) {
            p += num;

            res += f[p - k];
            f[p]++;
        }

        return res;
    }
};