

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());

        int n = nums.size(), l = 0, r = nums[n - 1] - nums[0];
        while (l <= r) {
            int mid = (l + r) / 2, cnt = 0;

            for (int i = 0, j = 0; j < n; j++) {
                while (nums[j] - nums[i] > mid) {
                    i++;
                }
                cnt += j - i;
            }

            if (cnt < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};