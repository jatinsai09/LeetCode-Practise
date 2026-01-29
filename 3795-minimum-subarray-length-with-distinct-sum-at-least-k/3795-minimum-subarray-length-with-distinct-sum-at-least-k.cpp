class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> f;
        
        long long s = 0, res = n + 1;
        for (long long l = 0, r = 0; r < n; r++) {
            if (++f[nums[r]] == 1) {
                s += nums[r];
            }

            while (s >= k) {
                res = min(res, r - l + 1);
                if (--f[nums[l]] == 0) {
                    s -= nums[l];
                }
                l++;
            }
        }

        return (res == n + 1 ? -1 : res);
    }
};