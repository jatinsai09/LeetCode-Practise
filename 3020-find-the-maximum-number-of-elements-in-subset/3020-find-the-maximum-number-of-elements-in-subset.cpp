class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size(), res = 1;
        unordered_map<long long, int> mp;

        for (auto &i: nums) {
            mp[i]++;
        }

        long long x;
        for (int i = 0; i < n; i++) {
            x = nums[i];
            if (mp[x] < 0) {
                continue;
            }
            if (x == 1) {
                res = max(res, mp[x] - (mp[x] % 2 == 0));
                mp[x] = -mp[x];
                continue;
            }

            int c = 1;
            while (mp[x * x] > 0) {
                if (mp[x] < 2) {
                    break;
                }
                mp[x] = -mp[x];
                x *= x;
                c += 2;
            }
            res = max(res, c);
        }

        return res;
    }
};