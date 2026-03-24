class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN, p1 = 1, p2 = 1;
        
        for (int i = 0; i < n; i++) {
            p1 *= nums[i];
            p2 *= nums[n - 1 - i];

            res = max({res, p1, p2});
            if (!p1)
                p1 = 1;
            if (!p2)
                p2 = 1;
        }
        return res;
    }
};