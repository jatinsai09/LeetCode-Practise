class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), total = 0;
        for(const auto &i:nums){
            total += i;
        }

        if (x > total) {
            return -1;
        }

        int res = -1, cur = 0, req = total - x;
        for(int l = 0, r = 0; r < n; r++) {
            cur += nums[r];

            while(cur > req) {
                cur -= nums[l++];
            }

            if(cur == req) {
                res = max(res, r - l + 1);
            }
        }
        return (res == -1 ? -1 : n - res);
    }
};