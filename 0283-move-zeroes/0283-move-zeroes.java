class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length, i = 0;

        // for (int num: nums) {
        //     if (num != 0) {
        //         nums[i++] = num;
        //     }
        // }

        // while (i < n) {
        //     nums[i++] = 0;
        // }

        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++;
            }
        }

    }
}