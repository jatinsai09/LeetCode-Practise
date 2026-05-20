class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& a, int s) {
        if (s < 0) {
            return 0;
        }
        int res = 0, n = a.size();
        for (int l = 0, r = 0; r < n; r++) {
            s -= a[r];
            while (s < 0) {
                s += a[l++];
            }
            res += r - l + 1;
        }
        return res;
    }
};