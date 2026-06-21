class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size(), res = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int last = sum % 10, first = last;
                long long t = sum;

                if (last != x) {
                    continue;
                }

                while (t) {
                    first = t % 10;
                    t /= 10; 
                }

                if (first == x && last == x) {
                    res++;
                }
            }
        }

        return res;
    }
};