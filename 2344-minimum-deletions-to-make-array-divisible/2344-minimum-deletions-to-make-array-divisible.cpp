class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(begin(nums), end(nums));
        
        int n = nums.size(), g = 0;
        for (const auto &i: numsDivide) {
            g = __gcd(i, g);
        }

        for (int i = 0; i < n; i++) {
            if (g % nums[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};