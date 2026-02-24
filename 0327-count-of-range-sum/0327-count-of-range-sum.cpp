class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> psum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }

        multiset<long long> s;
        long long res = 0;
        for (int i = n; i >= 0; --i) {
            long long low = psum[i] + lower;
            long long high = psum[i] + upper;

            auto itLow = s.lower_bound(low);
            auto itHigh = s.upper_bound(high);

            res += distance(itLow, itHigh);

            s.insert(psum[i]);
        }

        return res;
    }
};