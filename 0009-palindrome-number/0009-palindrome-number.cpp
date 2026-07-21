class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int slow = x, fast = x;
        int rev = 0;
        while (fast >= 10) {
            rev = rev * 10 + slow % 10;
            slow /= 10;
            fast /= 100;
        }
        if (fast > 0) {
            slow /= 10;
        }

        return (slow == rev);
    }
};