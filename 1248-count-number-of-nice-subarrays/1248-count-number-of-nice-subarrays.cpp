class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        v[0] = 1;

        int c = 0, res = 0;
        for (int i = 0; i < n; i++) {
            c += (nums[i] & 1);
            if (c >= k) {
                res += v[c - k];
            }
            v[c]++;
        }
        return res;
    }
};