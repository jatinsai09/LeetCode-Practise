class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        //cout << slow << "\n";

        slow = nums[0];
        while (slow != fast) {
            // cout << nums[slow] << " " << nums[fast] << "\n";
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};