class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), pos, res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }

        bool inc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                inc = false;
                break;
            }
        }
        if (inc) {
            res = min(pos, (n - pos) + 2);
        }

        bool dec = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos - i + n) % n] != i) {
                dec = false;
                break;
            }
        }
        if (dec) {
            res = min({res, pos + 2, (n - pos)});
        }

        return (res == INT_MAX ? -1 : res);
    }
};