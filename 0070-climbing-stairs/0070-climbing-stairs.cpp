class Solution {
public:
    int climbStairs(int n) {
        int cur = 1, prev2 = 1, prev = 1, count = 1;
        while (count < n) {
            cur = prev2 + prev;
            prev2 = prev;
            prev = cur;
            count++;
        }
        return cur;
    }
};