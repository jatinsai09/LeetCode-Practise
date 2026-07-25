class Solution {
#define ll long long int
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll n = nums.size(), ps = 0, ss = 0;
        for (const auto& i: nums) {
            ss += i;
        }

        ll mn = INT_MAX, ind = 0;
        for (int i = 0; i < n; i++) {
            ps += nums[i];
            ss -= nums[i];

            int avg1 = 0, avg2 = 0;
            if (ps) {
                avg1 = ps / (i + 1);
            }
            if (ss) {
                avg2 = ss / (n - i - 1);
            } 
            ll got = abs(avg1 - avg2);

            if (got < mn) {
                mn = got;
                ind = i;
            }
        }

        return ind;
    }
};