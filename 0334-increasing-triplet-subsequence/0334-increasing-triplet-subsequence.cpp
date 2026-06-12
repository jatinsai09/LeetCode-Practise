class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        if (n < 3) {
            return false;
        }

        vector<int> max_right(n);
        max_right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = max(nums[i], max_right[i + 1]);
        }

        int min_left = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (min_left < nums[i] && nums[i] < max_right[i + 1]) {
                return true;
            }
            min_left = min(nums[i], min_left);
        }
        return false;
    }
};