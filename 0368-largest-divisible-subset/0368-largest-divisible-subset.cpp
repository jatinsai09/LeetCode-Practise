class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie();

        int n = nums.size();
        sort(rbegin(nums), rend(nums));

        int maxi = 1, lastind = 0;
        vector<int> dp(n, 1), hash(n);

        for (int i = 1; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] % nums[i] == 0 && dp[prev] + 1 >= dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] >= maxi) {
                maxi = dp[i];
                lastind = i;
            }
        }


        vector<int> res;
        res.push_back(nums[lastind]);
        while (lastind != hash[lastind]) {
            lastind = hash[lastind];
            res.push_back(nums[lastind]);
        }
        
        return res;
    }
};