class Solution {
#define ll long long int
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        ll n = nums.size(), res = 0, req = 0;

        deque<int> nge;
        for (int l = n - 1, r = n - 1; l >= 0; l--) {
            int a = nums[l];

            while (!nge.empty() && nums[nge.front()] <= a) {
                int i = nge.front();
                nge.pop_front();

                int j = (nge.empty() ? r + 1 : nge.front());

                req += 1LL * (a - nums[i]) * (j - i);
            }
            nge.push_front(l);

            while (req > k) {
                if (nge.back() == r) {
                    nge.pop_back();
                } else {
                    req -= nums[nge.back()] - nums[r];
                }
                r--;
            }
            
            res += r - l + 1;
        }
        return res;
    }
};