class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size(), idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int temp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = temp;

                idx++;
            }
        }
    }
};