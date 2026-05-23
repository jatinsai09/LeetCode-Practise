class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;

        vector<int> oc(k), ec(k);
        for (int r = 0; r < k; r++) {
            for (int i = 0; i < n; i++) {
                int rem = nums[i] % k;
                int del = abs(r - rem);

                if (i & 1) {
                    oc[r] += min(del, k - del); 
                } else {
                    ec[r] += min(del, k - del);
                }
            }
        }

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) {
                    continue;
                }
                res = min(res, ec[x] + oc[y]);
            }
        }
        
        return res;
    }
};