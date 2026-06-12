class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);

        sort(begin(nums), end(nums));

        int l = 0, r = nums.size() - 1, c = 0;
        while (l < r) {
            if (nums[l] + nums[r] == k) {
                c++;
                l++;
                r--;
            } else if (nums[l] + nums[r] > k) {
                r--;
            } else {
                l++;
            }
        }
        
        return c;
    }
};